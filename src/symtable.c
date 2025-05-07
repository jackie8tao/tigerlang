#include <symtable.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static sym_table_t *_symtable = NULL;

void sym_table_init()
{
    _symtable = (sym_table_t *)malloc(sizeof(sym_entry_t));
    if (!_symtable)
    {
        perror("cannot alloc memory");
        exit(-1);
    }
    _symtable->count = 0;
    _symtable->head = NULL;
    return;
}

void sym_table_append(sym_entry_t *entry)
{
    if (!_symtable || !_symtable->head)
    {
        _symtable->head = entry;
        _symtable->count++;
        return;
    }

    // forbid appending the same token;
    if (sym_table_find(entry->token))
        return;

    sym_entry_t *cur = _symtable->head;
    while (cur->next)
    {
        cur = cur->next;
    }
    cur->next = entry;
    _symtable->count++;
    return;
}

sym_entry_t *sym_table_find(const char *token)
{
    if (!_symtable || !_symtable->head)
        return NULL;
    sym_entry_t *cur = _symtable->head;
    while (cur)
    {
        if (strlen(cur->token) != strlen(token))
        {
            cur = cur->next;
            continue;
        }

        if (strcmp(token, cur->token) != 0)
        {
            cur = cur->next;
            continue;
        }

        break;
    }
    return cur;
}

void sym_table_remove(const char *token)
{
    if (!_symtable || !_symtable->head)
        return;

    sym_entry_t *before = NULL;
    sym_entry_t *cur = _symtable->head;
    while (cur)
    {
        if (strlen(cur->token) != strlen(token))
        {
            before = cur;
            continue;
        }
        if (strcmp(token, cur->token) != 0)
        {
            before = cur;
            continue;
        }

        break;
    }

    before->next = cur->next;
    _symtable->count--;
    free(cur);
    return;
}

void sym_table_show()
{
    if (!_symtable || !_symtable->head)
    {
        printf("empty symbol table");
        return;
    }

    printf("\n");

    sym_entry_t *cur = _symtable->head;
    int pos = 0;
    while (cur)
    {
        printf("position: %d, token: %s, type: %d\n",
               pos, cur->token, (int)cur->type);
        cur = cur->next;
        pos++;
    }

    return;
}

void sym_table_free()
{
    if (!_symtable || !_symtable->head)
    {
        free(_symtable);
        return;
    }

    sym_entry_t *cur = _symtable->head;
    sym_entry_t *tmp = NULL;
    while (cur)
    {
        tmp = cur->next;
        free(cur);
        cur = tmp;
    }
    return;
}