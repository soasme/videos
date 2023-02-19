#include "lexer.h"

Token Lexer_NextToken(Lexer *lexer) {
    lexer->error = LEX_EUNKNOWN;
    return TOK_ERR;
}
