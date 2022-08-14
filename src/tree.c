#include "tree.h"

#define COUNT 10

Node *initaliseNode(void) {
    Node *currentNode;

    if (!(currentNode = (Node *) malloc(sizeof(Node)))) {
        printf("Unable to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    currentNode -> leftNode = currentNode -> rightNode = NULL;
    currentNode -> data = 0;

    return currentNode;
}

Node *createRootNode(int data) {
    Node *rootNode;

    rootNode = initaliseNode();
    rootNode->data = data;

    return rootNode;
}

Node *createNode(Node *rootNode, int data) {
    Node *currentNode, *newNode;

    newNode = initaliseNode();
    newNode->data = data;
    currentNode = rootNode;
    while (1) {
        if(currentNode->data > data) {
            if (currentNode->leftNode == NULL) {
                currentNode->leftNode = newNode;
                return currentNode;
            }
            currentNode = currentNode->leftNode;
        } else {
            if (currentNode->rightNode == NULL) {
                currentNode->rightNode = newNode;
                return currentNode;
            }
            currentNode = currentNode->rightNode;
        }
    }
}

void printNode(Node *currentNode) {
    char leftNode[10], rightNode[10]; 
    
    if (currentNode) {
        sprintf(leftNode, "%s", "NULL");
        sprintf(rightNode, "%s", "NULL");
        if (currentNode->leftNode)
            sprintf(leftNode, "%d", currentNode->leftNode->data);
        if (currentNode->rightNode)
            sprintf(rightNode, "%d", currentNode->rightNode->data);
        printf("Current Node: %d, Left Node: %s, Right Node: %s\n", currentNode->data, leftNode, rightNode);
        return;
    }
    printf("Node does not exist\n");
}

void freeNode(Node *currentNode) {
    if (!(currentNode)) {
        return;
    }
    free(currentNode);
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

Path *createPath(Path *lastPath, Node *currentNode) {
    Path *currentPath;

    if (lastPath && currentNode) {
        currentPath = initalisePath();
        lastPath->next = currentPath;
        currentPath->prev = lastPath;
        currentPath->current = currentNode;
        currentPath->next = NULL;
        return currentPath;
    }
    printf("Error path or node enter is NULL\n");

    return NULL;
}

void printPath(Path *path) {
    char buffer[10];

    if (path == NULL) {
        return;
    }
    if (path->next != NULL) {
        sprintf(buffer, "%d", path->current->data);
        printf("%s, ", buffer);  
        printPath(path->next);
    } else {
        sprintf(buffer, "%d", path->current->data);
        printf("%s\n", buffer);
    }
}

void freePath(Path *path) {
    if (!(path)) {
        return;
    }
    freeNode(path->current);
    free(path);
}

void printTree(Node *rootNode, int space) {
    int i;
    char buffer[10];

    if (rootNode == NULL) 
        return;
    space += COUNT;
    printTree(rootNode->rightNode, space);
    printf("\n");
    for (i = COUNT; i < space; i++)
        printf(" ");
    sprintf(buffer, "%d", rootNode->data);
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