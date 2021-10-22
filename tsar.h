/*
    array of struct timespec
    
    20211022 typedef struct tsarr
    20210821 Created
*/

typedef struct
{
    int n_offset ;  /* number of the elements to skip */
    int n_elements ;  /* number of the elements in the array, length of the array in array index */
    int n_length ;  /* length of the elements(struct timespec) in byte */
    struct timespec *p ;  /* void *p */
}   tsarr ;

/* functions */
int tsar_gettime(tsarr *ta) ;
int tsar_malloc(tsarr *ta, const int n) ;
int tsar_free(tsarr *ta) ;
