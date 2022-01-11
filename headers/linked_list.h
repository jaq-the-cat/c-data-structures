#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_LLNode {
    int data;
    struct s_LLNode *next;
} LLNode;

typedef struct s_LinkedList {
    LLNode *head;
    int len;
} LinkedList;

LinkedList linked_list();

LLNode* make_node(int data);
void add_to_list(LinkedList *list, int data);
void remove_only(LinkedList *list);
void remove_first(LinkedList *list);
void remove_node_after(LLNode *previous);
void remove_from_list(LinkedList *list, int i);
void print_list(LinkedList *list);
void delete_list(LinkedList *list);

#endif
