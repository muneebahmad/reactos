/* $Id$
 *
 * COPYRIGHT:       See COPYING in the top level directory
 * PROJECT:         ReactOS Display Control Panel
 * FILE:            lib/cpl/desk/screensaver.c
 * PURPOSE:         Screen saver property page
 * 
 * PROGRAMMERS:     Trevor McCort (lycan359@gmail.com)
 */

#include "desk.h"
void SetScreenSaver();

#define MAX_SCREENSAVERS 100

void AddListViewItems2();
void CheckRegScreenSaverIsSecure();

typedef struct {
    BOOL  bIsScreenSaver; /* Is this background a wallpaper */
    TCHAR szFilename[MAX_PATH];
    TCHAR szDisplayName[256];
} ScreenSaverItem;

int ImageListSelection       = 0;
ScreenSaverItem g_ScreenSaverItems[MAX_SCREENSAVERS];

HWND g_hScreenBackgroundPage = NULL;
HWND g_hScreengroundList = NULL;
HWND ControlScreenSaverIsSecure = NULL;
HMENU g_hPopupMenu = NULL;

void ListViewItemAreChanged(int itemIndex)
{
    ScreenSaverItem *ScreenSaverItem = NULL;
    
    ImageListSelection = itemIndex;
    ScreenSaverItem = &g_ScreenSaverItems[ImageListSelection];
    
    PropSheet_Changed(GetParent(g_hScreenBackgroundPage), g_hScreenBackgroundPage);
}

void
ScreensaverConfig ()
{
    /*
       /p:<hwnd>  Run in preview 
       /s         Run normal
       /c:<hwnd>  Run configuration, hwnd is handle of calling window
       /a         Run change password

    */

    WCHAR szCmdline[2048];                                                
    STARTUPINFO si;
    PROCESS_INFORMATION pi;                        
    swprintf(szCmdline, L"%s /c",g_ScreenSaverItems[ImageListSelection].szFilename);

    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    ZeroMemory( &pi, sizeof(pi) );                         
   if(CreateProcess( NULL,  szCmdline, NULL, NULL, FALSE,  0,  NULL,NULL,&si, &pi )) 
   {                          
      CloseHandle( pi.hProcess );
      CloseHandle( pi.hThread );                       
   }                       
}

void
ScreensaverPreview ()
{
    /*
       /p:<hwnd>  Run in preview 
       /s         Run normal
       /c:<hwnd>  Run configuration, hwnd is handle of calling window
       /a         Run change password
    */

    WCHAR szCmdline[2048];                                                
    STARTUPINFO si;
    PROCESS_INFORMATION pi;                        
    swprintf(szCmdline, L"%s /p",g_ScreenSaverItems[ImageListSelection].szFilename);

    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    ZeroMemory( &pi, sizeof(pi) );                         
   if(CreateProcess( NULL,  szCmdline, NULL, NULL, FALSE,  0,  NULL,NULL,&si, &pi )) 
   {                          
      CloseHandle( pi.hProcess );
      CloseHandle( pi.hThread );                       
   }                       
 }

