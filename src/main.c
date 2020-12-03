#include "linked_list.h"

int main() {
    LinkedList list = linked_list();
    add_to_list(&list, 5);
    add_to_list(&list, 10);
    add_to_list(&list, 15);
    add_to_list(&list, 20);
    return 0;
}
