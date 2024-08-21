#include <stddef.h>
#include <stdlib.h>

#ifndef GROWABLE_ARRAY_STRUCT
#error "GROWABLE_ARRAY_STRUCT not defined"
#endif

#ifndef GROWABLE_ARRAY_STRUCT_POINTER
#error "GROWABLE_ARRAY_STRUCT_POINTER not defined"
#endif

#ifndef GROWABLE_ARRAY_DATA
#error "GROWABLE_ARRAY_DATA not defined"
#endif

#ifndef GROWABLE_ARRAY_DATA_POINTER
#error "GROWABLE_ARRAY_DATA_POINTER not defined"
#endif

#ifndef GROWABLE_ARRAY_EMPTY_FUNCTION_NAME
#error "GROWABLE_ARRAY_EMPTY_FUNCTION_NAME not defined"
#endif

#ifndef GROWABLE_ARRAY_CLEANUP_FUNCTION_NAME
#error "GROWABLE_ARRAY_CLEANUP_FUNCTION_NAME not defined"
#endif

#ifndef GROWABLE_ARRAY_ADD_FUNCTION_NAME
#error "GROWABLE_ARRAY_ADD_FUNCTION_NAME not defined"
#endif

GROWABLE_ARRAY_STRUCT {
    GROWABLE_ARRAY_DATA_POINTER data;
    size_t allocated;
    size_t size;
};

GROWABLE_ARRAY_STRUCT GROWABLE_ARRAY_EMPTY_FUNCTION_NAME() {
    GROWABLE_ARRAY_STRUCT empty = {
       .data = NULL,
       .allocated = 0,
       .size = 0
    };
    
    return empty;
}


void GROWABLE_ARRAY_ADD_FUNCTION_NAME(
    GROWABLE_ARRAY_STRUCT_POINTER array, 
    GROWABLE_ARRAY_DATA value
) {
    if (array->size + 1 > array->allocated) {
       size_t new_allocated;
       if (array->size == 0) {
           new_allocated = 2;
       }
       else {
           new_allocated = array->size * 2;
       }
       
       GROWABLE_ARRAY_DATA_POINTER new_data 
            = (GROWABLE_ARRAY_DATA_POINTER) calloc(sizeof(void*), new_allocated);
       GROWABLE_ARRAY_DATA_POINTER old_data = array->data;
       
       // Copy all the old elements to it
       if (old_data != NULL) {
           for (size_t i = 0; i < array->size; i++) {
               new_data[i] = old_data[i];
           }
       }
       
       free(old_data);

       array->data = new_data;
       array->allocated = new_allocated;
    }
    
    array->data[array->size] = value;
    array->size++;
}

size_t GROWABLE_ARRAY_SIZE_FUNCTION_NAME(
    GROWABLE_ARRAY_STRUCT_POINTER array
) {
    return array->size;
}


GROWABLE_ARRAY_DATA GROWABLE_ARRAY_GET_FUNCTION_NAME(
    GROWABLE_ARRAY_STRUCT_POINTER array, 
    size_t i
) {
    return array->data[i];
}

void GROWABLE_ARRAY_CLEANUP_FUNCTION_NAME(
    GROWABLE_ARRAY_STRUCT_POINTER array
) {
    #ifdef GROWABLE_ARRAY_ITEM_CLEANUP_FUNCTION_NAME
        for (size_t i = 0; i < array->size; i++) {
            GROWABLE_ARRAY_ITEM_CLEANUP_FUNCTION_NAME(array->data[i]);
        }
    #endif

    free(array->data);
}
