#include <iostream>
#include <string>
#include <vector>
#include<fstream>
#include "classes.h"
using namespace std;

void load_books(){
    fstream file;
    file.open("books.txt", ios::in);
    string line;
    string token;
    getline(file, line);

    cout<<"test";
    vector<string> tokens;
    size_t pos = 0;

    while ((pos = line.find(','))!= string::npos){

        token = line.substr(0, pos);
        tokens.push_back(token);
        line.erase(0, pos+1);
    }
    tokens.push_back(line);

    for (int i = 0; i < tokens.size(); ++i) {
        cout<<i<<" "<<tokens[i]<<"\n";
    }


}

int main() {
    vector<Book> *books = new vector<Book>;
    load_books();


   // Create some books
    Book* book1 = new Book("The Great Gatsby", "F. Scott Fitzgerald", 1925);
    Book* book2 = new Book("To Kill a Mockingbird", "Harper Lee", 1960);
    Book* book3 = new Book("Pride and Prejudice", "Jane Austen", 1813);

    // Create some users
    User* user1 = new User("Alice");
    User* user2 = new User("Bob");

    // Create a library and add books and users
    Library library;
    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);
    library.addUser(user1);
    library.addUser(user2);

    // Print the library books and users
    library.printBooks();
    library.printUsers();

    // Alice borrows a book
    library.borrowBook(book1, user1);

    // Print the library books and users again
    library.printBooks();
    library.printUsers();

    // Bob tries to borrow a book that is already borrowed
    library.borrowBook(book1, user2);

    // Alice returns the book she borrowed
    library.returnBook(book1, user1);

    // Print the library books and users again
    library.printBooks();
    library.printUsers();

    // Clean up the memory
    delete book1;
    delete book2;
    delete book3;
    delete user1;
    delete user2;

    return 0;

}