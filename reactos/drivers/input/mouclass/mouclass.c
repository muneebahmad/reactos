/* 
 * COPYRIGHT:       See COPYING in the top level directory
 * PROJECT:         ReactOS Mouse class driver
 * FILE:            drivers/mouclass/mouclass.c
 * PURPOSE:         Mouse class driver
 * 
 * PROGRAMMERS:     Herv� Poussineau (hpoussin@reactos.org)
 */

#define NDEBUG
#include <debug.h>

#define INITGUID
#include "mouclass.h"

static VOID NTAPI
DriverUnload(IN PDRIVER_OBJECT DriverObject)
{
	// nothing to do here yet
}

static NTSTATUS NTAPI
ClassCreate(
	IN PDEVICE_OBJECT DeviceObject,
	IN PIRP Irp)
{
	DPRINT("IRP_MJ_CREATE\n");

	if (!((PCOMMON_DEVICE_EXTENSION)DeviceObject->DeviceExtension)->IsClassDO)
		return ForwardIrpAndForget(DeviceObject, Irp);

	/* FIXME: open all associated Port devices */
	return STATUS_SUCCESS;
}

static NTSTATUS NTAPI
ClassClose(
	IN PDEVICE_OBJECT DeviceObject,
	IN PIRP Irp)
{
	DPRINT("IRP_MJ_CLOSE\n");

	if (!((PCOMMON_DEVICE_EXTENSION)DeviceObject->DeviceExtension)->IsClassDO)
		return ForwardIrpAndForget(DeviceObject, Irp);

	/* FIXME: close all associated Port devices */
	return STATUS_SUCCESS;
}

static NTSTATUS NTAPI
ClassCleanup(
	IN PDEVICE_OBJECT DeviceObject,
	IN PIRP Irp)
{
	DPRINT("IRP_MJ_CLEANUP\n");

	if (!((PCOMMON_DEVICE_EXTENSION)DeviceObject->DeviceExtension)->IsClassDO)
		return ForwardIrpAndForget(DeviceObject, Irp);

	/* FIXME: cleanup all associated Port devices */
	return STATUS_SUCCESS;
}

static NTSTATUS NTAPI
ClassRead(
	IN PDEVICE_OBJECT DeviceObject,
	IN PIRP Irp)
{
	DPRINT("IRP_MJ_READ\n");

	if (!((PCOMMON_DEVICE_EXTENSION)DeviceObject->DeviceExtension)->IsClassDO)
		return ForwardIrpAndForget(DeviceObject, Irp);

	if (IoGetCurrentIrpStackLocation(Irp)->Parameters.Read.Length < sizeof(MOUSE_INPUT_DATA))
	{
		Irp->IoStatus.Status = STATUS_BUFFER_TOO_SMALL;
		Irp->IoStatus.Information = 0;
		IoCompleteRequest(Irp, IO_NO_INCREMENT);

		return STATUS_BUFFER_TOO_SMALL;
	}

	IoMarkIrpPending(Irp);
	IoStartPacket(DeviceObject, Irp, NULL, NULL);
	return STATUS_PENDING;
}

static NTSTATUS NTAPI
ClassDeviceControl(
	IN PDEVICE_OBJECT DeviceObject,
	IN PIRP Irp)
{
	PCLASS_DEVICE_EXTENSION DeviceExtension;
	NTSTATUS Status;

	DPRINT("IRP_MJ_DEVICE_CONTROL\n");

	if (!((PCOMMON_DEVICE_EXTENSION)DeviceObject->DeviceExtension)->IsClassDO)
		return ForwardIrpAndForget(DeviceObject, Irp);

	DeviceExtension = (PCLASS_DEVICE_EXTENSION)DeviceObject->DeviceExtension;

	switch (IoGetCurrentIrpStackLocation(Irp)->Parameters.DeviceIoControl.IoControlCode)
	{
		case IOCTL_MOUSE_QUERY_ATTRIBUTES:
			/* FIXME */
			Status = STATUS_NOT_SUPPORTED;
			break;
		default:
			DPRINT1("IRP_MJ_DEVICE_CONTROL / unknown I/O control code 0x%lx\n",
				IoGetCurrentIrpStackLocation(Irp)->Parameters.DeviceIoControl.IoControlCode);
			Status = STATUS_NOT_SUPPORTED;
	}

	Irp->IoStatus.Status = Status;
	Irp->IoStatus.Information = 0;
	IoCompleteRequest(Irp, IO_NO_INCREMENT);

	return Status;
}

