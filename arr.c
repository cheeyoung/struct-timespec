/*
*/
#include <stdlib.h>  /* malloc */
#include <stdio.h>
#include "arr.h"

/* functions */
int arr_malloc(arr *a, const int al, const int el)
{
    int errno ;  /* Linux */
    
    (*a).el = el ; (*a).al = al ;
    (*a).n_offset = 0 ; (*a).n_he = 0 ;
    
    (*a).p = malloc((*a).el * (*a).al) ;
    if ((*a).p == 0)
    {
        printf("ERROR: malloc returned 0, errno = %d\n", errno) ;
        return -1 ;
    }
    printf("DEBUG: malloc returned %lx\n", (unsigned long int)(*a).p) ;
    return 0 ;
}

int arr_free(arr *a)
{
    free((*a).p) ;
    (*a).p = 0 ;
    return 0 ;
}
