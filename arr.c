/*
    20211028 Created
*/
#include <stdlib.h>  /* malloc */
#include <string.h>  /* strlen */
#include <stdio.h>
#include "arr.h"

/* functions */
int arr_dump(arr *a)
{
    printf("Array %lx\n", (unsigned long int)(*a).p) ;
    printf("The number of elements is %d\n", (*a).al) ;
    printf("The length of each element is %d for type \"%s\"\n", (*a).el, (*a).typestr) ;
    return 0 ;
}

int arr_malloc(arr *a, const int al, const int el, const char *typestr)
{
    size_t len ;
    int errno ;  /* Linux */
    
    (*a).al = al ; (*a).el = el ;
    
    len = strlen(typestr) ;
    len = len + 1 ;  /* for null */
    (*a).typestr = malloc(len) ;
    if ((*a).typestr == 0)
    {
        printf("ERROR: malloc returned 0 for %ld, errno = %d\n", len, errno) ;
        return -1 ;
    }
    printf("DEBUG: malloc returned %lx for %ld\n", (unsigned long int)(*a).typestr, len) ;
    strcpy((*a).typestr, typestr) ;
    
    len = (*a).el * (*a).al ;
    (*a).p = malloc(len) ;
    if ((*a).p == 0)
    {
        printf("ERROR: malloc returned 0 for %ld, errno = %d\n", len, errno) ;
        return -1 ;
    }
    printf("DEBUG: malloc returned %lx for %ld\n", (unsigned long int)(*a).p, len) ;
    return 0 ;
}

int arr_free(arr *a)
{
    free((*a).typestr) ;
    (*a).typestr = 0 ;
    free((*a).p) ;
    (*a).p = 0 ;
    return 0 ;
}
