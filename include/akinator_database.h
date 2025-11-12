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
node_t* GetNodeFromFile(char* filename);
void ReadFromFile(char* data, size_t pst);