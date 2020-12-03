#include "linked_list.h"
#include "vector.h"

void t_vector() {
    Vector v  = vector(3);
    push(&v, 1);
    push(&v, 2);
    push(&v, 3);
    push(&v, 4);
    print_vec(&v);
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
