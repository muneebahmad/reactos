/* Copyright (C) 1994 DJ Delorie, see COPYING.DJ for details */
#include <ntdll.h>

/*
 * @implemented
 */
int
abs(int j)
{
  return j<0 ? -j : j;
}
