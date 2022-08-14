# Binary Trees #  
This is a implementation of binary trees in c for use in other projects.

| Contents                        |
|---------------------------------|
|[How to use](#how-to-use)        |
|[Custom Structs](#custom-structs)|
|[Functions](#functions)          |

## How to use

There are two main options for using the tree library, the first option is:  
compile the program with gcc and use -c flag to compile it to a .o file, the following command will compile it correctly:
    gcc -c tree.c (any flags the user wants)
then in the program you wish to use it in use #include "tree.h", then when you compile the main program use the command:

    gcc -o (program name) (file to compile.c) tree.o (any flags the user wants)

The second option is to add or create a Makefile and then use the following lines inside the Makefile:

    $(CC)=gcc
    $(CFLAGS)=(any flags the user wish to use)

    tree.o: tree.c tree.h
        $(CC) -c $< $(CFLAGS)
The just call make and it will make tree.o for use in other programs.

For both options if no flags are used then just leave thos bits blank.
## Custom Structs

### Node
There is a custom struct in tree.h that uses a typedef of Node, this is used as the nodes in the tree that connect to each other. This has 3 attributes that are:
- **data** - This is an integer and holds the data in that node for the tree.
- **leftNode** - This is a Node data type and will hold a pointer to another node that will allow the tree to continue down the left path.
- **rightNode** - This is a Node data type and will hold a pointer to another node that will allow the tree to continue down the right path.

### Path
There is a custom struct in tree.h that uses a typedef of Path, this is used as a path that the user can create to traverse to a certain point in the tree from root. This has 3 attributes that are:
- **prev** - This is a Path data type and will hold a pointer to another Path struct that will allow the program and user to traverse the path backwards.
- **current** - This a Node data type and will hold a pointer to a Node struct which will tell the program and user the current step in the path they are at.
- **next** - This is a Path data type and will hold a pointer to another Path struct that will allow the program and user to traverse the path forwards.

## Functions
- **initaliseNode()** - This takes in no arguments and returns a Node data type, this creates and assigns memory to a node and returns it.
- **createRootNode()** - This takes in a integer called data and returns a Node data type. This will create a node assign memory to it and set the data to be the data in the node and return it for use as a root node in a tree.
- **createNode()** - This takes in a Node data type and an integer called data and returns a Node data type. This will take in a node check which side the new node has to go on assign memory to a new node attach the two nodes and set the data input to the new nodes data.
- **printNode** - This will take in a Node data type and returns nothing. This will print out the node passed in by printing its data and the left and right node.
- **freeNode()** - This takes a Node data type as an argument and returns nothing, this will unassign any memory attached to the node passed in. 
- **initialisePath()** - This takes in no arguments and returns a Path data type, this creates and assigns memory to the first step of a path to a certain node.
- **createPath()** - This takes in a Path data type, and a Node data type, and returns a Path data type. This will assign memory to a Path data type atach it to the Path passed in and assign the Node passed in to the newly created Path.
- **printPath()** - This takes in a Path data type as an argument and returns nothing. This will print out a path starting from the path given to it to the end of the path.
- **freePath()** - This takes a Path data type as an argument and returns nothing, this will unassign any memory attached to the current step in the path that is passed in. 
- **printTree()** - This takes in a Node data type and an integer called space and returns nothing. This will print a full tree starting from the node it is given. When calling this fucntion space should be called as 0.
- **freeTree()** - This will take in a Node data type and returns nothing. This will free everything on the tree before and including the node passed in.