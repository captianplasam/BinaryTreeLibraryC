#include <stdio.h>
#include <string.h>

#include "./../tree.c"
#include "treeProject.h"

int main(int argc, char *argv[]) {
    Node *rootNode, *currentNode;
    int i;
    Path *path;

    if (argc < 2) {
        printf("Invalid amount of arguments\n");
        return 1;
    }
    path = initalisePath();
    rootNode = createRootNode((void *) argv[1]);
    for (i = 2; i < argc; i++) {
        currentNode = createNode(rootNode, (void *) argv[i]);
    }
    printTree(rootNode, 0);
    path = DepthFirstSearch((void *) 3, rootNode);

    return 0;
}

Path *DepthFirstSearch(void *lookingFor, Node *rootNode) {
    Node *currentNode;
    Path *path, *lastPath;
    int exit = 0;

    path = initalisePath();
    lastPath = initalisePath();
    currentNode = rootNode;
    while (exit == 0) {
        printf("current node data: %s\n", (char *) currentNode->data);
        if (currentNode->leftNode == NULL) {
            exit = 1;
        }
        if (lastPath != NULL) {
            lastPath->next = path;
        }
        path->prev = lastPath;
        path->current = currentNode;
        if (currentNode->data == lookingFor) {
            return;
        }
        currentNode = currentNode->leftNode;
        lastPath = path;
    }
    return path;
}