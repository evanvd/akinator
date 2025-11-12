#include  <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "tree.h"

void InitTree(tree_t* tree)
{
    tree->dump_file = fopen("dump.html", "w"); //FIXME HARDCODE yeee
    tree->root  = CreateNode("chto ugodno"); 
}

void PrintNode(node_t* node)
{
    if (node == NULL) return;
    
    printf("(");
    
    if(node->left)
    {
        PrintNode(node->left);
    }

    printf("%d", node->data);

    if(node->right)
    {
        PrintNode(node->right);
    }
    printf(")");
}

node_t* CreateNode(char* data)
{
    node_t* new_node = (node_t*)calloc(1, sizeof(node_t));

    new_node->data = data;
    return new_node;
}

void InsertNode(node_t* root, char* element)
{
    if(element <= root->data)
    {
        if(root->left == NULL)
        {
            root->left = CreateNode(element);
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
        root->right = CreateNode(element);
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
