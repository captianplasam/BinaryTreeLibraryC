#include "tree.h"

#define COUNT 10

Node *initaliseNode(void) {
    Node *currentNode;

    if (!(currentNode = (Node *) malloc(sizeof(Node)))) {
        printf("Unable to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    currentNode -> leftNode = currentNode -> rightNode = currentNode -> prevNode = NULL;
    currentNode -> data = 0;

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

Node *createNode(Node *rootNode, int data) {
    Node *currentNode, *prevNode, *newNode;

    newNode = initaliseNode();
    newNode->data = data;
    currentNode = rootNode;
    while (1) {
        if(currentNode->data > data) {
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

Node *createRootNode(int data) {
    Node *rootNode;

    rootNode = initaliseNode();
    rootNode->data = data;

    return rootNode;
}

void printTree(Node *rootNode, int space) {
    int i;
    char buffer[100];

    if (rootNode == NULL) 
        return;
    space += COUNT;
    printTree(rootNode->rightNode, space);
    printf("\n");
    for (i = COUNT; i < space; i++)
        printf(" ");
    itoa(rootNode->data, buffer, 10);
    printf("%s\n", buffer);
    printTree(rootNode->leftNode, space);
}

void freeTree(Node *rootNode) {
    if (rootNode == NULL) 
        return;
    freeTree(rootNode->rightNode);
    freeTree(rootNode->leftNode);
    freeNode(rootNode);
}

void printPath(Path *path) {
    char buffer[100];
    if (path == NULL) {
        return;
    }
    if (path->next != NULL) {
        itoa(path->current->data, buffer, 10);
        printf("%s, ", buffer);  
        printPath(path->next);
    } else {
        itoa(path->current->data, buffer, 10);
        printf("%s\n", buffer);
    }
}