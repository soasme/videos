#include <stdio.h>
#include <assert.h>
#include "lexer.h"

int main(int argc, char** argv) {

    {
        Lexer lexer = {0};
        Token tok = Lexer_NextToken(&lexer);
        assert(tok == TOK_ERR);
        assert(lexer.error == LEX_EUNKNOWN);
    }

    printf("all test passed");
    return 0;
}
