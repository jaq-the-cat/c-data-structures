#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_Vector {
    int *first;
    int length;
} Vector;

Vector vector(int length) {
    Vector v = Vector {
        .first = (int*) malloc(sizeof(int)),
        .length = length,
    };
    int *e;
    for (int i=2; i < length; i++) {
        e = (int*) malloc(sizeof(int)*i);
        e = 0;
    }
    return v;
}

void set_at(Vector *v, int i, int d) {
}

#endif