static NTSTATUS NTAPI
IrpStub(
	IN PDEVICE_OBJECT DeviceObject,
	IN PIRP Irp)
{
	NTSTATUS Status = STATUS_NOT_SUPPORTED;

	if (!((PCOMMON_DEVICE_EXTENSION)DeviceObject->DeviceExtension)->IsClassDO)
	{
		/* Forward some IRPs to lower device */
		switch (IoGetCurrentIrpStackLocation(Irp)->MajorFunction)
		{
			case IRP_MJ_INTERNAL_DEVICE_CONTROL:
				return ForwardIrpAndForget(DeviceObject, Irp);
			default:
			{
				DPRINT1("Port DO stub for major function 0x%lx\n",
					IoGetCurrentIrpStackLocation(Irp)->MajorFunction);
				ASSERT(FALSE);
				Status = Irp->IoStatus.Status;
			}
		}
	}
	else
	{
		DPRINT1("Class DO stub for major function 0x%lx\n",
			IoGetCurrentIrpStackLocation(Irp)->MajorFunction);
		ASSERT(FALSE);
		Status = Irp->IoStatus.Status;
	}

	Irp->IoStatus.Status = Status;
	IoCompleteRequest(Irp, IO_NO_INCREMENT);
	return Status;
}

static NTSTATUS
ReadRegistryEntries(
	IN PUNICODE_STRING RegistryPath,
	IN PCLASS_DRIVER_EXTENSION DriverExtension)
{
	UNICODE_STRING ParametersRegistryKey;
	RTL_QUERY_REGISTRY_TABLE Parameters[4];
	NTSTATUS Status;

	ULONG DefaultConnectMultiplePorts = 1;
	ULONG DefaultDataQueueSize = 0x64;
	UNICODE_STRING DefaultDeviceBaseName = RTL_CONSTANT_STRING(L"PointerClass");

	ParametersRegistryKey.Length = 0;
	ParametersRegistryKey.MaximumLength = RegistryPath->Length + sizeof(L"\\Parameters") + sizeof(UNICODE_NULL);
	ParametersRegistryKey.Buffer = ExAllocatePool(PagedPool, ParametersRegistryKey.MaximumLength);
	if (!ParametersRegistryKey.Buffer)
	{
		DPRINT("ExAllocatePool() failed\n");
		return STATUS_INSUFFICIENT_RESOURCES;
	}
	RtlCopyUnicodeString(&ParametersRegistryKey, RegistryPath);
	RtlAppendUnicodeToString(&ParametersRegistryKey, L"\\Parameters");
	ParametersRegistryKey.Buffer[ParametersRegistryKey.Length / sizeof(WCHAR)] = UNICODE_NULL;

	RtlZeroMemory(Parameters, sizeof(Parameters));

	Parameters[0].Flags = RTL_QUERY_REGISTRY_DIRECT | RTL_REGISTRY_OPTIONAL;
	Parameters[0].Name = L"ConnectMultiplePorts";
	Parameters[0].EntryContext = &DriverExtension->ConnectMultiplePorts;
	Parameters[0].DefaultType = REG_DWORD;
	Parameters[0].DefaultData = &DefaultConnectMultiplePorts;
	Parameters[0].DefaultLength = sizeof(ULONG);

	Parameters[1].Flags = RTL_QUERY_REGISTRY_DIRECT | RTL_REGISTRY_OPTIONAL;
	Parameters[1].Name = L"MouseDataQueueSize";
	Parameters[1].EntryContext = &DriverExtension->DataQueueSize;
	Parameters[1].DefaultType = REG_DWORD;
	Parameters[1].DefaultData = &DefaultDataQueueSize;
	Parameters[1].DefaultLength = sizeof(ULONG);

	Parameters[2].Flags = RTL_QUERY_REGISTRY_DIRECT | RTL_REGISTRY_OPTIONAL;
	Parameters[2].Name = L"PointerDeviceBaseName";
	Parameters[2].EntryContext = &DriverExtension->DeviceBaseName;
	Parameters[2].DefaultType = REG_SZ;
	Parameters[2].DefaultData = &DefaultDeviceBaseName;
	Parameters[2].DefaultLength = sizeof(ULONG);

	Status = RtlQueryRegistryValues(
		RTL_REGISTRY_ABSOLUTE,
		ParametersRegistryKey.Buffer,
		Parameters,
		NULL,
		NULL);

	if (NT_SUCCESS(Status))
	{
		/* Check values */
		if (DriverExtension->ConnectMultiplePorts != 0
			&& DriverExtension->ConnectMultiplePorts != 1)
		{
			DriverExtension->ConnectMultiplePorts = DefaultConnectMultiplePorts;
		}
		if (DriverExtension->DataQueueSize == 0)
		{
			DriverExtension->DataQueueSize = DefaultDataQueueSize;
		}
	}
	else if (Status == STATUS_OBJECT_NAME_NOT_FOUND)
	{
		/* Registry path doesn't exist. Set defaults */
		DriverExtension->ConnectMultiplePorts = DefaultConnectMultiplePorts;
		DriverExtension->DataQueueSize = DefaultDataQueueSize;
		Status = RtlDuplicateUnicodeString(
			RTL_DUPLICATE_UNICODE_STRING_NULL_TERMINATE,
			&DefaultDeviceBaseName,
			&DriverExtension->DeviceBaseName);
	}

	return Status;
}

