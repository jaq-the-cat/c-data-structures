#ifndef GENERIC_VECTOR_H
#define GENERIC_VECTOR_H

#include <stdio.h>
#include <stdlib.h>

#define GVEC_D(v, x) gpush(&v, (gdata) {.d = x})
#define GVEC_I(v, x) gpush(&v, (gdata) {.n = x})
#define GVEC_L(v, x) gpush(&v, (gdata) {.l = x})
#define GVEC_C(v, x) gpush(&v, (gdata) {.c = x})
#define GVEC_S(v, x) gpush(&v, (gdata) {.str = x})

enum data_type {
    DOUBLE,

    INT,
    LONG,

    CHAR,
    STR,
};

typedef union gdata {
    double d;

    int n;
    long l;

    char c;
    char *str;
} gdata;

typedef struct {
    enum data_type type;
    union gdata *array;
    int length;
    int allocated;
} GVector;

GVector gvector(enum data_type type, const int initial_length);
void greallocate(GVector*);
void gpush(GVector*, gdata);
void gdelete(GVector*);
void print_g_vec(GVector*);

// TESTS

void* test_g_vector_double(double d);
void test_g_vector_print_double(GVector *v);

#endif
