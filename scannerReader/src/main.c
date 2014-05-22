#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "threads.h"

int main(void)
{
    pthread_t thread_id;
    if (pthread_create(&thread_id, NULL, reader, NULL) != 0)
    {
        return EXIT_FAILURE;
    }
    printf("Started.\n");
    if (pthread_join(thread_id, NULL) != 0)
    {
        return EXIT_FAILURE;
    }
    printf("Finished.\n");
    return EXIT_SUCCESS;
}
