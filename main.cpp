#include <iostream>
#include "BKM.h"

using namespace std;

int main() {
   BKM manager;                     //
   int choice;

   do {
       cout << "\n--- Book Management ---\n";
       
      cout << "1. Add Book\n2. Display All Books\n3. Display Book Details\n4. Update Book\n5. Sort Books\n6. Delete Book\n7. Exit\nEnter choice: ";
       
      cin >> choice;

      switch (choice) {
          case 1: {                    //
              int id, rating, pos;
              double price;
              char name[50], author[50];
              cout << "Enter ID, Name, Price, Rating, Author and Position: ";
              cin >> id >> ws;         //
              cin.getline(name, 50);  
              cin >> price >> rating >> ws;
              cin.getline(author, 50);
              cin >> pos;

              manager.addBookAtPos(id, name, price, rating, author, pos);
              break;
          }
          case 2:
              manager.display();         //
              break;

          case 3: {                    //
              int id;
              cout << "Enter Book ID: ";
              cin >> id;
              manager.displaySingle(id);
              break;
          }
          case 4: {                    //
              int id;
              cout << "Enter Book ID: ";
              cin >> id;

              Book* book = manager.searchById(id);
              manager.update(book);
              break;
          }
          case 5: {                    //
              int sortChoice;
              cout << "Sort by: 1. Price 2. Rating\nEnter choice: ";
              cin >> sortChoice;

              manager.sort(sortChoice);
              break;
          }
          case 6: {                    //
              int pos;
              cout << "Enter position to delete: ";
              cin >> pos;

              manager.deleteAtPos(pos);
              break;
          }
          case 7:
              cout << "Exiting..." << endl;  
              break;

          default:
              cout << "Invalid choice." << endl;
      }
   } while (choice != 7);            //

   return 0;
}