INT_PTR
CALLBACK
ScreenSaverPageProc(HWND hwndDlg,
                    UINT uMsg,
                    WPARAM wParam,
                    LPARAM lParam)
{
    g_hScreenBackgroundPage = hwndDlg;
    
    switch(uMsg) {
        case WM_DESTROY:
        {
            DestroyMenu(g_hPopupMenu);
            break;
        }
        case WM_INITDIALOG:
        {
            g_hScreengroundList = GetDlgItem(g_hScreenBackgroundPage, IDC_SCREENS_CHOICES);
            SendMessage(GetDlgItem(g_hScreenBackgroundPage, IDC_SCREENS_TIME), UDM_SETRANGE, 0, MAKELONG ((short) 240, (short) 0));
            AddListViewItems2();

            g_hPopupMenu = LoadMenu(hApplet, MAKEINTRESOURCE(IDR_POPUP_MENU));
            g_hPopupMenu = GetSubMenu(g_hPopupMenu, 0);

            CheckRegScreenSaverIsSecure();
        } break;

        case WM_COMMAND:
        {
            DWORD controlId = LOWORD(wParam);
            DWORD command   = HIWORD(wParam);
 
            switch(controlId) {
                case IDC_SCREENS_POWER_BUTTON: // Start Powercfg.Cpl
                {
                    if(command == BN_CLICKED)
                        WinExec("rundll32 shell32.dll,Control_RunDLL powercfg.cpl,,",SW_SHOWNORMAL);
                } break;
                case IDC_SCREENS_TESTSC: // Screensaver Preview
                {
                    if(command == BN_CLICKED)
                        ScreensaverPreview();   
                    break;
                } 
                case ID_MENU_PREVIEW:
                {
                    ScreensaverPreview();
                    break;
                }
                case ID_MENU_CONFIG:
                {
                    ScreensaverConfig();
                    break;
                }
                case ID_MENU_DELETE: // Delete Screensaver
                {
                    LPSHFILEOPSTRUCT fos = NULL;

                    if(command == BN_CLICKED) {
                        if (ImageListSelection == 0) // Can NOT delete anything :-)
                           return FALSE;

                        fos->hwnd = hwndDlg;
                        fos->wFunc = FO_DELETE;
                        fos->fFlags = 0;
                        fos->pFrom = g_ScreenSaverItems[ImageListSelection].szFilename;
                        SHFileOperationW(fos);
                    }
                } break; 
                case IDC_SCREENS_SETTINGS: // Screensaver Settings
                {
                    if(command == BN_CLICKED)
                        ScreensaverConfig();
                    break;
                }
                case IDC_SCREENS_USEPASSCHK: // Screensaver Is Secure
                {
                    if(command == BN_CLICKED)
                        MessageBox(NULL, TEXT("That button doesn't do anything yet"), TEXT("Whoops"), MB_OK);
                } break;
                case IDC_SCREENS_TIME: // Delay before show screensaver
                {
                } break;
                default:
                    break;
            } break;
        }
        case WM_NOTIFY:
        {
           LPNMHDR lpnm = (LPNMHDR)lParam;
           LPNMITEMACTIVATE nmia = (LPNMITEMACTIVATE) lParam;
           RECT rc;

           switch(lpnm->code) {   
             case PSN_APPLY:
             {
				 SetScreenSaver();
                return TRUE;
             } break;
             case NM_RCLICK:
             {
                GetWindowRect(g_hScreengroundList, &rc);
                TrackPopupMenuEx(g_hPopupMenu, TPM_RIGHTBUTTON,
                                 rc.left + nmia->ptAction.x, rc.top + nmia->ptAction.y, hwndDlg, NULL);
                break;
             }
             case LVN_ITEMCHANGED:
             {
                LPNMLISTVIEW nm = (LPNMLISTVIEW)lParam;
                if((nm->uNewState & LVIS_SELECTED) == 0)
                  return FALSE;
                ListViewItemAreChanged(nm->iItem);
                break;
             } break;
            default:
                break;
           }
        } break;
    }
    
    return FALSE;
}

void CheckRegScreenSaverIsSecure()
{
    HKEY hKey;
    TCHAR szBuffer[2];
    DWORD bufferSize = sizeof(szBuffer);
    DWORD varType = REG_SZ;
    LONG result;
    
    ControlScreenSaverIsSecure = GetDlgItem(g_hScreenBackgroundPage, IDC_SCREENS_USEPASSCHK);

    RegOpenKeyEx(HKEY_CURRENT_USER, TEXT("Control Panel\\Desktop"), 0, KEY_ALL_ACCESS, &hKey);
    result = RegQueryValueEx(hKey, TEXT("ScreenSaverIsSecure"), 0, &varType, (LPBYTE)szBuffer, &bufferSize);
    if(result == ERROR_SUCCESS)
        if(_ttoi(szBuffer) == 1) {
          SendMessage(ControlScreenSaverIsSecure, BM_SETCHECK, (WPARAM)BST_CHECKED, 0);
          goto End;
        }
    SendMessage(ControlScreenSaverIsSecure, BM_SETCHECK, (WPARAM)BST_UNCHECKED, 0);
End:
    RegCloseKey(hKey);
}

