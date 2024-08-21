#ifndef GROWABLE_INT_ARRAY_H
#define GROWABLE_INT_ARRAY_H

#include <stddef.h>
#include <stdlib.h>

struct GrowableIntArray {
    int* data;
    size_t allocated;
    size_t size;
};

struct GrowableIntArray growable_int_array_empty() {
    struct GrowableIntArray empty = {
       .data = NULL,
       .allocated = 0,
       .size = 0
    };
    
    return empty;
}

void growable_int_array_add(
    struct GrowableIntArray* array, 
    int value
) {
    // If we wouldn't have enough room
    if (array->size + 1 > array->allocated) {
       // Double the size of the last array
       size_t new_allocated;
       if (array->size == 0) {
           new_allocated = 2;
       }
       else {
           new_allocated = array->size * 2;
       }
       
       // Make a new array that size
       int* new_data = calloc(sizeof(int), new_allocated);
       int* old_data = array->data;
       
       // Copy all the old elements to it
       if (old_data != NULL) {
           for (size_t i = 0; i < array->size; i++) {
               new_data[i] = old_data[i];
           }
       }
       
       // Then free the old array
       free(old_data);
       
       // And patch up the pointers 
       array->data = new_data;
       array->allocated = new_allocated;
    }
    
    // And put in the new element
    array->data[array->size] = value;
    array->size++;
}

size_t growable_int_array_size(
    struct GrowableIntArray* array
) {
    return array->size;
}


int growable_int_array_get(
    struct GrowableIntArray* array, 
    size_t i
) {
    // You can do precondition checks and crash early if someone
    // tries to out of bounds if you want.
    return array->data[i];
}

void growable_array_cleanup(
    struct GrowableIntArray* array
) {
    free(array->data);
}

#endif