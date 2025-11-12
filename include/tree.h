#include <stdio.h>

#ifndef TREE_H
#define TREE_H


struct node_t 
{
    char* data;
    node_t* right;
    node_t* left;
};

struct tree_t
{
    FILE* dump_file = NULL;
    node_t* root = NULL;
};

void InitTree(tree_t* tree, char* root_element);
void PrintNode(node_t* node);
void InsertNode(node_t* node, char* element);
node_t* CreateNode(int data);
void DeleteNode(node_t* node);
#endif