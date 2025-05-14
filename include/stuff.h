#ifndef __STUFF_H
#define __STUFF_H

#include <parser.h>

void errmsg(const char *format, ...);
const char*  token_type_to_str(yytoken_kind_t token_type);

#endif