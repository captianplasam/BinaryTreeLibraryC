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
    path = DepthFirstSearch("3", rootNode, path, lastPath);
    tempPath = path;
    while (tempPath->next != NULL) {
        tempPath = tempPath->next;
    }
    if (!(strcmp("3", (char *) tempPath->current->data))) {
        printf("%s found path is: ", (char *) tempPath->current->data);
        printPath(path);
    } else {
        printf("%d not in tree\n", 3);
    }

    return 0;
}

Path *DepthFirstSearch(char *lookingFor, Node *rootNode, Path *path, Path *lastPath) {
    path = initalisePath();
    lastPath = initalisePath();
    path->current = rootNode;
    path->prev = lastPath;
    lastPath->next = path;
    if (!(strcmp(lookingFor, (char *) path->current->data))) {
        printf("Test\n");
        return path;
    }
    if ((rootNode->leftNode == NULL) && (rootNode->rightNode == NULL)) {
        printf("Error\n");
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