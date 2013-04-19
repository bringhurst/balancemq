#include <config.h>

#include "balancemqd.h"
#include <log.h>

#include <getopt.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <inttypes.h>

/**
 * Print the current version.
 */
void BALANCE_print_version()
{
    fprintf(stdout, "%s-%s <%s>\n", \
            PACKAGE_NAME, PACKAGE_VERSION, PACKAGE_URL);
}

/**
 * Print a usage message.
 */
void BALANCE_print_usage(char** argv)
{
    printf("usage: %s [chv]\n", argv[0]);
}

int main(int argc, \
         char** argv)
{
    int c;
    int option_index = 0;

    char* config_file_path = "/etc/balancemq/balancemq.conf";

    FILE* BALANCE_debug_stream = stdout;
    BALANCE_loglevel BALANCE_debug_level = BALANCE_LOG_DBG;

    static struct option long_options[] = {
        {"config-file-path"     , required_argument, 0, 'c'},
        {"help"                 , no_argument      , 0, 'h'},
        {"version"              , no_argument      , 0, 'v'},
        {0                      , 0                , 0, 0  }
    };

    /* Parse options */
    while((c = getopt_long(argc, argv, "c:hv", \
                           long_options, &option_index)) != -1) {
        switch(c) {

            case 'c':
                config_file_path = strdup(optarg);
                break;

            case 'h':
                BALANCE_print_usage(argv);
                exit(EXIT_SUCCESS);
                break;

            case 'v':
                BALANCE_print_version();
                exit(EXIT_SUCCESS);
                break;

            case '?':
            default:

                if(optopt == 'c') {
                    BALANCE_print_usage(argv);
                    fprintf(stderr, "Option -%c requires an argument.\n", \
                            optopt);
                }
                else if(isprint(optopt)) {
                    BALANCE_print_usage(argv);
                    fprintf(stderr, "Unknown option `-%c'.\n", optopt);
                }
                else {
                    BALANCE_print_usage(argv);
                    fprintf(stderr,
                            "Unknown option character `\\x%x'.\n",
                            optopt);
                }

                exit(EXIT_FAILURE);
                break;
        }
    }

    LOG(BALANCE_LOG_DBG, "Using config file path of `%s'.", config_file_path);

    /* TODO: config file parser */

    /* TODO: start main libcircle based event loop */

    /* TODO: plugin loader (based on config file) */

    /* TODO: wait for shutdown signal */

    /* TODO: plugin finalizer */

    exit(EXIT_SUCCESS);
}

/* EOF */