static NTSTATUS
CreateClassDeviceObject(
	IN PDRIVER_OBJECT DriverObject,
	OUT PDEVICE_OBJECT *ClassDO OPTIONAL)
{
	PCLASS_DRIVER_EXTENSION DriverExtension;
	ULONG DeviceId = 0;
	ULONG PrefixLength;
	UNICODE_STRING DeviceNameU;
	PWSTR DeviceIdW = NULL; /* Pointer into DeviceNameU.Buffer */
	PDEVICE_OBJECT Fdo;
	PCLASS_DEVICE_EXTENSION DeviceExtension;
	NTSTATUS Status;

	DPRINT("CreateClassDeviceObject(0x%p)\n", DriverObject);

	/* Create new device object */
	DriverExtension = IoGetDriverObjectExtension(DriverObject, DriverObject);
	DeviceNameU.Length = 0;
	DeviceNameU.MaximumLength =
		wcslen(L"\\Device\\") * sizeof(WCHAR)    /* "\Device\" */
		+ DriverExtension->DeviceBaseName.Length /* "PointerClass" */
		+ 4 * sizeof(WCHAR)                      /* Id between 0 and 9999 */
		+ sizeof(UNICODE_NULL);                  /* Final NULL char */
	DeviceNameU.Buffer = ExAllocatePool(PagedPool, DeviceNameU.MaximumLength);
	if (!DeviceNameU.Buffer)
	{
		DPRINT("ExAllocatePool() failed\n");
		return STATUS_INSUFFICIENT_RESOURCES;
	}
	Status = RtlAppendUnicodeToString(&DeviceNameU, L"\\Device\\");
	if (!NT_SUCCESS(Status))
	{
		DPRINT("RtlAppendUnicodeToString() failed with status 0x%08lx\n", Status);
		goto cleanup;
	}
	Status = RtlAppendUnicodeStringToString(&DeviceNameU, &DriverExtension->DeviceBaseName);
	if (!NT_SUCCESS(Status))
	{
		DPRINT("RtlAppendUnicodeStringToString() failed with status 0x%08lx\n", Status);
		goto cleanup;
	}
	PrefixLength = DeviceNameU.MaximumLength - 4 * sizeof(WCHAR) - sizeof(UNICODE_NULL);
	DeviceIdW = &DeviceNameU.Buffer[PrefixLength / sizeof(WCHAR)];
	while (DeviceId < 9999)
	{
		DeviceNameU.Length = PrefixLength + swprintf(DeviceIdW, L"%lu", DeviceId) * sizeof(WCHAR);
		Status = IoCreateDevice(
			DriverObject,
			sizeof(CLASS_DEVICE_EXTENSION),
			&DeviceNameU,
			FILE_DEVICE_MOUSE,
			FILE_DEVICE_SECURE_OPEN,
			TRUE,
			&Fdo);
		if (NT_SUCCESS(Status))
			goto cleanup;
		else if (Status != STATUS_OBJECT_NAME_COLLISION)
		{
			DPRINT("IoCreateDevice() failed with status 0x%08lx\n", Status);
			goto cleanup;
		}
		DeviceId++;
	}
	DPRINT("Too much devices starting with '\\Device\\%wZ'\n", &DriverExtension->DeviceBaseName);
	Status = STATUS_UNSUCCESSFUL;
cleanup:
	if (!NT_SUCCESS(Status))
	{
		ExFreePool(DeviceNameU.Buffer);
		return Status;
	}

	DeviceExtension = (PCLASS_DEVICE_EXTENSION)Fdo->DeviceExtension;
	RtlZeroMemory(DeviceExtension, sizeof(CLASS_DEVICE_EXTENSION));
	DeviceExtension->Common.IsClassDO = TRUE;
	DeviceExtension->DriverExtension = DriverExtension;
	KeInitializeSpinLock(&(DeviceExtension->SpinLock));
	DeviceExtension->ReadIsPending = FALSE;
	DeviceExtension->InputCount = 0;
	DeviceExtension->PortData = ExAllocatePool(NonPagedPool, DeviceExtension->DriverExtension->DataQueueSize * sizeof(MOUSE_INPUT_DATA));
	Fdo->Flags |= DO_POWER_PAGABLE;
	Fdo->Flags &= ~DO_DEVICE_INITIALIZING;

	/* FIXME: create registry entry in HKEY_LOCAL_MACHINE\HARDWARE\DEVICEMAP */

	ExFreePool(DeviceNameU.Buffer);

	if (ClassDO)
		*ClassDO = Fdo;

	return STATUS_SUCCESS;
}

