/*
    array of struct timespec
    
    20211022 typedef struct tsarr
    20210821 Created
*/
#include <time.h>
#include <stdlib.h>  /* malloc */
#include <stdio.h>
#include "tsop.h"
#include "tsar.h"

int tsar_gettime(tsarr *ta)
{
    int i ;
    int rv ;  /* Return Value */
    
    /* offset is the number of elements to skip */
    /* array index is zero based */
    i = (*ta).n_offset ;  
    printf("DEBUG: n_offset = %d\n", i) ;
    
    rv = tsop_gettime(&((*ta).p[i])) ;
    if (rv != 0)  /* rv == -1 */
    {
        printf("ERROR: tsop_gettime returned %d\n", rv) ;
        /* return to the caller leaving the offest as before */
        return -1 ;
    }
    
    /* if successful, advance the offset by 1. means commit this local transaction. */
    (*ta).n_offset = (*ta).n_offset + 1 ;
    /* if the offset == the number of elements then reset the offset to 0 */
    if ((*ta).n_offset == (*ta).n_elements)
        (*ta).n_offset = 0 ;
    return 0 ;
}

int tsar_malloc(tsarr *ta, const int n)
{
    void *p ;
    int errno ;  /* Linux */
    
    (*ta).n_offset = 0 ;
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
