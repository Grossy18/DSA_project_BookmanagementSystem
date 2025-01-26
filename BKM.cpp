#include "BKM.h"
#include <iostream>

using namespace std;

// Constructor to initialize an empty book list
BKM::BKM() {
    start = nullptr;
}

// Constructor for Book class to initialize its attributes
Book::Book(int id, const char* name, double price, int rating, const char* author) {
    this->id = id;
    strcpy(this->name, name);
    this->price = price;
    this->rating = rating;
    strcpy(this->author, author);
    prev = next = nullptr;  // Initialize pointers to null
}

// Add a new book at a specified position in the list
void BKM::addBookAtPos(int id, const char* name, double price, int rating, const char* author, int pos) {
    Book* newBook = new Book(id, name, price, rating, author);  // Create a new book object
    
    if (start == nullptr) {  // If the list is empty
        start = newBook;     // Set start to new book
        return;
    }

    if (pos == 1) {  // If inserting at the head (position 1)
        newBook->next = start;  // Link new book to current head
        start->prev = newBook;   // Update current head's previous pointer
        start = newBook;         // Update head to new book
        return;
    }

    Book* temp = start;  // Temporary pointer for traversal
    
    // Traverse to the position before where we want to insert
    for (int i = 1; i < pos - 1 && temp->next != nullptr; i++) {
        temp = temp->next;
    }

    newBook->next = temp->next;   // Link new book's next to temp's next
    
    if (temp->next != nullptr) {   // If not inserting at end of list
        temp->next->prev = newBook; // Update next node's previous pointer
    }
    
    temp->next = newBook;          // Link temp's next to new book
    newBook->prev = temp;          // Link new book's previous to temp
}

// Display all books in the list from head to tail
void BKM::display() {
    if (start == nullptr) {  // Check if list is empty
        cout << "No books available." << endl;
        return;
    }

    Book* temp = start;  // Temporary pointer for traversal
    
    while (temp != nullptr) {  // Traverse through the list and print details of each book
        cout << "ID: " << temp->id << ", Name: " << temp->name 
             << ", Price: " << temp->price 
             << ", Rating: " << temp->rating 
             << ", Author: " << temp->author << endl;
        temp = temp->next;  // Move to next node in the list
    }
}

// Display details of a single book by ID
void BKM::displaySingle(int id) {
    Book* book = searchById(id);  // Search for the book by ID
    
    if (book == nullptr) {  // If not found, print message and return
        cout << "Book not found." << endl;
        return;
    }

   // Print details of found book 
   cout << "ID: " << book->id 
        << ", Name: " << book->name 
        << ", Price: " << book->price 
        << ", Rating: " << book->rating 
        << ", Author: " << book->author << endl;
}

// Search for a book by ID and return its pointer if found.
Book* BKM::searchById(int id) {
   Book* temp = start;

   while (temp != nullptr) {       // Traverse through the list until found or end reached.
       if (temp->id == id) {       // Check if current node matches ID.
           return temp;            // Return pointer to found node.
       }
       temp = temp->next;          // Move to next node.
   }
   
   return nullptr;                 // Return null if not found.
}

// Update details of a specific book.
void BKM::update(Book* book) {
   if (book == nullptr) {          // Check if provided pointer is valid.
       cout << "Book not found." << endl;
       return;
   }

   int choice;

   cout << "1. Update Name\n2. Update Price\n3. Update Rating\n4. Update Author\nEnter choice: ";
   
   cin >> choice;

   switch (choice) {               // Switch based on user choice for updating attributes.
       case 1:
           cout << "Enter new name: ";
           cin.ignore();           // Clear input buffer before reading string.
           cin.getline(book->name, 50);  // Read updated name.
           break;

       case 2:
           cout << "Enter new price: ";
           cin >> book->price;     // Read updated price.
           break;

       case 3:
           cout << "Enter new rating: ";
           cin >> book->rating;     // Read updated rating.
           break;

       case 4:
           cout << "Enter new author: ";
           cin.ignore();            // Clear input buffer before reading string.
           cin.getline(book->author, 50);  // Read updated author name.
           break;

       default:
           cout << "Invalid choice." << endl;  // Handle invalid input.
   }
}

// Sort books based on user choice (by price or rating).
void BKM::sort(int& choice) {
   if (start == nullptr || start->next == nullptr) {  // Check if list is empty or has only one element.
       return;
   }

   for (Book* i = start; i != nullptr; i = i->next) {      // Outer loop for each node.
       for (Book* j = i->next; j != nullptr; j = j->next) {      // Inner loop for comparison with subsequent nodes.
           bool swapCondition = (choice == 1 && i->price > j->price) || 
                                 (choice == 2 && i->rating < j->rating);

           if (swapCondition) {     // If swap condition is met based on user choice,
               swap(i->id, j->id);              // Swap IDs.
               swap(i->price, j->price);        // Swap prices.
               swap(i->rating, j->rating);      // Swap ratings.
               swap(i->name, j->name);          // Swap names.
               swap(i->author, j->author);      // Swap authors.
           }
       }
   }
}

// Delete a book at a specific position in the list.
void BKM::deleteAtPos(int pos) {
   if (start == nullptr) {          // Check if list is empty.
       cout << "No books to delete." << endl;
       return; 
   }

   if (pos == 1) {                  // If deleting head node,
       Book* temp = start;          // Store head temporarily. 
       start = start->next;         // Move head pointer to next node.

       if (start != nullptr) {      // If there is a next node,
           start->prev = nullptr;   // Set its previous pointer to null.
       }

       delete temp;                 // Free memory of deleted node.
       return; 
   }

   Book* temp = start;             // Temporary pointer for traversal.

   for (int i = 1; i < pos && temp != nullptr; i++) { 
       temp = temp->next;          // Traverse until position or end reached.
   }

   if (temp == nullptr) {          // If position is invalid,
       cout << "Invalid position." << endl; 
       return; 
   }

   if (temp->prev != nullptr) {     //
       temp->prev->next = temp->next;     //
   }

   if (temp->next != nullptr) {     //
       temp->next->prev = temp->prev;
   }

   delete temp;                     //
}
