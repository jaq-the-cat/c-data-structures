#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_Vector {
    int *array;
    int length;
} Vector;

Vector vector(const int length) {
    int a[length];
    Vector v = Vector {
        .array = a,
        .length = length,
    };
    return v;
}

void set_at(Vector *v, const int i, const int d) {
    *(v->array + i) = d;
}

void print_vec(const Vector *v) {

}

#endif
