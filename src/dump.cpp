#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dump.h"

void NodePrint(node_t* node, const char* file, int line)
{
    printf("\n====DUMP from %s:%d====\n", file, line);
    PrintNode(node);
    printf("\n=================================\n\n");
}

void GraphDump(tree_t* tree, const char* filename, const char* file, int line)
{
    static size_t count_dump = 1;    
    
    FILE* log_file =  fopen(filename, "w");
    WriteToDot(tree->root, log_file);
    fclose(log_file);
    
    CallCommand(count_dump);
    DumpToHtml(tree, count_dump, file, line);
    count_dump++;
}

void WriteToDot(node_t* node, FILE* log_file)
{
    fprintf(log_file, "digraph {\n");

    fprintf(log_file, "graph [rankdir=TB, splines=polyline, nodesep=0.6];\n");
    fprintf(log_file, "node [shape=record, style=\"filled, rounded\", fillcolor=\"#009b34ff\", height=0.8];\n");
    fprintf(log_file, "edge [color=\"#008000\", penwidth=1.5, arrowhead = normal];\n");

    
    PrintNodeToDot(node, log_file);

    fprintf(log_file, "}");
}

static size_t node_count = 1;

void PrintNodeToDot(node_t* node, FILE* log_file)
{
    size_t current_node_id = node_count++;
    fprintf(log_file, "node%lu [label=\"{ adr %p | %s | {<L> %p| <R> %p}}\"];\n", current_node_id, node, node->data, node->left, node->right);
    if(node->left)
    {
        fprintf(log_file, "node%lu:<L>->node%lu\n", current_node_id, node_count);
        PrintNodeToDot(node->left, log_file);
    }

    if(node->right)
    {
        fprintf(log_file, "node%lu:<R>->node%lu\n", current_node_id, node_count);
        PrintNodeToDot(node->right, log_file);
    }
}


void CallCommand(size_t count_dump)
{
    char cmd[60] = {};
    snprintf(cmd, sizeof(cmd), "%s%lu.%s", "dot -Tpng log/graphviz_file.dot -o log/tree", count_dump, "png");
    printf("%s\n",cmd);
    system(cmd);
}


void DumpToHtml(tree_t* tree, size_t count_dump, const char* file, int line)
{
    char dump_str[120] = {};
    snprintf(dump_str, sizeof(dump_str), "<h1>DUMP FROM %s:%d</h1>\n", file, line);
    fprintf(tree->dump_file, "%s",dump_str);
    

    char img_name[40] = {};
    snprintf(img_name, sizeof(img_name), "<img src = \"log/tree%lu.png\"/>\n",  count_dump);
    fprintf(tree->dump_file, "%s", img_name);
}