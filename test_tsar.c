/*
    test_tsar.c
    
    20211022 Created
*/
#include <stdio.h>
#include "tsar.h"

int main()
{
    tsarr ta ;
    
    int rv ;  /* Return Value */
    
    rv = tsar_malloc(&ta, 128) ;  /* 2048 = 2KB */
    printf("tsar_malloc returned %d\n", rv) ;
    rv = tsar_free(&ta) ;
    printf("tsar_free returned %d\n", rv) ;

    return 0;
}
