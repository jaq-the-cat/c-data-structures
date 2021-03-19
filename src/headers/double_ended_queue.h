#ifndef DOUBLE_ENDED_QUEUE
#define DOUBLE_ENDED_QUEUE

#include <stdio.h>
#include <stdlib.h>

typedef struct s_DENode {
    int data;
    struct s_DENode *next;
} DENode;

typedef struct s_DEQueue {
    DENode *head;
    DENode *tail;
    int len;
} DEQueue;

DEQueue double_ended_queue();
void deq_append(DEQueue *q, int data);
int deq_pop_head(DEQueue *q);
int deq_pop_end(DEQueue *q);
int deq_peek_head(DEQueue *q);
int deq_peek_end(DEQueue *q);


#endif
