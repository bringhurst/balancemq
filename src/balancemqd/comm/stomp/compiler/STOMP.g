/* ANTLR grammar for STOMP. */

grammar STOMP;
 
options
{
    language=C;
}
 
/* Parser rules. */
 
frame_stream   : ( frame )
               {printf("Frame stream `\%s'.", $frame_stream.text);}
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

header         : header_name COLON header_value;
header_name    : SPECIAL;
header_value   : ( header_name )*;

/* Lexer rules. */

NULL    : '\u0000';
LF      : '\u000A';
CR      : '\u000D';
EOL     : (CR)? LF;
COLON   : ':';
OCTET   : '\u0000'..'\u00FF';
SPECIAL : ~(LF | CR | COLON) | OCTET;

/* EOF */
