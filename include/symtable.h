#ifndef __SYMTABLE_H
#define __SYMTABLE_H

#include <parser.h>

typedef struct sym_entry {
    char* token;
    yytoken_kind_t type;
    int lineno;
    struct sym_entry* next;
} sym_entry_t;

typedef struct sym_table {
    int count;
    sym_entry_t* head;
} sym_table_t;

void sym_table_init();
void sym_table_append(sym_entry_t* entry);
sym_entry_t* sym_table_find(const char* token);
void sym_table_remove(const char* token);
void sym_table_show();
void sym_table_free();

#endif