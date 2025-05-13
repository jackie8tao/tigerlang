#ifndef __STXTREE_H
#define __STXTREE_H

#include <parser.h>
#include <tigerdef.h>

typedef union token_val
{
    char *sym;  // symbol value
    int ival;   // integer value
    char *sval; // string value
} token_val_t;

typedef struct stxnode
{
    yytoken_kind_t token_type;
    token_val_t *token_val;
    int count; // children node count
    struct stxnode **children;
} stxnode_t;

typedef struct stxtree
{
    stxnode_t *root;
} stxtree_t;

void stxtree_init();
stxnode_t *stxtree_create_binoper_node(yytoken_kind_t token_type);
void stxtree_show();

#endif