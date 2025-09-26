
#ifndef BOOK_H
#define BOOK_H

typedef struct{
    char title[50];
    char author[50];
    int id;
    char status; // 'A' for available, 'B' for borrowed
}Book;

void createBook(Book *book, const char *title, const char *author, int id);
void printBookInfor(const Book *book);

#endif // BOOK_H