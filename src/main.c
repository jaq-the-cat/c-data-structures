#include "linked_list.h"
#include "vector.h"

void t_vector() {
    Vector v  = vector(2);
    push(&v, 0);
    rm(&v, 0);
    for (int i=0; i<10; i++)
        push(&v, i);
    print_vec(&v);
    /*print_vec_addr(&v);*/
    delete_vec(&v);
}

void t_linked_list() {
    LinkedList list = linked_list();
    add_to_list(&list, 5);
    add_to_list(&list, 10);
    add_to_list(&list, 15);
    add_to_list(&list, 20);
    print_list(&list);

    printf("----------------\n");

    remove_from_list(&list, 0);
    print_list(&list);

    printf("----------------\n");

    remove_from_list(&list, 2);
    print_list(&list);

    printf("----------------\n");

    remove_from_list(&list, 1);
    print_list(&list);

    printf("----------------\n");
    delete_list(&list);
}

int main() {
    t_vector();
    return 0;
}
