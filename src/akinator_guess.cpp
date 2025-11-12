#include "akinator_guess.h"
#include <string.h>

void GuessWord(node_t* name)
{
    printf("%s?\n", name->data);
    char* user_answer = NULL;
    scanf("%s", user_answer);
    if (strcmp(user_answer, "yes") == 1)
    {
        if (name->right == NULL)
        {
            printf("ХАХАХАХХАХАХ я угадал\n");
            return;
        }
        else
        {
            GuessWord(name->right);
            return;
        }
    }
    else
    {
        if (name->right == NULL)
        {
            printf("Созадние нового перса\n");
            return;
        }
        else
        {
            GuessWord(name->right);
            return;
        }
    }
}