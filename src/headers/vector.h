#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_Vector {
    int *array;
    int length;
    int allocated;
} Vector;

Vector vector(const int initial_length);
void set(Vector *v, int i, int d);
void rm(Vector *v, int i);
int get(const Vector *v, int i);
void insert(Vector *v, int i, int d);
void push(Vector *v, int d);
void print_vec(const Vector *v);
void print_vec_addr(const Vector *v);
void delete_vec(Vector *v);

#endif
