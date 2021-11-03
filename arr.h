/*
    20211028 Created
*/
typedef struct
{
    int ne ;  /* next element */
    /* array */
    int al ;  /* length of the array, in array index */
    int el ;  /* length of each element, in byte */
    char *typestr ;
    void *p ;
}   arr ;

/* functions */
int arr_add_int(arr *a, int n) ;
int arr_dump(arr *a) ;
int arr_malloc(arr *a, const int al, const int el, const char *typestr) ;
int arr_free(arr *a) ;