static BOOLEAN
ClassCallback(
	IN PDEVICE_OBJECT ClassDeviceObject,
	IN OUT PMOUSE_INPUT_DATA DataStart,
	IN PMOUSE_INPUT_DATA DataEnd,
	IN OUT PULONG ConsumedCount)
{
	PCLASS_DEVICE_EXTENSION ClassDeviceExtension = ClassDeviceObject->DeviceExtension;
	PIRP Irp = NULL;
	KIRQL OldIrql;
	PIO_STACK_LOCATION Stack;
	ULONG InputCount = DataEnd - DataStart;
	ULONG ReadSize;

	ASSERT(ClassDeviceExtension->Common.IsClassDO);

	DPRINT("ClassCallback()\n");
	/* A filter driver might have consumed all the data already; I'm
	 * not sure if they are supposed to move the packets when they
	 * consume them though.
	 */
	if (ClassDeviceExtension->ReadIsPending == TRUE && InputCount)
	{
		Irp = ClassDeviceObject->CurrentIrp;
		ClassDeviceObject->CurrentIrp = NULL;
		Stack = IoGetCurrentIrpStackLocation(Irp);

		/* A read request is waiting for input, so go straight to it */
		/* FIXME: use SEH */
		RtlCopyMemory(
			Irp->MdlAddress ? MmGetSystemAddressForMdlSafe(Irp->MdlAddress, NormalPagePriority) : Irp->UserBuffer,
			DataStart,
			sizeof(MOUSE_INPUT_DATA));

		/* Go to next packet and complete this request with STATUS_SUCCESS */
		Irp->IoStatus.Status = STATUS_SUCCESS;
		Irp->IoStatus.Information = sizeof(MOUSE_INPUT_DATA);
		Stack->Parameters.Read.Length = sizeof(MOUSE_INPUT_DATA);

		ClassDeviceExtension->ReadIsPending = FALSE;

		/* Skip the packet we just sent away */
		DataStart++;
		(*ConsumedCount)++;
		InputCount--;
	}

	/* If we have data from the port driver and a higher service to send the data to */
	if (InputCount != 0)
	{
		KeAcquireSpinLock(&ClassDeviceExtension->SpinLock, &OldIrql);

		if (ClassDeviceExtension->InputCount + InputCount > ClassDeviceExtension->DriverExtension->DataQueueSize)
			ReadSize = ClassDeviceExtension->DriverExtension->DataQueueSize - ClassDeviceExtension->InputCount;
		else
			ReadSize = InputCount;

		/*
		 * FIXME: If we exceed the buffer, data gets thrown away.. better
		 * solution?
		*/

		/*
		 * Move the input data from the port data queue to our class data
		 * queue.
		 */
		RtlMoveMemory(
			ClassDeviceExtension->PortData,
			(PCHAR)DataStart,
			sizeof(MOUSE_INPUT_DATA) * ReadSize);

		/* Move the pointer and counter up */
		ClassDeviceExtension->PortData += ReadSize;
		ClassDeviceExtension->InputCount += ReadSize;

		KeReleaseSpinLock(&ClassDeviceExtension->SpinLock, OldIrql);
		(*ConsumedCount) += ReadSize;
	}
	else
	{
		DPRINT("ClassCallBack() entered, InputCount = %lu - DOING NOTHING\n", InputCount);
	}

	if (Irp != NULL)
	{
		IoStartNextPacket(ClassDeviceObject, FALSE);
		IoCompleteRequest(Irp, IO_MOUSE_INCREMENT);
	}

	DPRINT("Leaving ClassCallback()\n");
	return TRUE;
}

