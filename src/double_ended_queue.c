#include "headers/double_ended_queue.h"

DEQueue double_ended_queue() {
    DEQueue queue = {
        .head = NULL,
        .tail = NULL,
        .len = 0,
    };
    return queue;
}

DENode* _deq_make_node(int data) {
    DENode *node = (DENode*) malloc(sizeof(DENode));
    node->data = data;
    return node;
}

void deq_append(DEQueue *q, int data) {
    if (q->head == NULL) {
        q->head = _deq_make_node(data);
        goto end;
    }
    for (DENode *node = q->head;; node = node->next)
        if (node->next == NULL)
            node->next = _deq_make_node(data);
    end:
    q->len++;
}

int deq_pop_head(DEQueue *q) {
    int data = q->head->data;
    DENode *new_head = q->head->next;
    free(q->head);
    q->head = new_head;
    return data;
}

int deq_pop_end(DEQueue *q) {
    DENode *node;
    for (node = q->head; node->next->next != NULL; node = node->next);
    int data = node->next->data;
    free(node->next);
    node->next = NULL;
    return data;
}

int deq_peek_head(DEQueue *q) {
    return q->head->data;
}

int deq_peek_end(DEQueue *q) {
    DENode *node;
    for (node = q->head; node->next != NULL; node = node->next);
    return node->data;
}
