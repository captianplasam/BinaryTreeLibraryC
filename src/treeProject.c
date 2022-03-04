#include <stdio.h>

#include "tree.c"
#include "treeProject.h"

int main(int argc, char *argv[]) {
    Node *rootNode, *currentNode;
    int i;

    if (argc < 2) {
        printf("Invalid amount of arguments\n");
        return 1;
    }
    rootNode = createRootNode((void *) argv[1]);
    for (i = 2; i < argc; i++) {
        currentNode = createNode(rootNode, (void *) argv[i]);
    }
    printTree(rootNode, 0);
    freeTree(rootNode);
    return 0;
}