/* Send IOCTL_INTERNAL_*_CONNECT to port */
static NTSTATUS
ConnectPortDriver(
	IN PDEVICE_OBJECT PortDO,
	IN PDEVICE_OBJECT ClassDO)
{
	KEVENT Event;
	PIRP Irp;
	IO_STATUS_BLOCK IoStatus;
	CONNECT_DATA ConnectData;
	NTSTATUS Status;

	KeInitializeEvent(&Event, NotificationEvent, FALSE);

	ConnectData.ClassDeviceObject = ClassDO;
	ConnectData.ClassService      = ClassCallback;

	Irp = IoBuildDeviceIoControlRequest(IOCTL_INTERNAL_MOUSE_CONNECT,
		PortDO,
		&ConnectData, sizeof(CONNECT_DATA),
		NULL, 0,
		TRUE, &Event, &IoStatus);

	Status = IoCallDriver(PortDO, Irp);

	if (Status == STATUS_PENDING)
		KeWaitForSingleObject(&Event, Suspended, KernelMode, FALSE, NULL);
	else
		IoStatus.Status = Status;

	if (NT_SUCCESS(IoStatus.Status))
		ObReferenceObject(PortDO);

	return IoStatus.Status;
}

static NTSTATUS NTAPI
ClassAddDevice(
	IN PDRIVER_OBJECT DriverObject,
	IN PDEVICE_OBJECT Pdo)
{
	PCLASS_DRIVER_EXTENSION DriverExtension;
	PDEVICE_OBJECT Fdo;
	PPORT_DEVICE_EXTENSION DeviceExtension;
	NTSTATUS Status;

	DPRINT("ClassAddDevice called. Pdo = 0x%p\n", Pdo);

	DriverExtension = IoGetDriverObjectExtension(DriverObject, DriverObject);

	/* Create new device object */
	Status = IoCreateDevice(
		DriverObject,
		sizeof(PORT_DEVICE_EXTENSION),
		NULL,
		Pdo->DeviceType,
		FILE_DEVICE_SECURE_OPEN,
		TRUE,
		&Fdo);
	if (!NT_SUCCESS(Status))
	{
		DPRINT("IoCreateDevice() failed with status 0x%08lx\n", Status);
		return Status;
	}

	DeviceExtension = (PPORT_DEVICE_EXTENSION)Fdo->DeviceExtension;
	RtlZeroMemory(DeviceExtension, sizeof(CLASS_DEVICE_EXTENSION));
	DeviceExtension->Common.IsClassDO = FALSE;
	DeviceExtension->PnpState = dsStopped;
	Fdo->Flags |= DO_POWER_PAGABLE;
	Status = IoAttachDeviceToDeviceStackSafe(Fdo, Pdo, &DeviceExtension->LowerDevice);
	if (!NT_SUCCESS(Status))
	{
		DPRINT("IoAttachDeviceToDeviceStackSafe() failed with status 0x%08lx\n", Status);
		IoDeleteDevice(Fdo);
		return Status;
	}
	Fdo->Flags |= DO_BUFFERED_IO;

	if (DriverExtension->ConnectMultiplePorts)
		Status = ConnectPortDriver(Fdo, DriverExtension->MainClassDeviceObject);
	else
		Status = ConnectPortDriver(Fdo, Fdo);
	if (!NT_SUCCESS(Status))
	{
		DPRINT("ConnectPortDriver() failed with status 0x%08lx\n", Status);
		IoDetachDevice(DeviceExtension->LowerDevice);
		/* FIXME: why can't I cleanup without error? */
		//IoDeleteDevice(Fdo);
		return Status;
	}
	Fdo->Flags &= ~DO_DEVICE_INITIALIZING;

	/* Register interface */
	Status = IoRegisterDeviceInterface(
		Pdo,
		&GUID_DEVINTERFACE_MOUSE,
		NULL,
		&DeviceExtension->InterfaceName);
	if (!NT_SUCCESS(Status))
	{
		DPRINT("IoRegisterDeviceInterface() failed with status 0x%08lx\n", Status);
		return Status;
	}

	return STATUS_SUCCESS;
}

