#ifndef GENERIC_VECTOR_H
#define GENERIC_VECTOR_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void **array;
    int data_size;
    int length;
    int allocated;
} GVector;

GVector gvector(const int initial_length, int data_size) {
    return (GVector) {
        .array = (void**) malloc(data_size*initial_length),
        .length = 0,
        .allocated = initial_length,
    };
}

void greallocate(GVector *v) {
    v->allocated *= 1.5;
    v->array = (void**) realloc(v->array, sizeof(int)*v->allocated);

}

void _g_fix(GVector *v) {
    if (v->length >= v->allocated)
        greallocate(v);
}

void gpush(GVector *v, void *d) {
    _g_fix(v);
    void *ptr = (void*) ((char*) v->array + v->length * v->data_size);
    ptr = (char*) d;
    v->length++;
    _g_fix(v);
}

void delete_gvec(GVector *v) {
    free(v->array);
}

// TESTS

void* test_g_vector_double(double d) {
    double *dptr = (double*) malloc(sizeof(double));
    *dptr = d;
    return (void*) dptr;
}

void test_g_vector_print_double(GVector *v) {
    printf("{ ");

    for (int i=0; i<v->length-1; i++)
        printf("%lf, ", *(double*) v->array[i]);
    printf("%lf", *(double*) v->array[v->length-1]);

    printf(" }\n");
}

#endif
