#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linked list stuff
typedef struct s_hm_LLNode { int data; struct s_hm_LLNode *next; char key[100]; } hm_LLNode;
typedef struct s_hm_LinkedList { hm_LLNode *head; int len; } hm_LinkedList;

typedef struct HashMap {
    hm_LinkedList *array;
    int allocated;
} HashMap;

HashMap hash_map(const int initial_length);
void hm_insert(HashMap *map, char *key, int value);
int* hm_get(HashMap *map, char *key);
void hm_delete(HashMap *map);

#endif
