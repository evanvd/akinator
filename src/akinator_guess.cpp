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
void CreateOption(node_t* wrong_guess)
{
    printf("кто это?\n");
    char new_object[256] = {}; 
    scanf("%255s", new_object);

    printf("какой отличительный признак у него\n");
    char question[256] = {}; 
    scanf("%2555s", question);

    
    node_t* question_node = CreateNode(question, wrong_guess->parent);
    wrong_guess->parent = question_node;
    question_node->left = CreateNode(new_object, question_node);   
    question_node->right = wrong_guess;              
}