#include <ast.h>
#include <stdlib.h>

ast_node_t *ast_create_string_node(const char *str) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstString;
  ast_string_t *expr = (ast_string_t *)malloc(sizeof(ast_string_t));
  expr->str = str;
  node->str = expr;
  return node;
}

ast_node_t *ast_create_int_node(int ival) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstInt;
  ast_int_t *expr = (ast_int_t *)malloc(sizeof(ast_int_t));
  expr->ival = ival;
  node->ival = expr;
  return node;
}

ast_node_t *ast_create_nil_node() {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstNil;
  return node;
}

ast_node_t *ast_create_binory_node(yytoken_kind_t op, ast_node_t *left,
                                   ast_node_t *right) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstBinory;
  ast_binory_expr_t *expr =
      (ast_binory_expr_t *)malloc(sizeof(ast_binory_expr_t));
  expr->left = left;
  expr->right = right;
  expr->op = op;
  node->binexpr = expr;
  return node;
}

ast_node_t *ast_create_unary_node(yytoken_kind_t op, ast_node_t *val) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstUnary;
  ast_unary_expr_t *expr = (ast_unary_expr_t *)malloc(sizeof(ast_unary_expr_t));
  expr->val = val;
  expr->op = op;
  node->unexpr = expr;
  return node;
}

ast_node_t *ast_create_assign_node(ast_node_t *var, ast_node_t *right) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstAssign;
  ast_assign_expr_t *assign =
      (ast_assign_expr_t *)malloc(sizeof(ast_assign_expr_t));
  assign->var = var;
  assign->expr = right;
  node->assexpr = assign;
  return node;
}

ast_node_t *ast_create_fncall_node(ast_node_t *fnname, ast_node_t *params) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstFncall;
  ast_fncall_t *fncall = (ast_fncall_t *)malloc(sizeof(ast_fncall_t));
  fncall->fnname = fnname;
  fncall->params = params;
  node->fncall = fncall;
  return node;
}

ast_node_t *ast_create_struct_node(ast_node_t *name, ast_node_t *fields) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstStruct;
  ast_struct_t *st = (ast_struct_t *)malloc(sizeof(ast_struct_t));
  st->name = name;
  st->fields = fields;
  node->st = st;
  return node;
}

ast_node_t *ast_create_ident_node(const char *name, scope_t *sc) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstIdent;
  ast_ident_t *ident = (ast_ident_t *)malloc(sizeof(ast_ident_t));
  ident->name = name;
  ident->sc = sc;
  node->ident = ident;
  return node;
}

ast_node_t *ast_create_arraydef_node(ast_node_t *type, ast_node_t *size,
                                     ast_node_t *initval) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstArrDef;
  ast_arraydef_t *arrdef = (ast_arraydef_t *)malloc(sizeof(ast_arraydef_t));
  arrdef->type = type;
  arrdef->size = size;
  arrdef->initval = initval;
  node->arraydef = arrdef;
  return node;
}

ast_node_t *ast_create_if_node(ast_node_t *cond, ast_node_t *thexpr,
                               ast_node_t *elexpr) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstIf;
  ast_if_t *ifexpr = (ast_if_t *)malloc(sizeof(ast_if_t));
  ifexpr->cond = cond;
  ifexpr->thexpr = thexpr;
  ifexpr->elexpr = elexpr;
  node->ifexpr = ifexpr;
  return node;
}

ast_node_t *ast_create_while_node(ast_node_t *cond, ast_node_t *do_expr) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstWhile;
  ast_while_t *whexpr = (ast_while_t *)malloc(sizeof(ast_while_t));
  whexpr->cond = cond;
  whexpr->do_expr = do_expr;
  node->whexpr = whexpr;
  return node;
}

ast_node_t *ast_create_for_node(ast_node_t *itor, ast_node_t *start,
                                ast_node_t *end, ast_node_t *expr) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstFor;
  ast_for_t *forexpr = (ast_for_t *)malloc(sizeof(ast_for_t));
  forexpr->itor = itor;
  forexpr->start = start;
  forexpr->end = end;
  forexpr->expr = expr;
  node->forexpr = forexpr;
  return node;
}

ast_node_t *ast_create_let_node(ast_node_t *declist, ast_node_t *exprseq) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstLet;
  ast_let_t *letexpr = (ast_let_t *)malloc(sizeof(ast_let_t));
  letexpr->declist = declist;
  letexpr->exprseq = exprseq;
  node->letexpr = letexpr;
  return node;
}