#include "tree.h"

#define COUNT 10 //used for space in printTree

Node *initaliseNode(void) {
    Node *currentNode;

    if (!(currentNode = (Node *) malloc(sizeof(Node)))) { //checking memory can be assigned for a node
        printf("Unable to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    //assigning everything for the node
    currentNode -> leftNode = currentNode -> rightNode = NULL;
    currentNode -> data = 0;

    return currentNode;
}

Node *createRootNode(int data) {
    Node *rootNode;

    //initalising node for use and assigning it the given data
    rootNode = initaliseNode();
    rootNode->data = data;

    return rootNode;
}

Node *createNode(Node *rootNode, int data) {
    Node *currentNode, *newNode;

    // creating and given the correct data to the new node
    newNode = initaliseNode();
    newNode->data = data;
    currentNode = rootNode;
    while (1) {
        if(currentNode->data > data) { // seeing if it is smaller then the current node if true goes down the left path
            if (currentNode->leftNode == NULL) { // checks to see if it can be set here if not continues
                currentNode->leftNode = newNode;
                return currentNode;
            }
            currentNode = currentNode->leftNode;
        } else { // if false it will go down the right path 
            if (currentNode->rightNode == NULL) { // checks to see if it can be set here if not continues
                currentNode->rightNode = newNode;
                return currentNode;
            }
            currentNode = currentNode->rightNode;
        }
    }
}

void printNode(Node *currentNode) {
    char leftNode[10], rightNode[10]; 
    
    if (currentNode) { // checking if the node given is not NULL
        sprintf(leftNode, "%s", "NULL");
        sprintf(rightNode, "%s", "NULL");
        if (currentNode->leftNode) // if leftNode is not NULL gives the char leftNode the value of the left Node
            sprintf(leftNode, "%d", currentNode->leftNode->data);
        if (currentNode->rightNode) // if rightNode is not NULL gives the char rightNode the value of the right Node
            sprintf(rightNode, "%d", currentNode->rightNode->data);
        printf("Current Node: %d, Left Node: %s, Right Node: %s\n", currentNode->data, leftNode, rightNode); //prints the node
        return;
    }
    printf("Node does not exist\n"); // only occurs if given node is NULL
    return;
}

void freeNode(Node *currentNode) {
    if (!(currentNode)) { // checks if currentNode is NULL if it is then it returns
        return;
    }
    free(currentNode); // free non-NULL Node
}

Path *initalisePath(void) {
    Path *path;

    if (!(path = (Path *) malloc(sizeof(Path)))) { // tries to assgin memroy to a Path struct
        printf("Unable to allocate path memory\n"); // errors and exits if can't
        exit(EXIT_FAILURE);
    }
    // initalises and assigns data in path
    path->current = initaliseNode();
    path->prev = path->next = NULL;

    return path;
}

Path *createPath(Path *lastPath, Node *currentNode) {
    Path *currentPath;

    if (lastPath && currentNode) { //checks that the input path and node are correct
        // initalises and assigns path and data inside the path
        currentPath = initalisePath();
        lastPath->next = currentPath;
        currentPath->prev = lastPath;
        currentPath->current = currentNode;
        currentPath->next = NULL;
        return currentPath;
    }
    printf("Error path or node enter is NULL\n"); //errors if either path entered or node enter is NULL

    return NULL;
}

void printPath(Path *path) {
    char buffer[10];

    if (path == NULL) { // checks if the current Path is null for a base case
        return;
    }
    //prints each stage of the path and uses recursion to go to the end
    if (path->next != NULL) {
        sprintf(buffer, "%d", path->current->data);
        printf("%s, ", buffer);  
        printPath(path->next); //recursively goes to the end of the path
    } else {
        sprintf(buffer, "%d", path->current->data);
        printf("%s\n", buffer);
    }
}

void freePath(Path *path) {
    Path *temp;

    if (!(path)) // checks if path is non-NULL
        return;
    if (path->prev != NULL) { // checks if the path given is the start of the path. 
        temp = path->prev;
        temp->next = NULL;
    }
    // frees the node in the path then frees the current path
    freeNode(path->current);
    freePath(path->next);
    free(path);
}

void printTree(Node *rootNode, int space) {
    int i;
    char buffer[10];

    if (rootNode == NULL) // checks if the rootNode is NULL as base case
        return;
    space += COUNT; // adds predefined COUNT to space
    printTree(rootNode->rightNode, space); // uses recursion to go completely down the right path
    printf("\n");
    for (i = COUNT; i < space; i++)
        printf(" "); //prints all spaces needed in space
    sprintf(buffer, "%d", rootNode->data);
    printf("%s\n", buffer); // prints the data in the node
    printTree(rootNode->leftNode, space); // goes completely down the left path
}

void freeTree(Node *rootNode) {
    if (rootNode == NULL) // checks if root Node is not NULL
        return;
    // uses recursion to reach the leaf nodes and starts freeing from there
    freeTree(rootNode->rightNode);
    freeTree(rootNode->leftNode);
    freeNode(rootNode);
}