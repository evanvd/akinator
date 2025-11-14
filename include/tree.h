#include <stdio.h>

#ifndef TREE_H
#define TREE_H


struct node_t 
{
    node_t* parent = NULL;
    char* data = NULL;
    node_t* right = NULL;
    node_t* left = NULL;
};

struct tree_t
{
    FILE* dump_file = NULL;
    node_t* root = NULL;
};

void InitTree(tree_t* tree);
void PrintNode(node_t* node);
void InsertNode(node_t* node, char* element);
node_t* CreateNode(char* data, node_t* parent);
void DeleteNode(node_t* node);
void DestroyTree(tree_t* tree);
#endif