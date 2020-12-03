#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_BinaryTree {
    int *data;
    struct s_BinaryTree *left;
    struct s_BinaryTree *right;
} BinaryTree;

BinaryTree binary_tree() {
    BinaryTree tree = {
        .data = NULL,
        .left = NULL,
        .right = NULL,
    };
    return tree;
}

#endif