static VOID NTAPI
ClassStartIo(
	IN PDEVICE_OBJECT DeviceObject,
	IN PIRP Irp)
{
	PCLASS_DEVICE_EXTENSION DeviceExtension = DeviceObject->DeviceExtension;
	PIO_STACK_LOCATION Stack = IoGetCurrentIrpStackLocation(Irp);

	ASSERT(DeviceExtension->Common.IsClassDO);

	if (DeviceExtension->InputCount > 0)
	{
		KIRQL oldIrql;

		KeAcquireSpinLock(&DeviceExtension->SpinLock, &oldIrql);

		/* FIXME: use SEH */
		RtlCopyMemory(
			Irp->MdlAddress ? MmGetSystemAddressForMdlSafe(Irp->MdlAddress, NormalPagePriority) : Irp->UserBuffer,
			DeviceExtension->PortData - DeviceExtension->InputCount,
			sizeof(MOUSE_INPUT_DATA));

		if (DeviceExtension->InputCount > 1)
		{
			RtlMoveMemory(
				DeviceExtension->PortData - DeviceExtension->InputCount,
				DeviceExtension->PortData - DeviceExtension->InputCount + 1,
				(DeviceExtension->InputCount - 1) * sizeof(MOUSE_INPUT_DATA));
		}
		DeviceExtension->PortData--;
		DeviceExtension->InputCount--;
		DeviceExtension->ReadIsPending = FALSE;

		/* Go to next packet and complete this request with STATUS_SUCCESS */
		Irp->IoStatus.Status = STATUS_SUCCESS;
		Irp->IoStatus.Information = sizeof(MOUSE_INPUT_DATA);
		Stack->Parameters.Read.Length = sizeof(MOUSE_INPUT_DATA);
		IoCompleteRequest(Irp, IO_MOUSE_INCREMENT);

		IoStartNextPacket(DeviceObject, FALSE);
		KeReleaseSpinLock(&DeviceExtension->SpinLock, oldIrql);
	}
	else
	{
		DeviceExtension->ReadIsPending = TRUE;
	}
}

