#include <stdio.h>
#include <assert.h>
#include "lexer.h"

#define SETUP(s) \
        Lexer lexer = {0}; \
        Lexer_Init(&lexer); \
        Lexer_SetSource(&lexer, (s));

#define TESTNEXT(t) \
        assert(Lexer_NextToken(&lexer)== (t));

int main(int argc, char** argv) {

    {
        SETUP("();")
        TESTNEXT(TOK_LPAREN);
        TESTNEXT(TOK_RPAREN);
        TESTNEXT(TOK_SEMICOLON);
        TESTNEXT(TOK_EOF); // reach the end
        TESTNEXT(TOK_EOF); // no more lexing
    }

    {
        SETUP("{};")
        TESTNEXT(TOK_LBRACE);
        TESTNEXT(TOK_RBRACE);
        TESTNEXT(TOK_SEMICOLON);
        TESTNEXT(TOK_EOF); // reach the end
        TESTNEXT(TOK_EOF); // no more lexing
    }

    {
        SETUP("[];")
        TESTNEXT(TOK_LBRACKET);
        TESTNEXT(TOK_RBRACKET);
        TESTNEXT(TOK_SEMICOLON);
        TESTNEXT(TOK_EOF); // reach the end
        TESTNEXT(TOK_EOF); // no more lexing
    }

    {
        SETUP(":")
        TESTNEXT(TOK_COLON);
        TESTNEXT(TOK_EOF);
    }

    {
        SETUP(",")
        TESTNEXT(TOK_COMMA);
        TESTNEXT(TOK_EOF);
    }

    printf("all test passed");
    return 0;
}
