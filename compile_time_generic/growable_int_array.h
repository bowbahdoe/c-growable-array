#ifndef GROWABLE_INT_ARRAY_H
#define GROWABLE_INT_ARRAY_H

#define GROWABLE_ARRAY_STRUCT struct GrowableIntArray
#define GROWABLE_ARRAY_STRUCT_POINTER struct GrowableIntArray*
#define GROWABLE_ARRAY_DATA int
#define GROWABLE_ARRAY_DATA_POINTER int*
#define GROWABLE_ARRAY_EMPTY_FUNCTION_NAME growable_int_array_empty
#define GROWABLE_ARRAY_CLEANUP_FUNCTION_NAME growable_int_array_cleanup
#define GROWABLE_ARRAY_ADD_FUNCTION_NAME growable_int_array_add
#define GROWABLE_ARRAY_SIZE_FUNCTION_NAME growable_int_array_size
#define GROWABLE_ARRAY_GET_FUNCTION_NAME growable_int_array_get

#include "growable_array.h"

#undef GROWABLE_ARRAY_STRUCT
#undef GROWABLE_ARRAY_STRUCT_POINTER
#undef GROWABLE_ARRAY_DATA
#undef GROWABLE_ARRAY_DATA_POINTER
#undef GROWABLE_ARRAY_EMPTY_FUNCTION_NAME
#undef GROWABLE_ARRAY_CLEANUP_FUNCTION_NAME
#undef GROWABLE_ARRAY_ADD_FUNCTION_NAME
#undef GROWABLE_ARRAY_SIZE_FUNCTION_NAME
#undef GROWABLE_ARRAY_GET_FUNCTION_NAME

#endif