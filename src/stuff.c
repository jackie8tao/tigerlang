#include <stuff.h>
#include <stdarg.h>
#include <stdlib.h>
#include <err.h>
#include <stdio.h>

// print error message
void errmsg(const char *format, ...)
{
  char errmsg[128];
  va_list args;
  va_start(args, format);
  if (vsprintf(errmsg, format, args) < 0)
  {
    perror("cannot format error message");
    exit(ERR_SYSTEM);
  }
  va_end(args);

  perror(errmsg);
  return;
}