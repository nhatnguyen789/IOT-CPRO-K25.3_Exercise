#include<stdio.h>
#include "library.h"

void addBookToLibrary(Book *book, const char *title, const char *author, int id)
{
    createBook(book, title, author, id);
    printBookInfor(book);
}
void addUserToLibrary(User *user, const char *name, int id)
{
    createUser(user, name, id);
    printUserInfor(user);
}
void removeBookFromLibrary(Book *book)
{
    if(book == NULL)
    {
        printf("Invaled book provided for removal.\n");
        return;
    }
    book->status = 'A'; // Set status to available
    printf("Book removed: %s (ID: %D)\n", book->title, book->id);
}
void removeUserFromLibrary(User *user)
{
    if(user == NULL)
    {
        printf("Invalid user provided for removal.\n");
        return;
    }
    user->borrowedList[0] = '\0'; // Clear borrowed list
    printf("User removed: %s (ID: %d)\n", user->name, user->id);
}
void handleBorrowRequest(User *user, Book *book)
{
    if(user == NULL || book == NULL)
    {
        printf("Invalid user or book provied for borrowing.\n");
        return;
    }
    if(book->status == 'A')
    {
        book->status = 'B';
        snprintf(user->borrowedList, sizeof(user->borrowedList), "%d", book->id);
        printf("Book borrowed: %s by %s (ID: %d) by user: %s (ID: %d)\n", book->title, book->author, book->id, user->name, user->id);
    }
    else
    {
        printf("Book is not available for borrowing: %s (ID: %d)\n", book->title, book->id);
    }
}
void handleReturnRequest(User *user, Book *book)
{
    if(user == NULL || book == NULL)
    {
        printf("Invalid user or book provided for returning.\n");
        return;
    }
    if(book->status == 'B')
    {
        book->status = 'A';
        user->borrowedList[0] = '\0';
        printf("Book returned: %s by %s (ID: %d) by user: %s (ID: %d)\n", book->title, book->author, book->id, user->name, user->id);

    }
    else
    {
        printf("Book is not borrowed: %s (ID: %d)\n", book->title, book->id);
    }
}
void findBooks(Book *books, const char *title, const char *author)
{
    if(books == NULL || title == NULL || author == NULL)
    {
        printf("Invaled book or author information provided for searching.\n");
        return;
    }
    printf("Searching for books with title: %s and author: %s\n", title, author);
    for(int i = 0; i < sizeof(books) / sizeof(books[0]); i++)
    {
        if(title[0] == '\0' || strncmp(books[i].title, title, sizeof(books[i].title)) == 0)
        {
            if(author[0] == '\0' || strncmp(books[i].author, author, sizeof(books[i].author)) == 0)
            {
                printf("Found book: %s by %s (ID: %d, Status: %c)\n", books[i].title, books[i].author, books[i].id, books[i].status);
            }
        }
    }
}
void displayAvailableBooks(Book *books)
{
    if(books == NULL)
    {
        printf("Invalid book list provided for displaying.\n");
        return;
    }
    printf("Available books:\n");
    for(int i = 0; i < sizeof(books) / sizeof(books[0]); i++)
    {
        if(books[i].status == 'A')
        {
            printf("Title: %s, author: %s, ID: %d\n", books[i].title, books[i].author, books[i].id);

        }
    }
    if(sizeof(books) / sizeof(books[0]) == 0)
    {
        printf("No available books in the library.\n");
    }
    else
    {
        printf("Total available books: %d\n", sizeof(books) / sizeof(books[0]));
    }
}