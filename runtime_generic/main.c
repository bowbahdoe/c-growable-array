#include "growable_array.h"
#include <stdio.h>

int main()
{
    struct GrowableArray numbers 
        = growable_array_empty();
        
    int a = 6;
    int b = 4;
    int c = 7;
    growable_array_add(&numbers, &a);
    growable_array_add(&numbers, &b);
    growable_array_add(&numbers, &c);

    
    size_t i = 0;
    while (i < growable_array_size(&numbers)) {
        printf("%d\n", *((int*) growable_array_get(&numbers, i)));
        i++;
    }
    return 0;
}