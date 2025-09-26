#include<stdio.h>
#include "book.h"

void createBook(Book *book, const char *title, const char *author, int id)
{
    if(book == NULL || title == NULL || author == NULL)
    {
        printf("Invaled book or author information.\n");
        return;
    }
    snprintf(book->title, sizeof(book->title), "%s", title);
    snprintf(book->author, sizeof(book->author), "%s", author);
    book->id = id;
    book->status = 'A'; // Set status to available
    printf("Book created: %s by %s (ID: %d)\n", book->title, book->author, book->id);
}
void printBookInfor(const Book *book)
{
    if(book == NULL)
    {
        printf("Invalid book provided for printing.\n");
        return;
    }
    printf("-----Book Information:------\n");
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("ID: %d\n", book->id);
    printf("Status: %c\n", book->status);
    if(book->status == 'A')
    {
        printf("The book is available.\n"); 
    }
    else if(book->status == 'B')
    {
        printf("The book is borrowed.\n");
    }
    else
    {
        printf("Unknown status.\n");
    }
}