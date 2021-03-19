#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLLISIONS 5

// Linked list stuff
typedef struct s_hm_LLNode { int data; struct s_hm_LLNode *next; char key[100]; } hm_LLNode;
typedef struct s_hm_LinkedList { hm_LLNode *head; int len; } hm_LinkedList;
hm_LinkedList _hm_linked_list() { hm_LinkedList list = { NULL, 0, }; return list; }
hm_LLNode* _hm_make_node(char *key, int data) {
    hm_LLNode *node = (hm_LLNode*) malloc(sizeof(hm_LLNode));
    node->data = data;
    strcpy(node->key, key);
    node->next = NULL;
    return node;
}

void _hm_add_to_list(hm_LinkedList *list, char *key, int data) {
    int a;
    if (list->len == 0)
        list->head = _hm_make_node(key, data);
    else {
        hm_LLNode *node;
        for (node = list->head; node->next != NULL; node = node->next);
        node->next = _hm_make_node(key, data);
    }
    list->len++;
}
void _hm_remove_from_list(int len, hm_LLNode *node, int i, int c) { if (i-1 == c) { hm_LLNode *next = node->next->next; free(node->next); node->next = next; } else if (i < len) _hm_remove_from_list(len, node->next, i, c+1); }
void hm_remove_from_list(hm_LinkedList *list, int i) { if (list->len == 0) return; if (list->len == 1) { free(list->head); list->head = NULL; } else if (i == 0) { hm_LLNode *next = list->head->next; free(list->head); list->head = next; } else { _hm_remove_from_list(list->len, list->head, i, 0); } list->len--;}

int hash(char str[], int seed) {
    int hval = (seed == 0) ? 0x811c9dc5 : seed;

    for (int i=0; i<strlen(str); i++) {
        hval ^= str[i];
        hval = (hval << 1) + (hval << 4) + (hval << 7) + (hval << 8) + (hval << 24);
    }

    return hval > 0 ? hval : -hval;
}

typedef struct HashMap {
    hm_LinkedList *list;
    int allocated;
} HashMap;

HashMap hash_map(const int initial_length) {
    HashMap map = {
        .list = (hm_LinkedList*) malloc(sizeof(hm_LinkedList)*initial_length),
        .allocated = initial_length,
    };
    return map;
}

void hm_reallocate(HashMap *map) {
    map->allocated *= 1.5;
    map->list = (hm_LinkedList*) realloc(map->list, sizeof(hm_LinkedList) * map->allocated);
}

void hm_insert(HashMap *map, char *key, int value) {
    int index = hash(key, 0) % map->allocated;

    // replace if present
    for (hm_LLNode *node = map->list[index].head; node != NULL; node = node->next)
        if (!strcmp(node->key, key)) {
            node->data = value;
            return;
        }

    // if not present, append
    _hm_add_to_list(&map->list[index], key, value);
    if (map->list[index].len > COLLISIONS) hm_reallocate(map);
}

int* hm_get(HashMap *map, char *key) {
    int index = hash(key, 0) % map->allocated;

    for (hm_LLNode *node = map->list[index].head; node != NULL; node = node->next) {
        if (!strcmp(node->key, key))
            return &node->data;
    }
    return NULL;
}

void hm_delete(HashMap *map) {
    free(map->list);
}

#endif
