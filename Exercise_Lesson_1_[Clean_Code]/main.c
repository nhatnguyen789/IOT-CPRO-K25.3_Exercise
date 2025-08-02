#include<stdio.h>
#include "library.h"

void main()
{
    Book book1;
    User user1;

    // Adding a book to the library
    addBookToLibrary(&book1, "The Great Gatsby", "F. scott Fitzgerald", 1);
    printf("-------------------\n");
    // Adding a user to the library
    addUserToLibrary(&user1, "Alice", 101);
    printf("-------------------\n");
    // Borrowing a book
    handleBorrowRequest(&user1, &book1);
    // Printing book information
    printBookInfor(&book1);
    printf("-------------------\n");
    // Printing user information
    printUserInfor(&user1);
    printf("-------------------\n");
    // Returning a book
    handleReturnRequest(&user1, &book1);
    // Printing book information after return
    printBookInfor(&book1);
    printf("-------------------\n");
    // Printing user information after return
    printUserInfor(&user1);
    printf("-------------------\n");
    // Removing the book from the library
    removeBookFromLibrary(&book1);
    // Removing the user from the library
    removeUserFromLibrary(&user1);
    // Dispaying the final state of the book and user
    printBookInfor(&book1);
    printf("-------------------\n");
    printUserInfor(&user1);
    printf("-------------------\n");
}