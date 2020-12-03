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
    Vector v = {
        .array = a,
        .length = 0,
        .allocated = initial_length,
    };
    return v;
}

void set(Vector *v, const int i, const int d) {
    if (i >= 0 && i < v->length)
        v->array[i] = d;
}

void rm(Vector *v, const int i) {
    if (i >= 0 && i < v->length) {
        for (int j=i; j<v->length-1; j++)
            v->array[j] = v->array[j+1];
        v->length--;
    }
}

int get(const Vector *v, const int i) {
    return v->array[i];
}

void _fix(Vector *v) {
    if (v->length >= v->allocated) {
        v->array = (int*) realloc(v->array, sizeof(int)*(v->allocated+EXTRA_SIZE));
        //int *na = (int*) malloc(sizeof(int)*v->allocated+EXTRA_SIZE);
        //for (int i=0; i<v->length; i++)
            //na[i] = v->array[i];
        //free(v->array);
        //v->array = na;
    }
}

void push(Vector *v, const int d) {
    _fix(v);
    v->array[v->length] = d;
    v->length++;
    _fix(v);
}

void print_vec(const Vector *v) {
    printf("{ ");
    for (int i=0; i<v->length-1; i++)
        printf("%d, ", v->array[i]);
    printf("%d", v->array[v->length-1]);
    printf(" }\n");
}

void print_vec_addr(const Vector *v) {
    printf("(%lu) {\n", sizeof(int));
    for (int i=0; i<v->allocated-1; i++)
        printf("  %p,\n", &v->array[i]);
    printf("  %p\n", &v->array[v->allocated-1]);
    printf("}\n");
}

void delete_vec(Vector *v) {
    free(v->array);
}

#endif
