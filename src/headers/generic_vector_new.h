#ifndef GENERIC_VECTOR_H
#define GENERIC_VECTOR_H

#include <stdio.h>
#include <stdlib.h>

#define GENERIC_VEC_INIT(TYPE) \
    void* generic_ptr_##TYPE(TYPE value) {\
        TYPE *ptr = (TYPE*) malloc(sizeof(TYPE));\
        *ptr = value;\
        return (void*) ptr;\
    }

typedef struct {
    void **array;
    int length;
    int allocated;
} GVector;

GVector gvector(const int initial_length);
void greallocate(GVector *v);
void gpush(GVector *v, void *d);
void delete_gvec(GVector *v);

// TESTS
void* test_g_vector_double(double d);
void test_g_vector_print_double(GVector *v);

#endif
