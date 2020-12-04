#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
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

LLNode* make_node(int data) {
    LLNode *node = (LLNode*) malloc(sizeof(LLNode));
    node->data = (int*) malloc(sizeof(int));
    *(node->data) = data;
    node->next = NULL;
    return node;
}

void add_to_list(LinkedList *list, int data) {
    // empty list
    if (list->len == 0)
        list->head = make_node(data);
    else {
        LLNode *node;
        for (node = list->head; node->next != NULL; node = node->next); // move to last node
        node->next = make_node(data);
    }
    list->len += 1;
}

void remove_first(LinkedList *list) {
    free(list->head->data);
    list->head = list->head->next;
}

void remove_node_after(LLNode *previous) {
    free(previous->next->data);
    previous->next = previous->next->next;
}

void _remove_from_list(int len, LLNode *node, int i, int c) {
    if (i-1 == c)
        remove_node_after(node);
    else if (i < len)
        _remove_from_list(len, node->next, i, c+1);
}

void remove_from_list(LinkedList *list, int i) {
    if (list->len == 0) return;
    if (list->len == 1 || i == 0) remove_first(list);
    else _remove_from_list(list->len, list->head, i, 0);
}

void print_list(LinkedList *list) {
    if (list->len > 0) {
        LLNode *node;
        printf("{ ");
        for (node = list->head; node->next != NULL; node = node->next)
            printf("%d -> ", *node->data);
        printf("%d }\n", *node->data);
    }
}

void _delete_node(LLNode *node) {
    if (node->next != NULL)
        _delete_node(node->next);
    free(node->data);
    free(node);
}

void delete_list(LinkedList *list) {
    _delete_node(list->head);
    list->len = 0;
}

#endif
