/*
    tsop.c - operators for struct timespec in time.h
    
    20211004 Created
*/
#include <time.h>

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
