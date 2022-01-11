#include "generic_vector.h"

GVector gvector(enum data_type type, const int initial_length) {
    return (GVector) {
        type,
        malloc(sizeof(gdata)*initial_length),
        0,
        initial_length
    };
}

void greallocate(GVector* v) {
    v->allocated *= 1.5;
    v->array = realloc(v->array, sizeof(gdata)*v->allocated);
}

void gpush(GVector* v, gdata d) {
    if (v->length == v->allocated) {
        greallocate(v);
    }
    v->array[v->length] = d;
    v->length++;
}

void gdelete(GVector* v) {
    free(v->array);
}

void print_vec_element(gdata d, enum data_type t) {
    switch (t) {
        case DOUBLE:
            printf("%lf", d.d);
            break;
        case INT:
            printf("%d", d.n);
            break;
        case LONG:
            printf("%ld", d.l);
            break;
        case CHAR:
            printf("%c", d.c);
            break;
        case STR:
            printf("%s", d.str);
            break;
    }
}

void print_g_vec(GVector *v) {
    printf("{ ");
        int i;
        for (i=0; i<v->length-1; i++) {
            print_vec_element(v->array[i], v->type);
            printf(", ");
        }
        print_vec_element(v->array[i], v->type);
    printf("}");
}
