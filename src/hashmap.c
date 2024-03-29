#include "hashmap.h"

#define COLLISIONS 5

// Linked list stuff
hm_LinkedList _hm_linked_list() { hm_LinkedList list = { NULL, 0, }; return list; }
hm_LLNode* _hm_make_node(char *key, int data) {
    hm_LLNode *node = (hm_LLNode*) malloc(sizeof(hm_LLNode));
    node->data = data;
    strcpy(node->key, key);
    node->next = NULL;
    return node;
}

void _hm_add_to_list(hm_LinkedList *list, char *key, int data) {
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

HashMap hash_map(const int initial_length) {
    HashMap map = {
        .array = (hm_LinkedList*) malloc(sizeof(hm_LinkedList)*initial_length),
        .allocated = initial_length,
    };
    return map;
}

void hm_reallocate(HashMap *map) {
    map->allocated *= 1.5;
    map->array = (hm_LinkedList*) realloc(map->array, sizeof(hm_LinkedList) * map->allocated);
}

void hm_insert(HashMap *map, char *key, int value) {
    int index = hash(key, 0) % map->allocated;

    // replace if present
    for (hm_LLNode *node = map->array[index].head; node != NULL; node = node->next)
        if (!strcmp(node->key, key)) {
            node->data = value;
            return;
        }

    // if not present, append
    _hm_add_to_list(&map->array[index], key, value);
    if (map->array[index].len > COLLISIONS) hm_reallocate(map);
}

int* hm_get(HashMap *map, char *key) {
    int index = hash(key, 0) % map->allocated;

    for (hm_LLNode *node = map->array[index].head; node != NULL; node = node->next) {
        if (!strcmp(node->key, key))
            return &node->data;
    }
    return NULL;
}

void hm_delete(HashMap *map) {
    for (int i=0; i<map->allocated; i++) {
        for (hm_LLNode *node = map->array[i].head; node != NULL;) {
            hm_LLNode *next = node->next;
            free(node);
            node = next;
        }
    }
    free(map->array);
    map->array = NULL;
}
