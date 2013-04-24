/* TODO: file info here. */

/*
 * The public header file MUST be included first. Otherwise, header dependency
 * bugs may creep in.
 */
#include <balancemq/balancemq.h>

#include "config.h"

#include "balancemqd.h"
#include "log.h"

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

    BALANCE_context_t* ctx = NULL;
    char* config_file_path = "/etc/balancemq/balancemq.conf";

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

    /* A context to access logging facilities. */
    BALANCE_init_context(ctx);

    LOG(ctx, BALANCE_LOG_INFO, "[core] Starting up...\n");
    LOG(ctx, BALANCE_LOG_INFO, \
        " ____        _                      __  __  ___\n" \
        "| __ )  __ _| | __ _ _ __   ___ ___|  \\/  |/ _ \\\n" \
        "|  _ \\ / _` | |/ _` | '_ \\ / __/ _ \\ |\\/| | | | |\n" \
        "| |_) | (_| | | (_| | | | | (__| __/ |  | | |_| |\n" \
        "|____/ \\__,_|_|\\__,_|_| |_|\\___\\___|_|  |_|\\__\\_\\\n" \
        " A self-stabilizing continuous workload balancer.\n\n");

    LOG(ctx, BALANCE_LOG_INFO, "[core] Using configuration file at `%s'.\n", config_file_path);
    /* TODO: config file parser */

    LOG(ctx, BALANCE_LOG_INFO, "[core] Searching for available plugins at `%s'.\n", "TODO");
    /* TODO: plugin loader (based on config file) */

    LOG(ctx, BALANCE_LOG_INFO, "[core] Accepting new connections.\n");
    /* TODO: start main libcircle based event loop */

    LOG(ctx, BALANCE_LOG_INFO, "[core] Finalizing existing connections.\n");
    /* TODO: wait for shutdown signal */

    LOG(ctx, BALANCE_LOG_INFO, "[core] Cleaning up plugins.\n");
    /* TODO: plugin finalizer */

    LOG(ctx, BALANCE_LOG_INFO, "[core] Shutting down.\n");
    exit(EXIT_SUCCESS);
}

/* EOF */
