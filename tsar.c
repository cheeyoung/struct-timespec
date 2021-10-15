/*
    array of struct timespec

    20210821 Created
*/
#include <time.h>
#include <stdlib.h>  /* malloc */
#include <stdio.h>

struct timespec *tsar_malloc(const int n)
{
    void *p ;
    int errno ;  /* Linux */
    
    printf("DEBUG: size of struct timespec is %ld\n", sizeof(struct timespec)) ;
    p = malloc(sizeof(struct timespec) * n) ;
    if (p == 0)
    {
        printf("ERROR: malloc returned 0, errno = %d\n", errno) ;
        return 0 ;
    }
    printf("DEBUG: malloc returned 0x%lx\n", (unsigned long int)p) ;
    return (struct timespec *)p ;
}

int tsar_free(struct timespec *ts)
{
    free(ts) ;
    return 0 ;
}
