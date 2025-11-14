#include  <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

void InitTree(tree_t* tree)
{
    tree->dump_file = fopen("dump.html", "w"); //FIXME HARDCODE yeee
    tree->root  = CreateNode("Животное", NULL); 
}

void PrintNode(node_t* node)
{
    if (node == NULL) 
    {
        printf(" nil "); 
        return;
    }
    printf("(");
    PrintNode(node->left);

    printf("%s", node->data);
    PrintNode(node->right);
    printf(")");
}

node_t* CreateNode(char* data, node_t* parent)
{
    node_t* new_node = (node_t*)calloc(1, sizeof(node_t));
    new_node->parent = parent;
    if(data != NULL)
    {
        new_node->data = (char*)malloc(strlen(data) + 1);
        strcpy(new_node->data, data);
    } 
    else 
    {
        new_node->data = NULL;
    }
    
    return new_node;
}

void InsertNode(node_t* root, char* element)
{
    if(element <= root->data)
    {
        if(root->left == NULL)
        {
            root->left = CreateNode(element, root);
            assert(root->left != NULL); // TODO use if here
        }
        else
        {
            InsertNode(root->left, element);
        }

        return;
    }

    if(root->right == NULL)
    {
        root->right = CreateNode(element, root);
        assert(root->right != NULL);
    }
    else
    {
        InsertNode(root->right, element);
    }
}

void DeleteNode(node_t* node)
{
    if(node == NULL) return;
    
    if(node->left)
    {
        DeleteNode(node->left);
    }

    if (node->right)
    {
        DeleteNode(node->right);
    }
    free(node);
}

void DestroyTree(tree_t* tree)
{
    if (tree->dump_file != NULL) 
    {
        fclose(tree->dump_file);
    }
    if (tree->root != NULL) 
    {
        DeleteNode(tree->root);
    }
}