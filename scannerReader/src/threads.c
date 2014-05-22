#include "stdio.h"

void* reader(void* thread_params)
{
    printf("Hello Thread.\n");
    return NULL;
}
