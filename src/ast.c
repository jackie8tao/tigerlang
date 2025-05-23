#include <ast.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stuff.h>
#include <tigerdef.h>

#define AST_LIST_SIZE 5

#define ast_stmt_init(node_type, grp_name, field_name)                         \
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));                 \
  node->type = node_type;                                                      \
  node->field_name.count = 0;                                                  \
  node->field_name.cap = AST_LIST_SIZE;                                        \
  ast_node_t **subs =                                                          \
      (ast_node_t **)malloc(AST_LIST_SIZE * sizeof(ast_node_t *));             \
  node->field_name.children = subs;                                            \
  return node;

#define ast_stmt_append(node_type, grp_name, field_name)                       \
  if (cur->type != node_type) {                                                \
    simple_msg("invalid node type");                                           \
    exit(ERR_ARGS);                                                            \
  }                                                                            \
  if (cur->field_name.count >= cur->field_name.cap) {                          \
    int cap = cur->field_name.cap + AST_LIST_SIZE;                             \
    ast_node_t **subs = (ast_node_t **)malloc(cap * sizeof(ast_node_t *));     \
    for (int i = 0; i < cur->field_name.count; i++) {                          \
      subs[i] = cur->field_name.children[i];                                   \
    }                                                                          \
    free(cur->field_name.children);                                            \
    cur->field_name.children = subs;                                           \
  }                                                                            \
  cur->field_name.children[cur->field_name.count] = src;                       \
  cur->field_name.count++;

ast_node_t *g_ast_root = NULL;

ast_node_t *ast_create_fieldlist() {
  ast_stmt_init(AstFieldList, grpstmt, fieldlist);
}

void ast_append_fieldlist(ast_node_t *cur, ast_node_t *src) {
  ast_stmt_append(AstFieldList, grpstmt, fieldlist);
}

ast_node_t *ast_create_exprlist() {
  ast_stmt_init(AstExprList, grpstmt, exprlist);
}

void ast_append_exprlist(ast_node_t *cur, ast_node_t *src) {
  ast_stmt_append(AstExprList, grpstmt, exprlist);
}

ast_node_t *ast_create_declist() {
  ast_stmt_init(AstDecList, declist, declist);
}

void ast_append_declist(ast_node_t *cur, ast_node_t *src) {
  ast_stmt_append(AstDecList, declist, declist);
}

static const char *ast_binop_str(yytoken_kind_t type) {
  const char *str;
  switch (type) {
  case TK_PLUS:
    str = "+";
    break;
  case TK_MINUS:
    str = "-";
    break;
  case TK_MULTI:
    str = "*";
    break;
  case TK_DIV:
    str = "/";
    break;
  case TK_GT:
    str = ">";
    break;
  case TK_GEQU:
    str = ">=";
    break;
  case TK_LT:
    str = "<";
    break;
  case TK_LEQU:
    str = "<=";
    break;
  case TK_AND:
    str = "&";
    break;
  case TK_OR:
    str = "|";
    break;
  case TK_EQU:
    str = "=";
    break;
  case TK_NEQU:
    str = "!=";
    break;
  default:
    str = "";
    break;
  }
  return str;
}

static char dumpbuf[128];

static char *ast_print_prefix(char *prefix) {
  memset(dumpbuf, '\0', 128);
  if (strlen(prefix) <= 0) {
    sprintf(dumpbuf, "|");
    return strdup(dumpbuf);
  }
  sprintf(dumpbuf, "%s   |", prefix);
  printf("%s---", dumpbuf);
  return strdup(dumpbuf);
}

