#include "vector.h"

Vector vector(const int initial_length) {
    int *a = (int*) malloc(sizeof(int)*initial_length);
    Vector v = {
        .array = a,
        .length = 0,
        .allocated = initial_length,
    };
    return v;
}

void set(Vector *v, int i, int d) {
    if (i >= 0 && i < v->length)
        v->array[i] = d;
}

void rm(Vector *v, int i) {
    if (i >= 0 && i < v->length) {
        for (int j=i; j<v->length-1; j++)
            v->array[j] = v->array[j+1];
        v->length--;
    }
}

int get(const Vector *v, int i) {
    return v->array[i];
}

void reallocate(Vector *v) {
    v->allocated *= 1.5;
    v->array = realloc(v->array, sizeof(int)*v->allocated);

}

void _fix(Vector *v) {
    if (v->length >= v->allocated)
        reallocate(v);
}

void insert(Vector *v, int i, int d) {
    if (0 > i || v->length < i) return;
    if (v->length+1 > v->allocated)
        reallocate(v);
    for (int j=v->length; j>=i; j--)
        v->array[j] = v->array[j-1];
    v->array[i] = d;
    v->length++;

}

void push(Vector *v, int d) {
    _fix(v);

    v->array[v->length] = d;
    v->length++;

    _fix(v);
}

void print_vec(const Vector *v) {
    printf("{ ");

    int i=0;
    for (i=0; i<v->length-1; i++)
        printf("%d, ", v->array[i]);
    printf("%d", v->array[i]);

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
