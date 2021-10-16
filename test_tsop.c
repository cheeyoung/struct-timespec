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
    
    rv = tsop_gettime(&ts1) ;
    if (rv != 0)  /* rv == -1 */
    {
        printf("ERROR: tsop_gettime returned %d\n", rv) ;
        return -1 ;
    }
    printf("INFO: %ld.%09ld \n", ts1.tv_sec, ts1.tv_nsec) ;

    rv = tsop_gettime(&ts2) ;
    if (rv != 0)  /* rv == -1 */
    {
        printf("ERROR: tsop_gettime returned %d\n", rv) ;
        return -1 ;
    }
    printf("INFO: %ld.%09ld \n", ts2.tv_sec, ts2.tv_nsec) ;
    
    rv = tsop_subtract(&ts2, &ts1, &ts3) ;
    printf("Elapsed Time : %ld.%09ld \n", ts3.tv_sec, ts3.tv_nsec) ;

    ts2.tv_sec = 1 ; ts2.tv_nsec = 1 ;  /* 000,000,001 */
    printf("INFO: %ld.%09ld \n", ts2.tv_sec, ts2.tv_nsec) ;
    ts1.tv_sec = 0 ; ts1.tv_nsec = 999999999 ;  /* 999,999,999 */
    printf("INFO: %ld.%09ld \n", ts1.tv_sec, ts1.tv_nsec) ;

    rv = tsop_subtract(&ts2, &ts1, &ts3) ;
    printf("Elapsed Time : %ld.%09ld \n", ts3.tv_sec, ts3.tv_nsec) ;

    ts2.tv_sec = 0 ; ts2.tv_nsec = 999999999 ;  /* 999,999,999 */
    printf("INFO: %ld.%09ld \n", ts2.tv_sec, ts2.tv_nsec) ;
    ts1.tv_sec = 1 ; ts1.tv_nsec = 2 ;  /* 000,000,002 */
    printf("INFO: %ld.%09ld \n", ts1.tv_sec, ts1.tv_nsec) ;

    rv = tsop_add(&ts2, &ts1, &ts3) ;
    printf("Total : %ld.%09ld \n", ts3.tv_sec, ts3.tv_nsec) ;

    return 0 ;
}
