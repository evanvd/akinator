#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "dump.h"
#include "akinator_guess.h"


int main()
{
    tree_t tree = {};
    InitTree(&tree);
    node_t* node1 = CreateNode("Полторашка");
    node_t* node2 = CreateNode("Лектор");
    node_t* node4 = CreateNode("Петрович");
    node_t* node3 = CreateNode("хуй");
    tree.root->left = node1;
    tree.root->right = node2;
    node2->left = node4;
    node2->right = node3;
    DUMP_TREE(tree, "log/graphviz_file.dot");
    GuessWord(tree.root);
    DUMP_TREE(tree, "log/graphviz_file.dot");
    DeleteNode(tree.root);
}