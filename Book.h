#ifndef BOOK_H
#define BOOK_H

#include <cstring>

// Book class definition
class Book {
public:
    int id;                // Unique identifier for the book
    char name[50];        // Name of the book
    double price;         // Price of the book
    int rating;           // Rating of the book (e.g., 1-5)
    char author[50];      // Author of the book
    Book* prev;           // Pointer to the previous book in the list
    Book* next;           // Pointer to the next book in the list

    // Constructor to initialize a new book with given parameters
    Book(int id, const char* name, double price, int rating, const char* author);
};

#endif // BOOK_H
