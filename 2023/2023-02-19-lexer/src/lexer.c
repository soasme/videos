#include "lexer.h"

void Lexer_Init(Lexer *lexer) {
    lexer->source = NULL;
    lexer->current = NULL;
    lexer->line = 1;
    lexer->column = 1;
    lexer->error = LEX_EOK;
}

void Lexer_SetSource(Lexer *lexer, const char* s) {
    lexer->source = s;
    lexer->current = s;
}

char Lexer_GetChar(Lexer *lexer, size_t offset) {
    return *(lexer->current+offset);
}

Token Lexer_NextOp(Lexer *lexer) {
    char c = Lexer_GetChar(lexer, 0);
    switch (c) {
        case ';':
            lexer->column++;
            lexer->current++;
            return TOK_SEMICOLON;
        case '{':
            lexer->column++;
            lexer->current++;
            return TOK_LBRACE;
        case '(':
            lexer->column++;
            lexer->current++;
            return TOK_LPAREN;
        case '[':
            lexer->column++;
            lexer->current++;
            return TOK_LBRACKET;
        case '}':
            lexer->column++;
            lexer->current++;
            return TOK_RBRACE;
        case ')':
            lexer->column++;
            lexer->current++;
            return TOK_RPAREN;
        case ']':
            lexer->column++;
            lexer->current++;
            return TOK_RBRACKET;
        case ',':
            lexer->column++;
            lexer->current++;
            return TOK_COMMA;
        case ':':
            lexer->column++;
            lexer->current++;
            return TOK_COLON;
        default:
            lexer->error = LEX_EUNKNOWN;
            return TOK_ERR;
    }
}

Token Lexer_NextToken(Lexer *lexer) {
    char c = Lexer_GetChar(lexer, 0);
    switch (c) {
        case '\0':
            return TOK_EOF;
        case ';': case '{': case '(': case '[':
        case '}': case ')': case ']': case ',':
        case ':':
            return Lexer_NextOp(lexer);
        default:
            lexer->error = LEX_EUNKNOWN;
            return TOK_ERR;
    }
}
