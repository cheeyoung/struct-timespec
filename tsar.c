/*
    array of struct timespec
    
    20211022 typedef struct tsarr
    20210821 Created
*/
#include <time.h>
#include <stdlib.h>  /* malloc */
#include <stdio.h>
#include "tsar.h"

int tsar_malloc(tsarr *ta, const int n)
{
    void *p ;
    int errno ;  /* Linux */
    
    (*ta).n_elements = n ;
    
    printf("DEBUG: size of struct timespec is %ld\n", sizeof(struct timespec)) ;
    (*ta).n_length = sizeof(struct timespec) ;
    
    (*ta).p = malloc((*ta).n_length * (*ta).n_elements) ;
    if ((*ta).p == 0)
    {
        printf("ERROR: malloc returned 0, errno = %d\n", errno) ;
        return -1 ;
    }
    printf("DEBUG: malloc returned 0x%lx\n", (unsigned long int)p) ;
    return 0 ;
}

int tsar_free(tsarr *ta)
{
    free((*ta).p) ;
    (*ta).p = 0 ;
    return 0 ;
}
