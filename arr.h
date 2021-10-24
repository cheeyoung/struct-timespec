/*
*/
typedef struct
{
    int n_offset ;
    int n_he ;  /* head element */
    int al ;  /* length of the array, in array index */
    int el ;  /* length of each element, in byte */
    void *p ;  /* */
}   arr ;

/* functions */
int arr_malloc(arr *a, const int al, const int el) ;
int arr_free(arr *a) ;
