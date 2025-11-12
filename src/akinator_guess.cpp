#include "akinator_guess.h"
#include <string.h>
#include <assert.h>

void GuessWord(node_t* name)
{
    assert(name != NULL);
    printf("%s?\n", name->data);
    char user_answer[256] = {}; 
    scanf("%255s", user_answer);
    if(strcmp(user_answer, "yes") == 0)
    {
        if (name->left == NULL)
        {
            printf("succes\n");
        }
        else
        {
            GuessWord(name->left);
        }
    }
    else
    {
        if (name->right == NULL)
        {
            printf("failed, add new question\n");
            CreateOption(name);
        }
        else
        {
            GuessWord(name->right);
        }
    }
}
void CreateOption(node_t* node)
{
    char object_name[256] = {}; 
    scanf("%255s", object_name);

    char question[256] = {}; 
    scanf("%255s", question);

    node_t* right_answer = node;
    node = CreateNode(question); 

    node_t* left_answer = CreateNode(object_name);
    
    node->left = left_answer;
    node->right = right_answer;
}