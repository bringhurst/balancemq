/*
 * This example is a distributed treewalk of a filesystem hierarchy. Assuming
 * the underlying filesystem is parallel (i.e. has multiple read heads), this
 * will distribute and balance the stat(2) workload among many nodes.
 *
 * This example contains minimal error checking to keep things readable.
 *
 * FIXME: This file is mostly psuedocode. It really eeds fixing so it actually
 *        compile and works.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <mqueue.h>

#define TREEWALK_QUEUE_NAME  "/queue/treewalk_example"

int main(int argc, char **argv)
{
    /* Open a handle to the message queue. */
    mqd_t mq = mq_open(TREEWALK_QUEUE_NAME, O_WRONLY);

    /* Send the root of the directory structure. */
    mq_send(mq, argv[1], strlen(argv[0]), 0);

    /*
     * Receive messages to print regular files and place directories back
     * on the queue.
     */
    char buffer[BALANCEMQ_MSG_MAX_SIZE];
    ssize_t bytes_read;

    while((bytes_read = mq_receive( \
          mq, buffer, BALANCEMQ_MSG_MAX_SIZE, NULL)) > 0) {

        struct stat s;
        lstat(buffer, &s);

        if(s.st_mode & S_IFREG) {
            printf("F: `%s'\n", buffer);
            continue;
        }

        if(s.st_mode & S_IFDIR) {
            printf("D: `%s'\n", buffer);

            dirent *dp;
            DIR* dfd = opendir(dir);

            while ((dp = readdir(dfd)) != NULL) {

                if (strcmp(dp->name, ".") == 0 \
                    || strcmp(dp->name, "..")) {
                    continue;
                }

                struct stat ds;
                lstat(dp->name, &ds);

                if(ds.st_mode & S_IFREG) {
                    printf("F: `%s'\n", dp->name);
                    continue;
                }

                if(s.st_mode & S_IFDIR) {
                    mq_send(mq, dp->name, BALANCEMQ_MSG_MAX_SIZE, 0);
                }
            }

            closedir(dfd);
        }
    }

    mq_close(mq);
    exit(EXIT_SUCCESS);
}

/* EOF */
