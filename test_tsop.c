/*
    for tsop.c
    
    20211004 Created
*/
#include <time.h>
#include <stdio.h>
#include "tsop.h"

int main()
{
    struct timespec ts1, ts2, ts3 ;
    
    int rv ;  /* Return Value */
    int errno ;  /* Linux */
    
    rv = clock_gettime(CLOCK_MONOTONIC, &ts1) ;
    if (rv != 0)  /* rv == -1 */
    {
        printf("ERROR: clock_gettime returned %d, errno = %d\n", rv, errno) ;
        return -1 ;
    }
    printf("DEBUG: %ld.%09ld \n", ts1.tv_sec, ts1.tv_nsec) ;

    rv = clock_gettime(CLOCK_MONOTONIC, &ts2) ;
    if (rv != 0)  /* rv == -1 */
    {
        printf("ERROR: clock_gettime returned %d, errno = %d\n", rv, errno) ;
        return -1 ;
    }
    printf("DEBUG: %ld.%09ld \n", ts2.tv_sec, ts2.tv_nsec) ;
    
    rv = tsop_subtract(&ts2, &ts1, &ts3) ;
    printf("Elapsed Time : %ld.%09ld \n", ts3.tv_sec, ts3.tv_nsec) ;

    return 0 ;
}
