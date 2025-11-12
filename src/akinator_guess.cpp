#include "akinator_guess.h"
#include <string.h>
#include <assert.h>

void GuessWord(node_t* name)
{
    assert(name != NULL);
    printf("%s?\n", name->data);
    char* user_answer = {};
    scanf("%s", user_answer);
    if(strcmp(user_answer, "yes") == 1)
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
        }
        else
        {
            GuessWord(name->right);
        }
    }
}