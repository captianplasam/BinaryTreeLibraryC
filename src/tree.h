#ifndef _TREE_H
#define _TREE_H

typedef struct Node {
    void *data;
    struct Node *leftNode;
    struct Node *rightNode;
    struct Node *prevNode;
} Node;

typedef struct Path {
    struct Path *prev;
    Node *current;
    struct Path *next;
} Path;

Node *initaliseNode(void);
Path *initalisePath(void);
void freeNode(Node *currentNode);
void freePath(Path *path);
Node *createNode(Node *rootNode, void *data);
Node *createRootNode(void *data);
void printTree(Node *rootNode, int space);
void freeTree(Node *rootNode);
void printPath(Path *path);

#endif
