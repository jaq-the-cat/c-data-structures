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

CLinkedList c_linked_list();

void add_to_c_list(CLinkedList *list, int data);
void remove_from_c_list(CLinkedList *list, int i);
void print_c_list(CLinkedList *list);
void delete_c_list(CLinkedList *list);

#endif
