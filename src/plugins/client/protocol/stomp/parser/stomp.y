%{
 /* Parser for the STOMP 1.2 protocol. */

 #include <stdio.h>
 #include "../client_protocol_stomp.h"

stomp_node_t *stomp_frame_root;

 void yyerror(const char *str) {
     fprintf(stderr,"error: %s\n",str);
 }
 
 int yywrap() {
     return 1;
 }

 int yylex(void);
%}

%defines
%error-verbose

/* Tokens for header file generation. */
%token <string> T_CLIENT_SEND T_CLIENT_SUBSCRIBE T_CLIENT_UNSUBSCRIBE T_CLIENT_BEGIN
%token <string> T_CLIENT_COMMIT T_CLIENT_ABORT T_CLIENT_ACK T_CLIENT_NACK
%token <string> T_CLIENT_DISCONNECT T_CLIENT_CONNECT T_CLIENT_STOMP T_SERVER_CONNECTED
%token <string> T_SERVER_MESSAGE T_SERVER_RECEIPT T_SERVER_ERROR T_NULL T_LF T_CR T_EOL
%token <string> T_COLON T_OCTET T_SPECIAL

%union {
    char* string;
    /* stomp_node_t *node */
}

%type <string> expression frame header command
%type <string> frame_command frame_header frame_octet
%type <string> client_command

%%
expression     : frame { printf("received frame = %s\n", $1); }
               ;

frame          : frame_command
                 frame_command
                 T_EOL
                 frame_octet
                 T_NULL
                 frame_eol
               ;

frame_command  : command T_EOL { printf("received frame_command = %s\n", $1); }
               ;

frame_header   : header T_EOL
               | header T_EOL frame_header
               ;

frame_octet    : T_OCTET
               | T_OCTET frame_octet
               ;

frame_eol      : T_EOL
               | T_EOL frame_eol
               ;

command        : client_command 
               | server_command
               ;

client_command : T_CLIENT_SEND
               | T_CLIENT_SUBSCRIBE
               | T_CLIENT_UNSUBSCRIBE
               | T_CLIENT_BEGIN
               | T_CLIENT_COMMIT
               | T_CLIENT_ABORT
               | T_CLIENT_ACK
               | T_CLIENT_NACK
               | T_CLIENT_DISCONNECT
               | T_CLIENT_CONNECT
               | T_CLIENT_STOMP { printf("received client_command = %s\n", $1); }
               ;

server_command : T_SERVER_CONNECTED
               | T_SERVER_MESSAGE
               | T_SERVER_RECEIPT
               | T_SERVER_ERROR
               ;

header         : header_name T_COLON header_value
               ;

header_name    : T_SPECIAL
               ;

header_value   : header_name
               | header_name header_value
               ;
%%
