#include "headers/linked_list.h"
#include "headers/vector.h"
#include "headers/binary_tree.h"
#include "headers/circular_linked_list.h"
#include "headers/doubly_linked_list.h"
#include "headers/generic_vector.h"

void t_g_vector() {
    GVector v = gvector(10, sizeof(double));
    delete_gvec(&v);
}

void t_doubly_linked_list() {
    DLinkedList list = d_linked_list();
    print_d_list(&list);

    add_to_d_list(&list, 5);
    print_d_list(&list);

    add_to_d_list(&list, 10);
    print_d_list(&list);

    add_to_d_list(&list, 15);
    print_d_list(&list);

    add_to_d_list(&list, 20);
    print_d_list(&list);

    delete_d_list(&list);
}

void t_circular_linked_list() {
    CLinkedList list = c_linked_list();
    print_c_list(&list);

    add_to_c_list(&list, 5);
    print_c_list(&list);

    add_to_c_list(&list, 10);
    print_c_list(&list);

    add_to_c_list(&list, 15);
    print_c_list(&list);

    add_to_c_list(&list, 20);
    print_c_list(&list);

    remove_from_c_list(&list, 4);
    delete_c_list(&list);
}

void t_binary_tree() {
    BinaryTree tree = binary_tree(50);
    add_to_tree(&tree, 30);
    add_to_tree(&tree, 20);
    add_to_tree(&tree, 40);
    add_to_tree(&tree, 90);
    add_to_tree(&tree, 60);
    add_to_tree(&tree, 120);
    print_tree(&tree);
}

void t_vector() {
    Vector v  = vector(3);
    push(&v, 0);
    rm(&v, 0);
    for (int i=0; i<10; i++)
        push(&v, i);
    print_vec(&v);
    insert(&v, 2, -1);
    print_vec(&v);
    delete_vec(&v);
}

void t_linked_list() {
    LinkedList list = linked_list();
    add_to_list(&list, 5);
    add_to_list(&list, 10);
    add_to_list(&list, 15);
    add_to_list(&list, 20);
    print_list(&list);

    remove_from_list(&list, 0);
    print_list(&list);

    remove_from_list(&list, 2);
    print_list(&list);

    remove_from_list(&list, 1);
    print_list(&list);

    remove_from_list(&list, 0);
    print_list(&list);

    delete_list(&list);
}

int main() {
    t_g_vector();
    return 0;
}
