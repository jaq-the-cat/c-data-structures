#ifndef C_LINKED_LIST_H
#define C_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_CLLNode {
    int data;
    struct s_CLLNode *next;
} CLLNode;

typedef struct s_CLinkedList {
    CLLNode *tail;
    int len;
} CLinkedList;

CLinkedList c_linked_list() {
    CLinkedList list = {
        .tail = NULL,
        .len = 0,
    };
    return list;
}

CLLNode* make_c_node(int data) {
    CLLNode *node = (CLLNode*) malloc(sizeof(CLLNode));
    node->data = data;
    node->next = NULL;
    return node;
}

void add_to_c_list(CLinkedList *list, int data) {
    // empty list
    if (list->len == 0) {
        list->tail = make_c_node(data);
        list->tail->next = list->tail;
    }
    else {
        CLLNode *head = list->tail->next;
        list->tail->next = make_c_node(data);
        list->tail->next->next = head;
        list->tail = list->tail->next;
    }
    list->len += 1;
}

void remove_from_c_list(CLinkedList *list, int i) {
    CLLNode *node = list->tail->next;
    for (int c=0; c<i-1; c++, node = node->next); // move to correct index
    CLLNode *next = node->next->next;
    free(node->next);
    node->next = next;
    list->len--;
}

void print_c_list(CLinkedList *list) {
    if (list->len > 0) {
        CLLNode *node = list->tail->next;
        printf("{ ");
        do {
            printf("%d -> ", node->data);
            node = node->next;
        } while (node != list->tail->next);
        printf("(%d)  }\n", list->tail->next->data);
    } else {
        printf("{}\n");
    }
}

void _delete_c_node(CLinkedList *list, CLLNode *node) {
    if (node->next != list->tail)
        _delete_c_node(list, node->next);
    node->next = NULL;
    free(node);
}

void delete_c_list(CLinkedList *list) {
    _delete_c_node(list, list->tail);
    list->len = 0;
}

#endif
