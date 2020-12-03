#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>

typedef struct s_LLNode {
    int *data;
    struct s_LLNode *next;
} LLNode;

typedef struct s_LinkedList {
    LLNode *head;
    int len;
} LinkedList;

LinkedList linked_list() {
    LinkedList list = {
        .head = NULL,
        .len = 0,
    };
    return list;
}

void add_to_list(LinkedList *list, int data) {
    LLNode *node;
    for (node = list->head; node != NULL; node = node->next); // move to last node
    node = (LLNode*) malloc(sizeof(LLNode));
    node->data = (int*) malloc(sizeof(data));
    node->next = NULL;
}

void delete_list(LinkedList *list) {
}

void _delete_node(LLNode *node) {
    if (node->next != NULL)
        _delete_node(node->next);
    free(node->data);
    free(node);
}

#endif
