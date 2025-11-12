#include <stdio.h>
#include "akinator_database.h"

node_t* GetNodeFromFile(char* filename)
{
    data_base base = {};
    base.data_file = fopen(filename,"r");
    fscanf(base.data_file, "%s\n", base.data);
    ReadFromFile(base.data, 0);
}

void ReadFromFile(char* data, size_t pst)
{
    
}