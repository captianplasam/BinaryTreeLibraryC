#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"

#define COUNT 10

Node *initaliseNode(void) {
    Node *currentNode;

    if (!(currentNode = (Node *) malloc(sizeof(Node)))) {
        printf("Unable to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    currentNode -> leftNode = currentNode -> rightNode = currentNode -> data = currentNode -> prevNode = NULL;

    return currentNode;
}

Path *initalisePath(void) {
    Path *path;

    if (!(path = (Path *) malloc(sizeof(Path)))) {
        printf("Unable to allocate path memory\n");
        exit(EXIT_FAILURE);
    }
    path->current = initaliseNode();
    path->prev = path->next = NULL;

    return path;
}

void freeNode(Node *currentNode) {
    if (!(currentNode)) {
        return;
    }
    free(currentNode);
}

void freePath(Path *path) {
    if (!(path)) {
        return;
    }
    freeNode(path->current);
    free(path);
}

Node *createNode(Node *rootNode, void *data) {
    Node *currentNode, *prevNode, *newNode;

    newNode = initaliseNode();
    newNode->data = data;
    currentNode = rootNode;
    while (1) {
        if(strcmp((char *) currentNode->data, (char *) data) > 0) {
            if (currentNode->leftNode == NULL) {
                currentNode->leftNode = newNode;
                currentNode->prevNode = prevNode;
                return currentNode;
            }
            prevNode = currentNode;
            currentNode = currentNode->leftNode;
        } else {
            if (currentNode->rightNode == NULL) {
                currentNode->rightNode = newNode;
                return currentNode;
            }
            prevNode = currentNode;
            currentNode = currentNode->rightNode;
        }
    }
}

Node *createRootNode(void *data) {
    Node *rootNode;

    rootNode = initaliseNode();
    rootNode->data = data;

    return rootNode;
}

void printTree(Node *rootNode, int space) {
    int i;

    if (rootNode == NULL) 
        return;
    space += COUNT;
    printTree(rootNode->rightNode, space);
    printf("\n");
    for (i = COUNT; i < space; i++)
        printf(" ");
    printf("%s\n", (char *) rootNode->data);
    printTree(rootNode->leftNode, space);
}

void freeTree(Node *rootNode) {
    if (rootNode == NULL) 
        return;
    freeTree(rootNode->rightNode);
    freeTree(rootNode->leftNode);
    freeNode(rootNode);
}