static void ast_dump_node(ast_node_t *node, char *prefix) {
  if (!node) {
    return;
  }

  printf("\n");
  prefix = ast_print_prefix(prefix);
  switch (node->type) {
  case AstLet:
    printf("[let]");
    ast_dump_node(node->letexpr.declist, prefix);
    ast_dump_node(node->letexpr.exprseq, prefix);
    break;
  case AstDecList:
    printf("[declist]");
    for (int i = 0; i < node->declist.count; i++) {
      ast_dump_node(node->declist.children[i], prefix);
    }
    break;
  case AstString:
    printf("[string:'%s']", node->rvalue.sval);
    break;
  case AstIdent:
    printf("[ident:'%s']", node->ident.name);
    break;
  case AstStruct:
    printf("[struct]");
    ast_dump_node(node->strt.fields, prefix);
    break;
  case AstBinory:
    printf("[binoper:'%s']", ast_binop_str(node->binexpr.op));
    ast_dump_node(node->binexpr.left, prefix);
    ast_dump_node(node->binexpr.right, prefix);
    break;
  case AstAssign:
    printf("[assign]");
    ast_dump_node(node->assexpr.var, prefix);
    ast_dump_node(node->assexpr.expr, prefix);
    break;
  case AstUnary:
    printf("[unary:%d]", node->unexpr.op);
    ast_dump_node(node->unexpr.right, prefix);
    break;
  case AstInt:
    printf("[type:int]");
    break;
  case AstNil:
    printf("[type:nil]");
    break;
  case AstArrInit:
    printf("[arrinit]");
    ast_dump_node(node->arrinit.type, prefix);
    ast_dump_node(node->arrinit.size, prefix);
    ast_dump_node(node->arrinit.initval, prefix);
    break;
  case AstIf:
    printf("[if]");
    ast_dump_node(node->ifexpr.cond, prefix);
    ast_dump_node(node->ifexpr.thexpr, prefix);
    ast_dump_node(node->ifexpr.elexpr, prefix);
    break;
  case AstWhile:
    printf("[while]");
    ast_dump_node(node->whexpr.cond, prefix);
    ast_dump_node(node->whexpr.do_expr, prefix);
    break;
  case AstFor:
    printf("[for]");
    ast_dump_node(node->forexpr.itor, prefix);
    ast_dump_node(node->forexpr.start, prefix);
    ast_dump_node(node->forexpr.end, prefix);
    ast_dump_node(node->forexpr.expr, prefix);
    break;
  case AstExprList:
    printf("[exprlist]");
    for (int i = 0; i < node->exprlist.count; i++) {
      ast_dump_node(node->exprlist.children[i], prefix);
    }
    break;
  case AstExprSeq:
    printf("[exprseq]");
    for (int i = 0; i < node->exprseq.count; i++) {
      ast_dump_node(node->exprseq.children[i], prefix);
    }
    break;
  case AstFncall:
    printf("[fncall]");
    ast_dump_node(node->fncall.fnname, prefix);
    ast_dump_node(node->fncall.params, prefix);
    break;
  case AstFieldef:
    printf("[fieldef]");
    ast_dump_node(node->fieldef.ident, prefix);
    ast_dump_node(node->fieldef.expr, prefix);
    break;
  case AstFieldList:
    printf("[fieldlist]");
    for (int i = 0; i < node->fieldlist.count; i++) {
      ast_dump_node(node->fieldlist.children[i], prefix);
    }
    break;
  case AstIdentIndex:
    printf("[ident_index]");
    ast_dump_node(node->idxexpr.ident_index, prefix);
    if (node->idxexpr.next) {
      ast_dump_node(node->idxexpr.next, prefix);
    }
    break;
  case AstArrIndex:
    printf("[arr_index]");
    ast_dump_node(node->idxexpr.arr_index, prefix);
    if (node->idxexpr.next) {
      ast_dump_node(node->idxexpr.next, prefix);
    }
    break;
  case AstLvalue:
    printf("[lvalue]");
    ast_dump_node(node->lvalue.ident, prefix);
    ast_dump_node(node->lvalue.index, prefix);
    break;
  case AstIdentTypeDec:
    printf("[ident_type_dec]");
    ast_dump_node(node->typedec.typeid, prefix);
    ast_dump_node(node->typedec.typeval, prefix);
    break;
  case AstStTypeDec:
    printf("[st_type_dec]");
    ast_dump_node(node->typedec.typeid, prefix);
    ast_dump_node(node->typedec.typeval, prefix);
    break;
  case AstArrTypeDec:
    printf("[arr_type_dec]");
    ast_dump_node(node->typedec.typeid, prefix);
    ast_dump_node(node->typedec.typeval, prefix);
    break;
  case AstIdentTypeId:
    printf("[ident_typeid]");
    ast_dump_node(node->typeid.ident, prefix);
    break;
  case AstStrTypeId:
    printf("[str_typeid]");
    break;
  case AstIntTypeId:
    printf("[int_typeid]");
    break;
  case AstTypeFields:
    printf("[type_fields]");
    ast_dump_node(node->typefields.ident, prefix);
    ast_dump_node(node->typefields.typeid, prefix);
    if (node->typefields.next) {
      ast_dump_node(node->typefields.next, prefix);
    }
    break;
  case AstVarDec:
    printf("[vardec]");
    ast_dump_node(node->vardec.ident, prefix);
    ast_dump_node(node->vardec.typeid, prefix);
    ast_dump_node(node->vardec.expr, prefix);
    break;
  case AstFnDef:
    printf("[fndef]");
    ast_dump_node(node->fndef.fnname, prefix);
    ast_dump_node(node->fndef.params, prefix);
    ast_dump_node(node->fndef.rettype, prefix);
    ast_dump_node(node->fndef.fnbody, prefix);
    break;
  case AstBreak:
    printf("[break]");
    break;
  default:
    break;
  }
}

