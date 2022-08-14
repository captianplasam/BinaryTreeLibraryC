#ifndef _TREE_H
#define _TREE_H

// Libraries included
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// custom structs
typedef struct Node {
    int data;
    struct Node *leftNode;
    struct Node *rightNode;
} Node;

typedef struct Path {
    struct Path *prev;
    Node *current;
    struct Path *next;
} Path;

// method declarations
Node *initaliseNode(void);
Node *createRootNode(int data);
Node *createNode(Node *rootNode, int data);
void printNode(Node *currentNode);
void freeNode(Node *currentNode);
Path *initalisePath(void);
Path *createPath(Path *lastPath, Node *currentNode);
void printPath(Path *path);
void freePath(Path *path);
void printTree(Node *rootNode, int space);
void freeTree(Node *rootNode);

#endif
