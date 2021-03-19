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

DLinkedList d_linked_list();
void add_to_d_list(DLinkedList *list, int data);
void print_d_list(DLinkedList *list);
void delete_d_list(DLinkedList *list);

#endif
