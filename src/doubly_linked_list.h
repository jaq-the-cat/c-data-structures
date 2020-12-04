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

#endif
