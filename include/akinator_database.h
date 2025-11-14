#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

struct data_base
{
    FILE* data_file = NULL;
    char* filename = NULL;
    char* data = NULL;
};

void ReadFromFile(char* data);
tree_t* GetNodeFromFile(char* filename);
node_t* ReadNode(char* data);
void WriteTree(tree_t* tree, char* filename);
void WriteNode(node_t* node, FILE* base_file);
void CreateOption(node_t* node);