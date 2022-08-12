#include "./../tree.c"
#include "treeProject.h"

int main(int argc, char *argv[]) {
    Node *rootNode, *currentNode;
    int i;
    Path *path, *lastPath, *tempPath;
    char buffer[100];

    if (argc < 2) {
        printf("Invalid amount of arguments\n");
        return 1;
    }
    rootNode = createRootNode((int) argv[1]);
    for (i = 2; i < argc; i++) {
        currentNode = createNode(rootNode, (int) argv[i]);
    }
    printTree(rootNode, 0);
    path = DepthFirstSearch(3, rootNode, path, lastPath);
    tempPath = path;
    while (tempPath->next != NULL) {
        tempPath = tempPath->next;
    }
    if (3 == tempPath->current->data) {
        itoa(tempPath->current->data, buffer, 10);
        printf("%s found path is: ", buffer);
        printPath(path);
    } else {
        printf("%d not in tree\n", 3);
    }

    return 0;
}

Path *DepthFirstSearch(int lookingFor, Node *rootNode, Path *path, Path *lastPath) {
    path = initalisePath();
    lastPath = initalisePath();
    path->current = rootNode;
    path->prev = lastPath;
    lastPath->next = path;
    if (lookingFor == path->current->data) {
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