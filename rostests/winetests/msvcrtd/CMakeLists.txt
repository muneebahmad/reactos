
add_executable(msvcrtd_winetest debug.c testlist.c)
set_module_type(msvcrtd_winetest win32cui)
add_importlibs(msvcrtd_winetest msvcrt kernel32)
add_cd_file(TARGET msvcrtd_winetest DESTINATION reactos/bin FOR all)
