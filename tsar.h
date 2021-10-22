/*
    array of struct timespec
    
    20211022 typedef struct tsarr
    20210821 Created
*/

typedef struct
{
    int n_elements ;  /* number of the elements, length of the array in array index */
    int n_length ;  /* length of the elements in byte */
    struct timespec *p ;
}   tsarr ;

/* functions */
int tsar_malloc(tsarr *ta, const int n) ;
int tsar_free(tsarr *ta) ;
