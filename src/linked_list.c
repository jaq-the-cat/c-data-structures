#include "linked_list.h"

LinkedList linked_list() {
    LinkedList list = {
        .head = NULL,
        .len = 0,
    };
    return list;
}

LLNode* make_node(int data) {
    LLNode *node = (LLNode*) malloc(sizeof(LLNode));
    node->data = data;
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
    list->len++;
}

void remove_only(LinkedList *list) {
    free(list->head);
    list->head = NULL;
}

void remove_first(LinkedList *list) {
    LLNode *next = list->head->next;
    free(list->head);
    list->head = next;
}

void remove_node_after(LLNode *previous) {
    LLNode *next = previous->next->next;
    free(previous->next);
    previous->next = next;
}

void _remove_from_list(int len, LLNode *node, int i, int c) {
    if (i-1 == c)
        remove_node_after(node);
    else if (i < len)
        _remove_from_list(len, node->next, i, c+1);
}

void remove_from_list(LinkedList *list, int i) {
    if (list->len == 0) return;
    if (list->len == 1) remove_only(list);
    else if (i == 0) remove_first(list);
    else _remove_from_list(list->len, list->head, i, 0);
    list->len--;
}

void print_list(LinkedList *list) {
    if (list->len > 0) {
        LLNode *node;
        printf("{ ");
        for (node = list->head; node->next != NULL; node = node->next)
            printf("%d -> ", node->data);
        printf("%d }\n", node->data);
    } else {
        printf("{}\n");
    }
}

void _delete_node(LLNode *node) {
    if (node->next != NULL)
        _delete_node(node->next);
    free(node);
}

void delete_list(LinkedList *list) {
    if (list->len > 0) {
        _delete_node(list->head);
        list->len = 0;
    }
}
