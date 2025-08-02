#include<stdio.h>
#include "user.h"

void createUser(User *user, const char *name, int id)
{
    if(user == NULL || name == NULL)
    {
        printf("Invalid user information.\n");
        return;
    }
    snprintf(user->name, sizeof(user->name), "%s", name);
    user->id = id;
    user->borrowedList[0] = '\0';
    printf("User created: %s (ID: %d)\n", user->name, user->id);
}
void printUserInfor(const User *user)
{
    if(user == NULL)
    {
        printf("Invalid user provided for printing.\n");
        return;
    }
    printf("-----User Information:-------\n");
    printf("Name: %s\n", user->name);
    printf("ID: %d\n", user->id);
    printf("Borrowed Books:", user->borrowedList);
    if(user->borrowedList[0] == '\0')
    {
        printf(" No books borrowed.\n");
    }
    else
    {
        printf("Borrowed Books IDs: ");
        for(int i = 0; i < sizeof(user->borrowedList) && user->borrowedList[i] != '\0'; i++)
        {
            printf("%c", user->borrowedList[i]);
            if(user->borrowedList[i+1] != '\0')
            {
                printf(", ");
            }
        }
        printf("\n");
    }
}