static NTSTATUS
SearchForLegacyDrivers(
	IN PDRIVER_OBJECT DriverObject,
	IN PCLASS_DRIVER_EXTENSION DriverExtension)
{
	UNICODE_STRING DeviceMapKeyU = RTL_CONSTANT_STRING(L"\\REGISTRY\\MACHINE\\HARDWARE\\DEVICEMAP");
	UNICODE_STRING PortBaseName = {0, };
	PKEY_VALUE_BASIC_INFORMATION KeyValueInformation = NULL;
	OBJECT_ATTRIBUTES ObjectAttributes;
	HANDLE hDeviceMapKey = (HANDLE)-1;
	HANDLE hPortKey = (HANDLE)-1;
	ULONG Index = 0;
	ULONG Size, ResultLength;
	NTSTATUS Status;

	/* Create port base name, by replacing Class by Port at the end of the class base name */
	Status = RtlDuplicateUnicodeString(
		RTL_DUPLICATE_UNICODE_STRING_NULL_TERMINATE,
		&DriverExtension->DeviceBaseName,
		&PortBaseName);
	if (!NT_SUCCESS(Status))
	{
		DPRINT("RtlDuplicateUnicodeString() failed with status 0x%08lx\n", Status);
		goto cleanup;
	}
	PortBaseName.Length -= (sizeof(L"Class") - sizeof(UNICODE_NULL));
	RtlAppendUnicodeToString(&PortBaseName, L"Port");

	/* Allocate memory */
	Size = sizeof(KEY_VALUE_BASIC_INFORMATION) + MAX_PATH;
	KeyValueInformation = ExAllocatePool(PagedPool, Size);
	if (!KeyValueInformation)
	{
		DPRINT("ExAllocatePool() failed\n");
		Status = STATUS_INSUFFICIENT_RESOURCES;
		goto cleanup;
	}

	/* Open HKEY_LOCAL_MACHINE\HARDWARE\DEVICEMAP */
	InitializeObjectAttributes(&ObjectAttributes, &DeviceMapKeyU, OBJ_KERNEL_HANDLE | OBJ_CASE_INSENSITIVE, NULL, NULL);
	Status = ZwOpenKey(&hDeviceMapKey, 0, &ObjectAttributes);
	if (Status == STATUS_OBJECT_NAME_NOT_FOUND)
	{
		DPRINT("HKLM\\HARDWARE\\DEVICEMAP is non-existent\n");
		Status = STATUS_SUCCESS;
		goto cleanup;
	}
	else if (!NT_SUCCESS(Status))
	{
		DPRINT("ZwOpenKey() failed with status 0x%08lx\n", Status);
		goto cleanup;
	}

	/* Open sub key */
	InitializeObjectAttributes(&ObjectAttributes, &PortBaseName, OBJ_KERNEL_HANDLE | OBJ_CASE_INSENSITIVE, hDeviceMapKey, NULL);
	Status = ZwOpenKey(&hPortKey, KEY_QUERY_VALUE, &ObjectAttributes);
	if (Status == STATUS_OBJECT_NAME_NOT_FOUND)
	{
		DPRINT("HKLM\\HARDWARE\\DEVICEMAP\\%wZ is non-existent\n", &PortBaseName);
		Status = STATUS_SUCCESS;
		goto cleanup;
	}
	else if (!NT_SUCCESS(Status))
	{
		DPRINT("ZwOpenKey() failed with status 0x%08lx\n", Status);
		goto cleanup;
	}

	/* Read each value name */
	while (ZwEnumerateValueKey(hPortKey, Index++, KeyValueBasicInformation, KeyValueInformation, Size, &ResultLength) == STATUS_SUCCESS)
	{
		UNICODE_STRING PortName;
		PDEVICE_OBJECT PortDeviceObject = NULL;
		PFILE_OBJECT FileObject = NULL;

		PortName.Length = PortName.MaximumLength = KeyValueInformation->NameLength;
		PortName.Buffer = KeyValueInformation->Name;

		/* Open the device object pointer */
		Status = IoGetDeviceObjectPointer(&PortName, FILE_READ_ATTRIBUTES, &FileObject, &PortDeviceObject);
		if (!NT_SUCCESS(Status))
		{
			DPRINT("IoGetDeviceObjectPointer(%wZ) failed with status 0x%08lx\n", Status);
		}

		/* Connect the port device object */
		if (DriverExtension->ConnectMultiplePorts)
		{
			Status = ConnectPortDriver(PortDeviceObject, DriverExtension->MainClassDeviceObject);
			if (!NT_SUCCESS(Status))
			{
				/* FIXME: Log the error */
				DPRINT("ConnectPortDriver() failed with status 0x%08lx\n", Status);
			}
		}
		else
		{
			PDEVICE_OBJECT ClassDO;
			Status = CreateClassDeviceObject(DriverObject, &ClassDO);
			if (!NT_SUCCESS(Status))
			{
				/* FIXME: Log the error */
				DPRINT("CreatePointerClassDeviceObject() failed with status 0x%08lx\n", Status);
				continue;
			}
			Status = ConnectPortDriver(PortDeviceObject, ClassDO);
			if (!NT_SUCCESS(Status))
			{
				/* FIXME: Log the error */
				DPRINT("ConnectPortDriver() failed with status 0x%08lx\n", Status);
				IoDeleteDevice(ClassDO);
			}
		}
	}
	if (Status == STATUS_NO_MORE_ENTRIES)
		Status = STATUS_SUCCESS;

cleanup:
	if (KeyValueInformation != NULL)
		ExFreePool(KeyValueInformation);
	if (hDeviceMapKey != (HANDLE)-1)
		ZwClose(hDeviceMapKey);
	if (hPortKey != (HANDLE)-1)
		ZwClose(hPortKey);
	return Status;
}

