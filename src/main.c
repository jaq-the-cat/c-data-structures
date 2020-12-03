#include "linked_list.h"

int main() {
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
    return 0;
}
