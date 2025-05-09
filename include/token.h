#ifndef __TOKEN_H
#define __TOKEN_H

// token definitions
typedef enum token
{
    YYEOF = 0,
    // start at 258
    TK_IDENT = 258, // identifier
    TK_INTEGER,     // integer
    TK_STRING,      // a sequence of characters

    TK_ARRAY, // array
    TK_NIL,   // nil

    TK_VAR,      // var
    TK_TYPE,     // type
    TK_LET,      // let
    TK_END,      // end
    TK_FUNCTION, // function
    TK_IN,       // in
    TK_OF,       // of

    TK_IF,    // if
    TK_THEN,  // then
    TK_ELSE,  // else
    TK_BREAK, // break
    TK_DO,    // do
    TK_WHILE, // while
    TK_FOR,   // for
    TK_TO,    // to

    TK_COMMA,     // ,
    TK_COLON,     // :
    TK_SEMICOLON, // ;
    TK_LPAREN,    // (
    TK_RPAREN,    // )
    TK_LBRACKET,  // [
    TK_RBRACKET,  // ]
    TK_LBRACE,    // {
    TK_RBRACE,    // }
    TK_DOT,       // .

    TK_PLUS,  // +
    TK_MINUS, // -
    TK_MULTI, // *
    TK_DIV,   // /

    TK_EQU,  // =
    TK_NEQU, // <>
    TK_LT,   // <
    TK_LEQU, // <=
    TK_GT,   // >
    TK_GEQU, // >=

    TK_AND, // &
    TK_OR,  // |

    TK_ASSIGN // :=
} token_t;

#endif