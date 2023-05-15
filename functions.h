//
// Created by naims on 14/05/2023.
//

#ifndef LIBRARY_MANAGEMENT_SYSTEM_FUNCTIONS_H
#define LIBRARY_MANAGEMENT_SYSTEM_FUNCTIONS_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<sstream>
#include<algorithm>
#include <string>

void performUserOperations(Library &library, User *user)
{
    int choice;
    std::cout << "User Operations:" << std::endl;
    std::cout << "1. Borrow Book" << std::endl;
    std::cout << "2. Return Book" << std::endl;
    std::cout << "3. Display Book Info" << std::endl;
    std::cout << "4. Logout" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice)
    {
        case 1:
        {
            std::string title;
            std::cout << "Enter the title of the book to borrow: ";
            std::cin.ignore();
            std::getline(std::cin, title);
            Book *book = library.getBook(title);
            if (book != nullptr)
            {
                library.borrowBook(user, book);
            }
            else
            {
                std::cout << "Book not found." << std::endl;
            }
            break;
        }
        case 2:
        {
            std::string title;
            std::cout << "Enter the title of the book to return: ";
            std::cin.ignore();
            std::getline(std::cin, title);
            Book *book = library.getBook(title);
            if (book != nullptr)
            {
                library.returnBook(user, book);
            }
            else
            {
                std::cout << "Book not found." << std::endl;
            }
            break;
        }
        case 3:
        {
            std::string title;
            std::cout << "Enter the title of the book: ";
            std::cin.ignore();
            std::getline(std::cin, title);
            library.displayBookInfo(title);
            break;
        }
        case 4:
        {
            std::cout << "Logging out..." << std::endl;
            return;
        }
        default:
        {
            std::cout << "Invalid choice." << std::endl;
            break;
        }
    }

    performUserOperations(library, user);
}

void performAdminOperations(Library &library)
{
    int choice;
    std::stringstream ss;
    std::string in, str, un, ps, rl;
    std::cout << "Admin Operations:" << std::endl;
    std::cout<<"0. Add user"<<std::endl;
    std::cout << "1. Add Book" << std::endl;
    std::cout << "2. Remove Book" << std::endl;
    std::cout << "3. Display All Books" << std::endl;
    std::cout << "4. Logout" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice)
    {
        case 0:
            std::cout<<"Enter username, password and role seperated by comma(no space): ";std::cin>>str;
            ss<<str;
            std::getline(ss, un, ',');
            std::getline(ss, ps, ',');
            std::getline(ss, rl, ',');
            library.addUser(library.createUser(un, ps, rl));
            break;

        case 1:
        {
            std::string title, author;
            std::cout << "Enter the title of the book: ";
            std::cin.ignore();
            std::getline(std::cin, title);
            std::cout << "Enter the author of the book: ";
            std::getline(std::cin, author);
            library.addBook(new Book(title, author));
            std::cout << "Book added successfully!" << std::endl;
            break;
        }
        case 2:
        {
            std::string title;
            std::cout << "Enter the title of the book to remove: ";
            std::cin.ignore();
            std::getline(std::cin, title);
            Book *book = library.getBook(title);
            if (book != nullptr)
            {
                library.removeBook(book);
                delete book;
                std::cout << "Book removed successfully!" << std::endl;
            }
            else
            {
                std::cout << "Book not found." << std::endl;
            }
            break;
        }
        case 3:
        {
            library.displayAllBooks();
            break;
        }
        case 4:
        {
            std::cout << "Logging out..." << std::endl;
            return;
        }
        default:
        {
            std::cout << "Invalid choice." << std::endl;
            break;
        }
    }

    performAdminOperations(library);
}
#endif //LIBRARY_MANAGEMENT_SYSTEM_FUNCTIONS_H
