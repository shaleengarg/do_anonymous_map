#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/mman.h>
#include <sys/time.h>
#include <unistd.h>

//#define GB 1024*1024*1024

//Time in nanoseconds
double getntime(struct timespec *begin, struct timespec *end)
{
    return (((end->tv_sec - begin->tv_sec)*1000000000) + \
            (end->tv_nsec - begin->tv_nsec)); //Time in nanoseconds
}

int main()
{
    size_t Pagesize = getpagesize();
    long long int GB = 1024 * 1024 * 1024;
    printf("The Page size is %d\n", Pagesize);

    //char *Mem = mmap((void *)(Pagesize * (1<<10)), 2*GB, PROT_READ|PROT_WRITE|PROT_EXEC, MAP_ANON | MAP_PRIVATE , 0, 0);
    //char *Mem = mmap(NULL, 2*GB, PROT_READ|PROT_WRITE|PROT_EXEC, MAP_ANON | MAP_PRIVATE | MAP_POPULATE, 0, 0);
    char *Mem = mmap(NULL, 2*GB, PROT_READ|PROT_WRITE|PROT_EXEC, MAP_ANON | MAP_PRIVATE, 0, 0);
    struct timespec start, end;
    register long long int i;

    //int count =0 ;
    clock_gettime(CLOCK_REALTIME, &start);
    
    for(i=0; i<2*GB/sizeof(char); i+=Pagesize)
    {
        //count ++;
        Mem[i] = (char) i;
    }
    
    clock_gettime(CLOCK_REALTIME, &end);

    //printf("coujnt = %d\n", count);
    printf("Time spent in systemcall = %f ns\n", getntime(&start, &end)/(i/Pagesize));
    //printf("Time spent in systemcall = %f ns\n", getntime(&start, &end)/count);
    return 0;
}
