#include <tigerdef.h>
#include <stxtree.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <parser.h>
#include <stuff.h>

static stxtree_t *_stree = NULL;

void stxtree_init()
{
    if (!_stree)
        return;
    stxtree_t *_stree = (stxtree_t *)malloc(sizeof(stxtree_t));
    _stree->root = NULL;
    return;
}

// create binoper node along with two children node
stxnode_t *stxtree_create_binoper_node(yytoken_kind_t token_type)
{
    stxnode_t *node = (stxnode_t *)malloc(sizeof(stxnode_t));
    if (!node)
        goto memerr;

    node->token_type = token_type;
    stxnode_t *children = (stxnode_t *)malloc(2 * sizeof(stxnode_t*));
    if (!children)
        goto memerr;
    node->children = &children;
    node->count = 2;
    goto succ;

memerr:
    errmsg("invalid memory");
    exit(ERR_SYSTEM);
succ:
    return node;
}

void stxtree_show()
{
}