#ifndef _TREE_H
#define _TREE_H

typedef struct Node {
    void *data;
    struct Node *leftNode;
    struct Node *rightNode;
    struct Node *prevNode;
} Node;

Node *initaliseNode(void);
void freeNode(Node *currentNode);
Node *createNode(Node *rootNode, void *data);
Node *createRootNode(void *data);
void printTree(Node *rootNode, int space);
void freeTree(Node *rootNode);

#endif
