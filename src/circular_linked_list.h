#ifndef C_LINKED_LIST_H
#define C_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_CLLNode {
    int *data;
    struct s_CLLNode *next;
} CLLNode;

typedef struct s_CLinkedList {
    CLLNode *head;
    int len;
} CLinkedList;

CLinkedList linked_list() {
    CLinkedList list = {
        .head = NULL,
        .len = 0,
    };
    return list;
}

CLLNode* make_node(int data) {
    CLLNode *node = (CLLNode*) malloc(sizeof(CLLNode));
    node->data = (int*) malloc(sizeof(int));
    *(node->data) = data;
    node->next = NULL;
    return node;
}

void add_to_list(CLinkedList *list, int data) {
    // empty list
    if (list->len == 0)
        list->head = make_node(data);
    else {
        CLLNode *node;
        for (node = list->head; node->next != NULL; node = node->next); // move to last node
        node->next = make_node(data);
    }
    list->len += 1;
}

void remove_first(CLinkedList *list) {
    free(list->head->data);
    list->head = list->head->next;
}

void remove_node_after(CLLNode *previous) {
    free(previous->next->data);
    previous->next = previous->next->next;
}

void _remove_from_list(int len, CLLNode *node, int i, int c) {
    if (i-1 == c)
        remove_node_after(node);
    else if (i < len)
        _remove_from_list(len, node->next, i, c+1);
}

void remove_from_list(CLinkedList *list, int i) {
    if (list->len == 0) return;
    if (list->len == 1 || i == 0) remove_first(list);
    else _remove_from_list(list->len, list->head, i, 0);
}

void print_list(CLinkedList *list) {
    if (list->len > 0) {
        CLLNode *node;
        for (node = list->head; node != NULL; node = node->next)
            printf("%d\n", *node->data);
    }
}

void _delete_node(CLLNode *node) {
    if (node->next != NULL)
        _delete_node(node->next);
    free(node->data);
    free(node);
}

void delete_list(CLinkedList *list) {
    _delete_node(list->head);
    list->len = 0;
}

#endif
