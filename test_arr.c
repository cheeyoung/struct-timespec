/*
    20211024 Created
*/
#include <stdio.h>
#include "arr.h"

int main()
{
    arr a ;
    
    int rv ;  /* Return Value */
    
    rv = arr_malloc(&a, 256, sizeof(int)) ;
    printf("arr_malloc returned %d\n", rv) ;
    
    for (int i = 0; i < 256; i++)
        ((int *)a.p)[i] = i ;
    
    for (int i = 0; i < 256; i++)
        printf("%d ", ((int *)a.p)[i]) ;
    
    rv = arr_free(&a) ;
    printf("arr_free returned %d\n", rv) ;

    return 0 ;
}
