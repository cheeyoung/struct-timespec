/*
    tsop.c - operators for struct timespec in time.h
    
    20211004 Created
*/
#include <time.h>
#include <stdio.h>

int tsop_gettime(struct timespec *p)
{
    int rv ;  /* Return Value */
    int errno ;  /* Linux */
    
    rv = clock_gettime(CLOCK_MONOTONIC, p ) ;
    if (rv != 0)  /* rv == -1 */
    {
        printf("ERROR: clock_gettime returned %d, errno = %d\n", rv, errno) ;
        return -1 ;
    }
    printf("DEBUG: %ld.%09ld \n", (*p).tv_sec, (*p).tv_nsec) ;
    return 0 ;
}

int tsop_subtract
( const struct timespec *ts1
, const struct timespec *ts2
, struct timespec *ts3
)
{
    (*ts3).tv_sec = (*ts1).tv_sec - (*ts2).tv_sec ;
    (*ts3).tv_nsec = (*ts1).tv_nsec - (*ts2).tv_nsec ;
    if ( (*ts3).tv_nsec < 0 )
    {
        (*ts3).tv_sec = (*ts3).tv_sec - 1 ;
        (*ts3).tv_nsec = (*ts3).tv_nsec + 1000000000 ;  /* 1,000,000,000 */
    }

    return 0 ;
}
