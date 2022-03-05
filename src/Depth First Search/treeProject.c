#include <stdio.h>
#include <string.h>

#include "./../tree.c"
#include "treeProject.h"

int main(int argc, char *argv[]) {
    Node *rootNode, *currentNode;
    int i;
    Path *path, *lastPath;

    if (argc < 2) {
        printf("Invalid amount of arguments\n");
        return 1;
    }
    path = initalisePath();
    lastPath = initalisePath();
    rootNode = createRootNode((void *) argv[1]);
    for (i = 2; i < argc; i++) {
        currentNode = createNode(rootNode, (void *) argv[i]);
    }
    printTree(rootNode, 0);
    path = DepthFirstSearch((void *) 3, rootNode, path, lastPath);
    //path = resetPath(path);
    //printPath(path);

    return 0;
}

Path *DepthFirstSearch(void *lookingFor, Node *rootNode, Path *path, Path *lastPath) {
    path->current = rootNode;
    path->prev = lastPath;
    lastPath->next = path;
    
    if (rootNode->data == lookingFor) {
        return path;
    }
    if ((rootNode->leftNode == NULL) && (rootNode->rightNode == NULL)) {
        return path;
    }
    if (rootNode->leftNode != NULL) {
        lastPath = path;
        return DepthFirstSearch(lookingFor, rootNode->leftNode, path->next, lastPath);
    } 
    if (rootNode-> rightNode != NULL) {
        lastPath = path;
        return DepthFirstSearch(lookingFor, rootNode->rightNode, path->next, lastPath);
    }
    return path;
}