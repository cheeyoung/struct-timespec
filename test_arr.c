/*
    20211024 Created
*/
#include <time.h>
#include <stdio.h>
#include "arr.h"

int main()
{
    arr a1, a2, a3, a4, a5 ;
    
    int rv ;  /* Return Value */
    
    rv = arr_malloc(&a1, 12, sizeof(int), "int") ;
    printf("arr_malloc returned %d\n", rv) ;
    rv = arr_dump(&a1) ;
    
    rv = arr_malloc(&a2, 256, sizeof(long int), "long int") ;
    printf("arr_malloc returned %d\n", rv) ;
    rv = arr_dump(&a2) ;
    
    rv = arr_malloc(&a3, 512, sizeof(float), "float") ;
    printf("arr_malloc returned %d\n", rv) ;
    rv = arr_dump(&a3) ;
    
    rv = arr_malloc(&a4, 256, sizeof(double), "double") ;
    printf("arr_malloc returned %d\n", rv) ;
    rv = arr_dump(&a4) ;
    
    rv = arr_malloc(&a5, 12, sizeof(struct timespec), "struct timespec") ;  /* 2048 = 2KB */
    printf("arr_malloc returned %d\n", rv) ;
    rv = arr_dump(&a5) ;

    for (int i = 0; i < 17; i++)
    {
        rv = arr_add_int(&a1, i) ;
        printf("arr_add_int returned %d\n", rv) ;
    }
    
    for (int i = 0; i < 11; i++)
        printf("%d\n", ((int *)a1.p)[i]) ;

    rv = arr_add_int(&a2, 1) ;
    printf("arr_add_int returned %d\n", rv) ;
    
    for (int i = 0; i < 17; i++)
    {
        rv = arr_add_timespec(&a5) ;
        printf("arr_add_timespec returned %d\n", rv) ;
    }
    
    for (int i = 0; i < 11; i++)
        printf("%ld.%09ld\n", ((struct timespec *)a5.p)[i].tv_sec, ((struct timespec *)a5.p)[i].tv_nsec) ;

    rv = arr_free(&a1) ;
    printf("arr_free returned %d\n", rv) ;

    rv = arr_free(&a2) ;
    printf("arr_free returned %d\n", rv) ;

    rv = arr_free(&a3) ;
    printf("arr_free returned %d\n", rv) ;

    rv = arr_free(&a4) ;
    printf("arr_free returned %d\n", rv) ;

    rv = arr_free(&a5) ;
    printf("arr_free returned %d\n", rv) ;

    return 0 ;
}
