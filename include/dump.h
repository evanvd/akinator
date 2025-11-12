#include <stdio.h>
#include "tree.h"


#define DUMP_TREE(tree, filename) NodePrint(tree.root, __FILE__, __LINE__);      \
                           GraphDump(&tree, filename, __FILE__, __LINE__);



void GraphDump(tree_t* node, const char* filename, const char* file, int line);
void NodePrint(node_t* node, const char* file, int line);
void WriteToDot(node_t* node, FILE* log_file);
void CallCommand(size_t count_dump);
void DumpToHtml(tree_t* node, size_t count_dump, const char* file, int line);
void PrintNodeToDot(node_t* node, FILE* log_file);