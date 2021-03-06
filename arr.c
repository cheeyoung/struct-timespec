/*
    20211028 Created
*/
#include <time.h>
#include <stdlib.h>  /* malloc */
#include <string.h>  /* strlen */
#include <stdio.h>
#include "tsop.h"
#include "arr.h"

/* functions */
int arr_add_int(arr *a, int n)
{
    int i ;
    
    if (sizeof(int) != (*a).el)
    {
        printf("ERROR: The length of each element is %d for type \"%s\"\n", (*a).el, (*a).typestr) ;
        return -1 ;
    }
    
    i = (*a).ne ;
    printf("DEBUG: ne = %d, Array %lx\n", i, (unsigned long int)(*a).p) ;
    
    ((int *)(*a).p)[i] = n ;
    (*a).ne = ((*a).ne + 1) % (*a).al ;
    return 0 ;
}

int arr_add_timespec(arr *a)
{
    int i ;
    int rv ;  /* Return Value */
    
    if (sizeof(struct timespec) != (*a).el)
    {
        printf("ERROR: The length of each element is %d for type \"%s\"\n", (*a).el, (*a).typestr) ;
        return -1 ;
    }
    
    i = (*a).ne ;
    printf("DEBUG: ne = %d, Array %lx\n", i, (unsigned long int)(*a).p) ;
    
    rv = tsop_gettime(&(((struct timespec *)(*a).p)[i])) ;
    if (rv != 0)  /* rv == -1 */
    {
        printf("ERROR: tsop_gettime returned %d\n", rv) ;
        return -1 ;
    }
    (*a).ne = ((*a).ne + 1) % (*a).al ;
    return 0 ;
}

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
    
    (*a).ne = 0 ;
    
    /* array */
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