/*
 * Standard DriverEntry method.
 */
NTSTATUS NTAPI
DriverEntry(
	IN PDRIVER_OBJECT DriverObject,
	IN PUNICODE_STRING RegistryPath)
{
	PCLASS_DRIVER_EXTENSION DriverExtension;
	ULONG i;
	NTSTATUS Status;

	Status = IoAllocateDriverObjectExtension(
		DriverObject,
		DriverObject,
		sizeof(CLASS_DRIVER_EXTENSION),
		(PVOID*)&DriverExtension);
	if (!NT_SUCCESS(Status))
	{
		DPRINT("IoAllocateDriverObjectExtension() failed with status 0x%08lx\n", Status);
		return Status;
	}
	RtlZeroMemory(DriverExtension, sizeof(CLASS_DRIVER_EXTENSION));

	Status = ReadRegistryEntries(RegistryPath, DriverExtension);
	if (!NT_SUCCESS(Status))
	{
		DPRINT("ReadRegistryEntries() failed with status 0x%08lx\n", Status);
		return Status;
	}

	if (DriverExtension->ConnectMultiplePorts == 1)
	{
		Status = CreateClassDeviceObject(
			DriverObject,
			&DriverExtension->MainClassDeviceObject);
		if (!NT_SUCCESS(Status))
		{
			DPRINT("CreateClassDeviceObject() failed with status 0x%08lx\n", Status);
			return Status;
		}
	}

	DriverObject->DriverExtension->AddDevice = ClassAddDevice;
	DriverObject->DriverUnload = DriverUnload;

	for (i = 0; i < IRP_MJ_MAXIMUM_FUNCTION; i++)
		DriverObject->MajorFunction[i] = IrpStub;

	DriverObject->MajorFunction[IRP_MJ_CREATE]         = ClassCreate;
	DriverObject->MajorFunction[IRP_MJ_CLOSE]          = ClassClose;
	DriverObject->MajorFunction[IRP_MJ_CLEANUP]        = ClassCleanup;
	DriverObject->MajorFunction[IRP_MJ_READ]           = ClassRead;
	DriverObject->MajorFunction[IRP_MJ_DEVICE_CONTROL] = ClassDeviceControl;
	DriverObject->DriverStartIo                        = ClassStartIo;

	Status = SearchForLegacyDrivers(DriverObject, DriverExtension);

	return Status;
}