void ast_show_node(ast_node_t *node) { ast_dump_node(node, ""); }

ast_node_t *ast_get_root() { return g_ast_root; }

void ast_set_root(ast_node_t *root) { g_ast_root = root; }

ast_node_t *ast_create_string(char *str) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstString;
  node->rvalue.type = TK_STRING;
  node->rvalue.sval = str;
  return node;
}

ast_node_t *ast_create_int(int ival) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstInt;
  node->rvalue.type = TK_INTEGER;
  node->rvalue.ival = ival;
  return node;
}

ast_node_t *ast_create_nil() {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstNil;
  return node;
}

ast_node_t *ast_create_binory(yytoken_kind_t op, ast_node_t *left,
                              ast_node_t *right) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstBinory;
  node->binexpr.op = op;
  node->binexpr.left = left;
  node->binexpr.right = right;
  return node;
}

ast_node_t *ast_create_unary(yytoken_kind_t op, ast_node_t *val) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstUnary;
  node->unexpr.op = op;
  node->unexpr.right = val;
  return node;
}

ast_node_t *ast_create_assign(ast_node_t *var, ast_node_t *right) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstAssign;
  node->assexpr.var = var;
  node->assexpr.expr = right;
  return node;
}

ast_node_t *ast_create_fncall(ast_node_t *fnname, ast_node_t *params) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstFncall;
  node->fncall.fnname = fnname;
  node->fncall.params = params;
  return node;
}

ast_node_t *ast_create_struct(ast_node_t *name, ast_node_t *fields) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstStruct;
  node->strt.name = name;
  node->strt.fields = fields;
  return node;
}

ast_node_t *ast_create_ident(char *name, scope_t *sc, int lineno, int colno) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstIdent;
  node->ident.name = name;
  node->ident.sc = sc;
  symval_t *symval = symdict_create_symval(lineno, colno, name);
  scope_add_sym(sc, symval);
  return node;
}

ast_node_t *ast_create_arrinit(ast_node_t *type, ast_node_t *size,
                               ast_node_t *initval) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstArrInit;
  node->arrinit.type = type;
  node->arrinit.size = size;
  node->arrinit.initval = initval;
  return node;
}

ast_node_t *ast_create_if(ast_node_t *cond, ast_node_t *thexpr,
                          ast_node_t *elexpr) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstIf;
  node->ifexpr.cond = cond;
  node->ifexpr.elexpr = elexpr;
  node->ifexpr.thexpr = thexpr;
  return node;
}

ast_node_t *ast_create_while(ast_node_t *cond, ast_node_t *do_expr) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstWhile;
  node->whexpr.cond = cond;
  node->whexpr.do_expr = do_expr;
  return node;
}

ast_node_t *ast_create_for(ast_node_t *itor, ast_node_t *start, ast_node_t *end,
                           ast_node_t *expr) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstFor;
  node->forexpr.itor = itor;
  node->forexpr.start = start;
  node->forexpr.end = end;
  node->forexpr.expr = expr;
  return node;
}

