/* ANTLR grammar for STOMP. */

grammar STOMP;
 
options
{
    language=C;
}
 
@members
{

 #include "STOMPLexer.h"
 
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
 
    parser  ->expr(parser);

    parser ->free(parser);
    tokens ->free(tokens);
    lex    ->free(lex);
    
    input  ->close(input);
 
    return 0;
 }

}

/* Parser rules. */
 
frame_stream   : ( frame )
               ;

frame          : command EOL
                 ( header EOL )*
                 EOL
                 ( OCTET )*
                 NULL
                 ( EOL )*
               ;

command        : client_command
                 | server_command
               ;

client_command : 'SEND'
                 | 'SUBSCRIBE'
                 | 'UNSUBSCRIBE'
                 | 'BEGIN'
                 | 'COMMIT'
                 | 'ABORT'
                 | 'ACK'
                 | 'NACK'
                 | 'DISCONNECT'
                 | 'CONNECT'
                 | 'STOMP'
               ;

server_command : 'CONNECTED'
                 | 'MESSAGE'
                 | 'RECEIPT'
                 | 'ERROR'
               ;

header         : header_name COLON header_value
               ;

header_name    : SPECIAL
               ;
               
header_value   : ( header_name )*
               ;

/* Lexer rules. */

NULL    : '\u0000';
LF      : '\u000A';
CR      : '\u000D';
EOL     : (CR)? LF;
COLON   : ':';
OCTET   : '\u0000'..'\u00FF';
SPECIAL : '\u0000'..'\u0009' | '\u000B'..'\u000C' | '\u000E'..'\u00FF';

/* EOF */
