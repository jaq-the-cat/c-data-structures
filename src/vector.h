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
    for (int i=2; i < length; i++) {
        malloc(sizeof(int)*i);
    }
    return v;
}

#endif