ast_node_t *ast_create_let(ast_node_t *declist, ast_node_t *exprseq) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstLet;
  node->letexpr.declist = declist;
  node->letexpr.exprseq = exprseq;
  return node;
}

ast_node_t *ast_create_exprseq() {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstExprSeq;
  node->exprseq.count = 0;
  node->exprseq.cap = AST_LIST_SIZE;
  ast_node_t **subs =
      (ast_node_t **)malloc(AST_LIST_SIZE * sizeof(ast_node_t *));
  node->exprseq.children = subs;
  return node;
}

void ast_append_exprseq(ast_node_t *cur, ast_node_t *src) {
  if (cur->type != AstExprSeq) {
    simple_msg("invalid node type");
    exit(ERR_ARGS);
  }
  if (cur->exprseq.count >= cur->exprseq.cap) {
    int cap = cur->exprseq.cap + AST_LIST_SIZE;
    ast_node_t **subs = (ast_node_t **)malloc(cap * sizeof(ast_node_t *));
    for (int i = 0; i < cur->exprseq.count; i++) {
      subs[i] = cur->exprseq.children[i];
    }
    free(cur->exprseq.children);
    cur->exprseq.children = subs;
  }
  cur->exprseq.children[cur->exprseq.count] = src;
  cur->exprseq.count++;
}

ast_node_t *ast_create_fieldef(ast_node_t *ident, ast_node_t *expr) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstFieldef;
  node->fieldef.ident = ident;
  node->fieldef.expr = expr;
  return node;
}

ast_node_t *ast_create_ident_index(ast_node_t *ident) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstIdentIndex;
  node->idxexpr.ident_index = ident;
  return node;
}

ast_node_t *ast_create_arr_index(ast_node_t *ival) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstArrIndex;
  node->idxexpr.arr_index = ival;
  return node;
}

void ast_append_index(ast_node_t *cur, ast_node_t *next) {
  if (cur->type != AstArrIndex && cur->type != AstIdentIndex) {
    simple_msg("invalid node");
    exit(ERR_ARGS);
  }
  cur->idxexpr.next = next;
}

ast_node_t *ast_create_lvalue(ast_node_t *ident, ast_node_t *index) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstLvalue;
  node->lvalue.ident = ident;
  node->lvalue.index = index;
  return node;
}

ast_node_t *ast_create_ident_typeid(ast_node_t *ident) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstIdentTypeId;
  node->typeid.ident = ident;
  return node;
}

ast_node_t *ast_create_int_typeid() {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstIntTypeId;
  return node;
}

ast_node_t *ast_create_str_typeid() {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstStrTypeId;
  return node;
}

ast_node_t *ast_create_typefields(ast_node_t *ident, ast_node_t *typeid) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstTypeFields;
  node->typefields.ident = ident;
  node->typefields.typeid = typeid;
  return node;
}

void ast_append_typefields(ast_node_t *cur, ast_node_t *src) {
  if (cur->type != AstTypeFields) {
    simple_msg("invalid node type");
    exit(ERR_ARGS);
  }
  while (cur->typefields.next) {
    if (cur->type != AstTypeFields) {
      simple_msg("invalid node type");
      exit(ERR_ARGS);
    }
    cur = cur->typefields.next;
  }
  cur->typefields.next = src;
}

ast_node_t *ast_create_vardec(ast_node_t *ident, ast_node_t *typeid,
                              ast_node_t *expr) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstVarDec;
  node->vardec.ident = ident;
  node->vardec.typeid = typeid;
  node->vardec.expr = expr;
  return node;
}

ast_node_t *ast_create_typedec(ast_type type, ast_node_t *ident,
                               ast_node_t *typeval) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = type;
  node->typedec.typeid = ident;
  node->typedec.typeval = typeval;
  return node;
}

ast_node_t *ast_create_fndef(ast_node_t *fnname, ast_node_t *params,
                             ast_node_t *rettype, ast_node_t *fnbody) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstFnDef;
  node->fndef.fnname = fnname;
  node->fndef.params = params;
  node->fndef.rettype = rettype;
  node->fndef.fnbody = fnbody;
  return node;
}

ast_node_t *ast_create_break() {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstBreak;
  return node;
}