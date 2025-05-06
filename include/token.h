#ifndef __TOKEN_H
#define __TOKEN_H

// token definitions
typedef enum token {
    IDENT, // identifier
    INTEGER, // integer
    STRING, // a sequence of characters
    ARRAY, // array
    BREAK, // break
    DO, // do
    ELSE, // else
    END, // end
    FOR, // for
    FUNCTION, // function
    IF, // if
    IN, // in
    LET, // let
    NIL, // nil
    OF, // of
    THEN, // then
    TO, // to
    TYPE, // type
    VAR, // var
    WHILE, // while
    COMMA, // ,
    COLON, // :
    SEMICOLON, // ;
    LPAREN, // (
    RPAREN, // )
    LBRACKET, // [
    RBRACKET, // ]
    LBRACE, // {
    RBRACE, // }
    DOT, // .
    PLUS, // +
    MINUS, // -
    MULTI, // *
    DIV, // /
    EQU, // =
    NEQU, // <>
    LT, // <
    LEQU, // <=
    GT, // >
    GEQU, // >=
    AND, // &
    OR, // |
    ASSIGN // :=
} token_t;

#endif