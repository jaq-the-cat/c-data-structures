#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_DLLNode {
    int data;
    struct s_DLLNode *prev;
    struct s_DLLNode *next;
} DLLNode;

typedef struct s_DLinkedList {
    DLLNode *head;
    int len;
} DLinkedList;

DLinkedList d_linked_list() {
    DLinkedList list = {
        .head = NULL,
        .len = 0,
    };
    return list;
}

DLLNode* make_d_node(DLLNode *prev, int data) {
    DLLNode *node = (DLLNode*) malloc(sizeof(DLLNode));
    node->data = data;
    node->prev = prev;
    node->next = NULL;
    return node;
}

void add_to_d_list(DLinkedList *list, int data) {
    if (list->len == 0)
        list->head = make_d_node(NULL, data);
    else {
        DLLNode *node;
        for (node = list->head; node->next != NULL; node = node->next); // move to last node
        node->next = make_d_node(node, data);
    }
}

void print_d_list(DLinkedList *list) {
    if (list->len > 0) {
        DLLNode *node;
        printf("{ ");
        for (node = list->head; node->next != NULL; node = node->next)
            printf("%d <-> ", node->data);
        printf("%d }\n", node->data);
    } else {
        printf("{}\n");
    }
}

void _delete_node(DLLNode *node) {
    if (node->next != NULL)
        _delete_node(node->next);
    node->next = NULL;
    free(node);
}

void delete_list(DLinkedList *list) {
    if (list->len > 0) {
        _delete_node(list->head);
        list->len = 0;
    }
}

#endif
