#ifndef LEXER_H
#define LEXER_H

#include <stdlib.h>

typedef enum LexerError {
    LEX_EOK,
    LEX_EUNKNOWN,
} LexerError;

typedef enum Token {
    TOK_ERR,
    TOK_EOF,
    TOK_SEMICOLON,
} Token;

// The state of the lexer
typedef struct Lexer {
    // the source input
    const char* source;
    // the current parsed input
    const char* current;
    // the lexer error
    LexerError error;
    // the current parsed line
    size_t line;
    // the current parsed column
    size_t column;
} Lexer;

Token Lexer_NextToken(Lexer *lexer);

#endif
