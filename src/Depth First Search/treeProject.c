#include <stdio.h>
#include <string.h>

#include "./../tree.c"
#include "treeProject.h"

int main(int argc, char *argv[]) {
    Node *rootNode, *currentNode;
    int i;
    Path *path, *lastPath, *tempPath;

    if (argc < 2) {
        printf("Invalid amount of arguments\n");
        return 1;
    }
    rootNode = createRootNode((void *) argv[1]);
    for (i = 2; i < argc; i++) {
        currentNode = createNode(rootNode, (void *) argv[i]);
    }
    printTree(rootNode, 0);
    path = DepthFirstSearch((void *) 3, rootNode, path, lastPath);
    tempPath = path;
    while (tempPath->next != NULL) {
        tempPath = tempPath->next;
    }
    if (tempPath->current->data == (void *) 3) {
        printf("Item foound path is: ");
        printPath(path);
    } else {
        printf("%s not in tree\n", (char *) tempPath->current->data);
    }

    return 0;
}

Path *DepthFirstSearch(void *lookingFor, Node *rootNode, Path *path, Path *lastPath) {
    path = initalisePath();
    lastPath = initalisePath();
    path->current = rootNode;
    path->prev = lastPath;
    lastPath->next = path;
    if (memcmp(rootNode->data, lookingFor, sizeof(int))) {
        printf("Test\n");
        return path;
    }
    if ((rootNode->leftNode == NULL) && (rootNode->rightNode == NULL)) {
        return path;
    }
    if (rootNode->leftNode != NULL) {
        lastPath = path;
        path->next = DepthFirstSearch(lookingFor, rootNode->leftNode, path->next, lastPath);
    } 
    if (rootNode-> rightNode != NULL) {
        lastPath = path;
        path->next = DepthFirstSearch(lookingFor, rootNode->rightNode, path->next, lastPath);
    }
    return path;
}