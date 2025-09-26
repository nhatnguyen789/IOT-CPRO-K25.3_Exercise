
#ifndef USER_H
#define USER_H

typedef struct{
    char name[50];
    int id;
    char borrowedList[10]; // List of ids of borrowed books
}User;

void createUser(User *user, const char *name, int id);
void printUserInfor(const User *user);

#endif 