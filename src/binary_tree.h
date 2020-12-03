#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_BinaryTree {
    int data;
    struct s_BinaryTree *left;
    struct s_BinaryTree *right;
} BinaryTree;

BinaryTree binary_tree(int data) {
    BinaryTree tree = {
        .data = data,
        .left = NULL,
        .right = NULL,
    };
    return tree;
}

void add_to_tree(BinaryTree *tree, int data) {
    if (data <= tree->data) {
        if (tree->left == NULL) {
            tree->left = (BinaryTree*) malloc(sizeof(BinaryTree));
            *tree->left = binary_tree(data);
        } else
            add_to_tree(tree->left, data);
    } else {
        if (tree->right == NULL) {
            tree->right = (BinaryTree*) malloc(sizeof(BinaryTree));
            *tree->right = binary_tree(data);
        } else
            add_to_tree(tree->right, data);
    }
}

void remove_all(BinaryTree *tree, int data) {
    if (data == tree->data) {
    }
    if (tree->left != NULL)
        remove_all(tree->left, data);
    if (tree->right != NULL)
        remove_all(tree->right, data);
}

void print_tree(BinaryTree *tree) {
    printf("%d[", tree->data);
    if (tree->left != NULL) {
        printf(" ");
        print_tree(tree->left);
        printf(", ");
    }
    if (tree->right != NULL) {
        print_tree(tree->right);
        printf(" ");
    }
    printf("]");
}

#endif
