#include "STOMPLexer.h"
#include "STOMPParser.h"
 
int main(int argc, char* argv[])
{
    pANTLR3_INPUT_STREAM        input;
    pSTOMPLexer                 lex;
    pANTLR3_COMMON_TOKEN_STREAM tokens;
    pSTOMPParser                parser;
 
    input  = antlr3AsciiFileStreamNew         ((pANTLR3_UINT8)argv[1]);
    lex    = STOMPLexerNew                    (input);
    tokens = antlr3CommonTokenStreamSourceNew (ANTLR3_SIZE_HINT, TOKENSOURCE(lex));
    parser = STOMPParserNew                   (tokens);
 
    parser->frame_stream(parser);

    parser->free(parser);
    tokens->free(tokens);
    lex->free(lex);
    
    input->close(input);
 
    return 0;
}

/* EOF */
