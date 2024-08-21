#include "growable_int_array.h"
#include <stdio.h>

int main()
{
    struct GrowableIntArray numbers = growable_int_array_empty();

    growable_int_array_add(&numbers, 6);
    growable_int_array_add(&numbers, 4);
    growable_int_array_add(&numbers, 7);

    size_t i = 0;
    while (i < growable_int_array_size(&numbers))
    {
        printf("%d\n", growable_int_array_get(&numbers, i));
        i++;
    }

    growable_array_cleanup(&numbers);

    return 0;
}