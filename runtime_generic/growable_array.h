#ifndef GROWABLE_INT_ARRAY_H
#define GROWABLE_INT_ARRAY_H

#include <stddef.h>
#include <stdlib.h>

struct GrowableArray {
    void** data;
    size_t allocated;
    size_t size;

    void (*cleanup)(void*);
};

struct GrowableArray growable_array_empty() {
    struct GrowableArray empty = {
       .data = NULL,
       .allocated = 0,
       .size = 0
    };
    
    return empty;
}

void growable_array_add(
    struct GrowableArray* array, 
    void* value
) {
    if (array->size + 1 > array->allocated) {
       size_t new_allocated;
       if (array->size == 0) {
           new_allocated = 2;
       }
       else {
           new_allocated = array->size * 2;
       }
       
       void** new_data = (void**) calloc(sizeof(void*), new_allocated);
       void** old_data = array->data;
       
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

size_t growable_array_size(
    struct GrowableArray* array
) {
    return array->size;
}


void* growable_array_get(
    struct GrowableArray* array, 
    size_t i
) {
    // You can do precondition checks and crash early if someone
    // tries to out of bounds if you want.
    return array->data[i];
}

#endif