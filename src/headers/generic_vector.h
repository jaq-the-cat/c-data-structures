#ifndef GENERIC_VECTOR_H
#define GENERIC_VECTOR_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void *array;
    int data_size;
    int length;
    int allocated;
} GVector;

GVector gvector(const int initial_length, int data_size) {
    return (GVector) {
        .array = (void*) malloc(data_size*initial_length),
        .length = 0,
        .allocated = initial_length,
    };
}

#endif
