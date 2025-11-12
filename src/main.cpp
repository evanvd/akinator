#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "dump.h"



int main()
{
    tree_t tree = {};
    InitTree(&tree);    
    DUMP_TREE(tree, "log/graphviz_file.dot");
    DeleteNode(tree.root);
}