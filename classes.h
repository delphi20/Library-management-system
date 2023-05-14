//
// Created by naims on 14/05/2023.
//

#ifndef LIBRARY_MANAGEMENT_SYSTEM_CLASSES_H
#define LIBRARY_MANAGEMENT_SYSTEM_CLASSES_H
#include <iostream>
#include <vector>
using namespace std;

class Book {
private:
    string title;
    string author;
    int yearPublished;
    bool available;
public:
    Book(string title, string author, int yearPublished) {
        this->title = title;
        this->author = author;
        this->yearPublished = yearPublished;
        this->available = true;
    }

    string getTitle() {
        return title;
    }

    string getAuthor() {
        return author;
    }

    int getYearPublished() {
        return yearPublished;
    }

    bool isAvailable() {
        return available;
    }

    void borrow() {
        if(available) {
            available = false;
            cout << "Book \"" << title << "\" borrowed." << endl;
        } else {
            cout << "Book \"" << title << "\" is not available." << endl;
        }
    }

    void returnBook() {
        available = true;
        cout << "Book \"" << title << "\" returned." << endl;
    }
};

class User {
private:
    string name;
    vector<Book*> borrowedBooks;
public:
    User(string name) {
        this->name = name;
    }

    string getName() {
        return name;
    }

    vector<Book*> getBorrowedBooks() {
        return borrowedBooks;
    }

    void borrowBook(Book* book) {
        borrowedBooks.push_back(book);
    }

    void returnBook(Book* book) {
        for(int i = 0; i < borrowedBooks.size(); i++) {
            if(borrowedBooks[i] == book) {
                borrowedBooks.erase(borrowedBooks.begin() + i);
                book->returnBook();
                return;
            }
        }
    }
};

class Library {
private:
    vector<Book*> books;
    vector<User*> users;
public:
    void addBook(Book* book) {
        books.push_back(book);
    }

    void addUser(User* user) {
        users.push_back(user);
    }

    void borrowBook(Book* book, User* user) {
        if(book->isAvailable()) {
            book->borrow();
            user->borrowBook(book);
        } else {
            cout << "Book \"" << book->getTitle() << "\" is not available." << endl;
        }
    }

    void returnBook(Book* book, User* user) {
        for(int i = 0; i < users.size(); i++) {
            if(users[i] == user) {
                user->returnBook(book);
                return;
            }
        }
    }

    void printBooks() {
        cout << "Library books:" << endl;
        for(int i = 0; i < books.size(); i++) {
            cout << books[i]->getTitle() << " by " << books[i]->getAuthor() << " (" << books[i]->getYearPublished() << ")";
            if(books[i]->isAvailable()) {
                cout << " [available]" << endl;
            } else {
                cout << " [not available]" << endl;
            }
        }
    }

    void printUsers() {
        cout << "Library users:" << endl;
        for(int i = 0; i < users.size(); i++) {
            cout << users[i]->getName() << endl;
            vector<Book*> borrowedBooks = users[i]->getBorrowedBooks();
            if(borrowedBooks.size() > 0) {
                cout << "Borrowed books:" << endl;
                for(int j = 0; j < borrowedBooks.size(); j++){
                    cout << borrowedBooks[j]->getTitle() << " by " << borrowedBooks[j]->getAuthor() << " (" << borrowedBooks[j]->getYearPublished() << ")" << endl;
                }
            }
        }
    }
};
#endif //LIBRARY_MANAGEMENT_SYSTEM_CLASSES_H