/* Add the bitmaps in the C:\ReactOS directory and the current wallpaper if any */
void AddListViewItems2()
{
    WIN32_FIND_DATA fd;
    HANDLE hFind;
    TCHAR szSearchPath[MAX_PATH];
    LV_ITEM listItem;
    LV_COLUMN dummy;
    RECT clientRect;
    //HKEY regKey;
    SHFILEINFO sfi;
    HIMAGELIST himl;
    HIMAGELIST g_hScreenShellImageList    = NULL;
    //TCHAR wallpaperFilename[MAX_PATH];
    //DWORD bufferSize = sizeof(wallpaperFilename);
    //DWORD varType = REG_SZ;
    //LONG result;
    UINT i = 0;
    int g_ScreenlistViewItemCount         = 0;
    ScreenSaverItem *ScreenSaverItem = NULL;
    
    GetClientRect(g_hScreengroundList, &clientRect);
    
    ZeroMemory(&dummy, sizeof(LV_COLUMN));
    dummy.mask      = LVCF_SUBITEM | LVCF_WIDTH;
    dummy.iSubItem  = 0;
    dummy.cx        = (clientRect.right - clientRect.left) - GetSystemMetrics(SM_CXVSCROLL);
    
    (void)ListView_InsertColumn(g_hScreengroundList, 0, &dummy);

    /* Add the "None" item */
    ScreenSaverItem = &g_ScreenSaverItems[g_ScreenlistViewItemCount];
    
    ScreenSaverItem->bIsScreenSaver = FALSE;

    LoadString(hApplet,
               IDS_NONE,
               ScreenSaverItem->szDisplayName,
               sizeof(ScreenSaverItem->szDisplayName) / sizeof(TCHAR));
    
    ZeroMemory(&listItem, sizeof(LV_ITEM));
    listItem.mask       = LVIF_TEXT | LVIF_PARAM | LVIF_STATE | LVIF_IMAGE;
    listItem.state      = LVIS_SELECTED;
    listItem.pszText    = ScreenSaverItem->szDisplayName;
    listItem.iImage     = -1;
    listItem.iItem      = g_ScreenlistViewItemCount;
    listItem.lParam     = g_ScreenlistViewItemCount;
    
    (void)ListView_InsertItem(g_hScreengroundList, &listItem);
    ListView_SetItemState(g_hScreengroundList, g_ScreenlistViewItemCount, LVIS_SELECTED, LVIS_SELECTED);

    g_ScreenlistViewItemCount++;

    /* Add current screensaver if any */
	/*
    RegOpenKeyEx(HKEY_CURRENT_USER, TEXT("Control Panel\\Desktop"), 0, KEY_ALL_ACCESS, &regKey);
    
    result = RegQueryValueEx(regKey, TEXT("SCRNSAVE.EXE"), 0, &varType, (LPBYTE)wallpaperFilename, &bufferSize);
    
    if((result == ERROR_SUCCESS) && (_tcslen(wallpaperFilename) > 0))
    {
        himl = (HIMAGELIST)SHGetFileInfo(wallpaperFilename,
                                         0,
                                         &sfi,
                                         sizeof(sfi),
                                         SHGFI_SYSICONINDEX | SHGFI_SMALLICON |
                                         SHGFI_DISPLAYNAME);

        if(himl != NULL)
        {
            if(i++ == 0)
            {
                g_hScreenShellImageList = himl;
                (void)ListView_SetImageList(g_hScreengroundList, himl, LVSIL_SMALL);
            }

            ScreenSaverItem = &g_ScreenSaverItems[g_ScreenlistViewItemCount];
            
            ScreenSaverItem->bIsScreenSaver = TRUE;

            _tcscpy(ScreenSaverItem->szDisplayName, sfi.szDisplayName);
            _tcscpy(ScreenSaverItem->szFilename, wallpaperFilename);

            ZeroMemory(&listItem, sizeof(LV_ITEM));
            listItem.mask       = LVIF_TEXT | LVIF_PARAM | LVIF_STATE | LVIF_IMAGE;
            listItem.state      = LVIS_SELECTED;
            listItem.pszText    = ScreenSaverItem->szDisplayName;
            listItem.iImage     = sfi.iIcon;
            listItem.iItem      = g_ScreenlistViewItemCount;
            listItem.lParam     = g_ScreenlistViewItemCount;

            (void)ListView_InsertItem(g_hScreengroundList, &listItem);
            ListView_SetItemState(g_hScreengroundList, g_ScreenlistViewItemCount, LVIS_SELECTED, LVIS_SELECTED);

            g_ScreenlistViewItemCount++;
        }
    } 	
	

    
    RegCloseKey(regKey);
	*/

    /* Add all the screensavers in the C:\ReactOS\System32 directory. */

    GetSystemDirectory(szSearchPath, MAX_PATH);
    _tcscat(szSearchPath, TEXT("\\*.scr"));
    
    hFind = FindFirstFile(szSearchPath, &fd);
    while(hFind != INVALID_HANDLE_VALUE)
    {
        /* Don't add any hidden screensavers */
        if((fd.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN) == 0)
        {
            TCHAR filename[MAX_PATH];
            
            GetSystemDirectory(filename, MAX_PATH);

            _tcscat(filename, TEXT("\\"));
            _tcscat(filename, fd.cFileName);
            
            himl = (HIMAGELIST)SHGetFileInfo(filename,
                                             0,
                                             &sfi,
                                             sizeof(sfi),
                                             SHGFI_SYSICONINDEX | SHGFI_SMALLICON |
                                             SHGFI_DISPLAYNAME);

            if(himl == NULL)
            {
                break;
            }
            
            if(i++ == 0)
            {
                g_hScreenShellImageList = himl;
                (void)ListView_SetImageList(g_hScreengroundList, himl, LVSIL_SMALL);
            }

            ScreenSaverItem = &g_ScreenSaverItems[g_ScreenlistViewItemCount];

            ScreenSaverItem->bIsScreenSaver = TRUE;
            
            _tcscpy(ScreenSaverItem->szDisplayName, sfi.szDisplayName);
            _tcscpy(ScreenSaverItem->szFilename, filename);

            ZeroMemory(&listItem, sizeof(LV_ITEM));
            listItem.mask       = LVIF_TEXT | LVIF_PARAM | LVIF_STATE | LVIF_IMAGE;
            listItem.pszText    = ScreenSaverItem->szDisplayName;
            listItem.state      = 0;
            listItem.iImage     = sfi.iIcon;
            listItem.iItem      = g_ScreenlistViewItemCount;
            listItem.lParam     = g_ScreenlistViewItemCount;
            
            (void)ListView_InsertItem(g_hScreengroundList, &listItem);
            
            g_ScreenlistViewItemCount++;
        }
        
        if(!FindNextFile(hFind, &fd))
            hFind = INVALID_HANDLE_VALUE;
    }
}

void SetScreenSaver()
{
    HKEY regKey;
    
    RegOpenKeyEx(HKEY_CURRENT_USER, TEXT("Control Panel\\Desktop"), 0, KEY_ALL_ACCESS, &regKey);
    RegSetValueEx(regKey, TEXT("SCRNSAVE.EXE"), 0, REG_SZ, (BYTE *)g_ScreenSaverItems[ImageListSelection].szFilename, _tcslen(g_ScreenSaverItems[ImageListSelection].szFilename)*sizeof(TCHAR));
   // RegSetValueEx(regKey, TEXT("SCRNSAVE.EXE"), 0, REG_SZ, g_ScreenSaverItems[ImageListSelection].szFilename, sizeof(TCHAR) * 2);        
   

	 RegCloseKey(regKey);
    
    //if(g_backgroundItems[g_backgroundSelection].bWallpaper == TRUE)
    //{
    //    SystemParametersInfo(SPI_SETDESKWALLPAPER,
    //                         0,
    //                         g_backgroundItems[g_backgroundSelection].szFilename,
    //                         SPIF_UPDATEINIFILE);
    //}
    //else
    //{   
    //    SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, TEXT(""), SPIF_UPDATEINIFILE);
    //}
}

