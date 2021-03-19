#ifndef GENERIC_VECTOR_H
#define GENERIC_VECTOR_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void **array;
    int length;
    int allocated;
} GVector;

void** pointer_to(GVector *v, int i);
GVector gvector(const int initial_length);
void greallocate(GVector *v);
void gpush(GVector *v, void *d);
void delete_gvec(GVector *v);

// TESTS

void* test_g_vector_double(double d);
void test_g_vector_print_double(GVector *v);

#endif
