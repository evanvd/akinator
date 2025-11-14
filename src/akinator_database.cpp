#include <stdio.h>
#include <string.h>
#include "akinator_database.h"

tree_t* GetNodeFromFile(char* filename)
{
    data_base base = {};
    base.data_file = fopen(filename,"r");
    size_t buffer_size = 0;
    
    ssize_t read = getline(&base.data, &buffer_size, base.data_file);
    if (read > 0 && base.data[read - 1] == '\n') 
    {
       base.data[read - 1] = '\0';
    
    }
    fclose(base.data_file);
    
    tree_t* tree = {};
    tree->root = ReadNode(base.data);
    return tree;
}

node_t* ReadNode(char* data)
{
    node_t* created_node = {};
    
    char readed_node [255] = {};
    sscanf(data, "(\"%s\")", readed_node);
    created_node->data = readed_node;
    data = data + strlen(readed_node) + 2;
    
    if (strcmp(readed_node,"nil") == 0)
    {
        return NULL;
    }
    
    created_node->left = ReadNode(data);
    created_node->right = ReadNode(data);
    data += 1;
    return created_node;
}

void WriteTree(tree_t* tree, char* filename)
{
    data_base base = {};
    base.data_file = fopen(filename,"w");
    WriteNode(tree->root, base.data_file);
    fclose(base.data_file);
}

void WriteNode(node_t* node, FILE* base_file)
{
    if (node == NULL) 
    {
        fprintf(base_file, " nil "); 
        return;
    }
    fprintf(base_file, "(");

    fprintf(base_file, "\"%s\"", node->data);
    
    WriteNode(node->left, base_file);
    WriteNode(node->right, base_file);
    
    fprintf(base_file,")");
}