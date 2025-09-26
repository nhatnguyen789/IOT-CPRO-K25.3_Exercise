
#ifndef LIBRARY_H
#define LIBRARY_H

#include "user.h"
#include "book.h"

void addBookToLibrary(Book *book, const char *tittle, const char *author, int id);
void addUserToLibrary(User *userm, const char *name, int id);
void removeBookFromLibrary(Book *book);
void removeUserFromLibrary(User *user);
void handleBorrowRequest(User *user, Book *book);
void handleReturnRequest(User *user, Book *book);
void findBooks(Book *book, const char *tittle, const char *author);
void displayAvailableBooks(Book *books);

#endif 