#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

#define MAX 1000000

//Time in nanoseconds
double getntime(struct timespec *begin, struct timespec *end)
{
    return (((end->tv_sec - begin->tv_sec)*1000000000) + \
            (end->tv_nsec - begin->tv_nsec)); //Time in nanoseconds
}

int main(int argc, char *argv[])
{

    int i;

    struct timespec start, end;

    clock_gettime(CLOCK_REALTIME, &start);
    for(i=0; i<MAX; i++)
    {
         //call systemcall
    }
    clock_gettime(CLOCK_REALTIME, &end);

    printf("Time spent in systemcall = %f ns\n", getntime(&start, &end)/MAX);
    
    return 0;
}
