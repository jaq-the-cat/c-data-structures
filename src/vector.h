#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>

#ifndef EXTRA_SIZE
#define EXTRA_SIZE 50
#endif

typedef struct s_Vector {
    int *array;
    int length;
    int allocated;
} Vector;

Vector vector(const int initial_length) {
    int *a = (int*) malloc(sizeof(int)*initial_length);
    Vector v = Vector {
        .array = a,
        .length = 0,
        .allocated = initial_length,
    };
    return v;
}

void set_at(Vector *v, const int i, const int d) {
    if (i < v->length)
        v->array[i] = d;
}

void push(Vector *v, const int d) {
    if (v->length >= v->allocated) {
        int *na = (int*) malloc(sizeof(int)*v->allocated+EXTRA_SIZE);
        for (int i=0; i<v->length; i++)
            na[i] = v->array[i];
        free(v->array);
        v->array = na;
    }
    v->array[v->length] = d;
    v->length += 1;
}

void print_vec(const Vector *v) {
    printf("[ ");
    for (int i=0; i<v->length; i++)
        printf("%d ", v->array[i]);
    printf("]\n");
}

#endif
