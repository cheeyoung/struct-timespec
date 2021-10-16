/*
    tsop.h - operators for struct timespec in time.h
    
    20211004 Created
*/
#include <time.h>

/* functions */
int tsop_gettime(struct timespec *p) ;

int tsop_subtract
( const struct timespec *ts1
, const struct timespec *ts2
, struct timespec *ts3 
) ;
