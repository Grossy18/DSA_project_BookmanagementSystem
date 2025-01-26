#ifndef BKM_H
#define BKM_H

#include "Book.h"

// BKM class definition for managing books
class BKM {
private:
    Book* start;  // Pointer to the first book in the list

public:
    BKM();  // Constructor to initialize an empty list
    void addBookAtPos(int id, const char* name, double price, int rating, const char* author, int pos); // Add a book at a specific position
    void display();  // Display all books in the list
    void displaySingle(int id);  // Display details of a single book by ID
    Book* searchById(int id);  // Search for a book by ID and return its pointer
    void update(Book* book);  // Update details of a specific book
    void sort(int choice);  // Sort books based on price or rating
    void deleteAtPos(int pos);  // Delete a book at a specific position
};

#endif // BKM_H
