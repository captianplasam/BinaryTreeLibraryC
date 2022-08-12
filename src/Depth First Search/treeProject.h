#ifndef _TREE_PROJECT_H
#define _TREE_PROJECT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Path *DepthFirstSearch(int lookingFor, Node *rootNode, Path *path, Path *lastPath);

#endif