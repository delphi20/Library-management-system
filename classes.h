//
// Created 
//

#ifndef LIBRARY_MANAGEMENT_SYSTEM_CLASSES_H
#define LIBRARY_MANAGEMENT_SYSTEM_CLASSES_H


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

class User
{
private:
    std::string username;
    std::string password;
    std::string role;

public:
    User(const std::string &u, const std::string &p, const std::string &r)
        : username(u), password(p), role(r) {}

    const std::string &getUsername() const { return username; }
    const std::string &getPassword() const { return password; }
    const std::string &getRole() const { return role; }
};

class Book
{
private:
    std::string title;
    std::string author;
    bool isAvailable;

public:
    Book(const std::string &t, const std::string &a)
        : title(t), author(a), isAvailable(true) {}

    const std::string &getTitle() const { return title; }
    const std::string &getAuthor() const { return author; }
    bool getAvailability() const { return isAvailable; }
    void setAvailability(bool available) { isAvailable = available; }
};

class Library
{
private:
    std::vector<User *> users;
    std::vector<Book *> books;

public:
    User* createUser(std::string un, std::string ps, std::string rl ){
        User user(un, ps, rl);
        return &user;
    }
    void addUser(User *user)
    {
        users.push_back(user);
    }

    User *getUser(const std::string &username)
    {
        for (User *user : users)
        {
            if (user->getUsername() == username)
            {
                return user;
            }
        }
        return nullptr;
    }

    void addBook(Book *book)
    {
        books.push_back(book);
    }

    Book *getBook(const std::string &title)
    {
        for (Book *book : books)
        {
            if (book->getTitle() == title)
            {
                return book;
            }
        }
        return nullptr;
    }

    void borrowBook(User *user, Book *book)
    {
        if (user != nullptr && book != nullptr && book->getAvailability())
        {
            std::cout << user->getUsername() << " has borrowed the book: " << book->getTitle() << std::endl;
            book->setAvailability(false);
        }
    }

    void returnBook(User *user, Book *book)
    {
        if (user != nullptr && book != nullptr && !book->getAvailability())
        {
            std::cout << user->getUsername() << " has returned the book: " << book->getTitle() << std::endl;
            book->setAvailability(true);
        }
    }

    void displayBookInfo(const std::string &title)
    {
        Book *book = getBook(title);
        if (book != nullptr)
        {
            std::cout << "Title: " << book->getTitle() << std::endl;
            std::cout << "Author: " << book->getAuthor() << std::endl;
            std::cout << "Availability: " << (book->getAvailability() ? "Available" : "Borrowed") << std::endl;
        }
        else
        {
            std::cout << "Book not found." << std::endl;
        }
    }

    void displayAllBooks()
    {
        if (books.empty())
        {
            std::cout << "No books available in the library." << std::endl;
        }
        else
        {
            std::cout << "Library Books: " << std::endl;
            for (Book *book : books)
            {
                std::cout << "Title: " << book->getTitle() << ", Author: " << book->getAuthor() << ", Availability: " << book->getAvailability();
            }
        }
    }

    void saveLibraryData(const Library &library, const std::string &filename)
    {
        std::ofstream file(filename);
        if (file.is_open())
        {
            // Save users
            for (const User *user : library.users)
            {
                file << "User," << user->getUsername() << "," << user->getPassword() << "," << user->getRole() << std::endl;
            }

            // Save books
            for (const Book *book : library.books)
            {
                file << "Book," << book->getTitle() << "," << book->getAuthor() << "," << book->getAvailability() << std::endl;
            }

            file.close();
            std::cout << "Library data saved successfully." << std::endl;
        }
        else
        {
            std::cerr << "Unable to save library data to file: " << filename << std::endl;
        }
    }

    void loadLibraryData(Library &library, const std::string &filename)
    {
        std::ifstream file(filename);
        if (file.is_open())
        {
            library.users.clear();
            library.books.clear();

            std::string line;
            std::getline(file, line);
            std::cout<<line;
            while (std::getline(file, line))
            {
                std::cout<<line;
                std::stringstream ss(line);
                std::string type;
                std::getline(ss, type, ',');

                if (type == "User")
                {
                    std::string username, password, role;
                    std::getline(ss, username, ',');
                    std::cout<<username;
                    std::getline(ss, password, ',');
                    std::getline(ss, role, ',');
                    library.addUser(new User(username, password, role));
                }
                else if (type == "Book")
                {
                    std::string title, author;
                    bool availability;
                    std::getline(ss, title, ',');
                    std::getline(ss, author, ',');
                    ss >> availability;
                    library.addBook(new Book(title, author));
                    library.getBook(title)->setAvailability(availability);
                }
            }

            file.close();
            std::cout << "Library data loaded successfully." << std::endl;
        }
        else
        {
            std::cerr << "Unable to load library data from file: " << filename << std::endl;
        }
    }

    void removeBook(Book *book)
    {
        books.erase(std::remove(books.begin(), books.end(), book), books.end());
    }
};
#endif//
// Created 
//

#ifndef LIBRARY_MANAGEMENT_SYSTEM_CLASSES_H
#define LIBRARY_MANAGEMENT_SYSTEM_CLASSES_H


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

class User
{
private:
    std::string username;
    std::string password;
    std::string role;

public:
    User(const std::string &u, const std::string &p, const std::string &r)
        : username(u), password(p), role(r) {}

    const std::string &getUsername() const { return username; }
    const std::string &getPassword() const { return password; }
    const std::string &getRole() const { return role; }
};

class Book
{
private:
    std::string title;
    std::string author;
    bool isAvailable;

public:
    Book(const std::string &t, const std::string &a)
        : title(t), author(a), isAvailable(true) {}

    const std::string &getTitle() const { return title; }
    const std::string &getAuthor() const { return author; }
    bool getAvailability() const { return isAvailable; }
    void setAvailability(bool available) { isAvailable = available; }
};

class Library
{
private:
    std::vector<User *> users;
    std::vector<Book *> books;

public:
    User* createUser(std::string un, std::string ps, std::string rl ){
        User user(un, ps, rl);
        return &user;
    }
    void addUser(User *user)
    {
        users.push_back(user);
    }

    User *getUser(const std::string &username)
    {
        for (User *user : users)
        {
            if (user->getUsername() == username)
            {
                return user;
            }
        }
        return nullptr;
    }

    void addBook(Book *book)
    {
        books.push_back(book);
    }

    Book *getBook(const std::string &title)
    {
        for (Book *book : books)
        {
            if (book->getTitle() == title)
            {
                return book;
            }
        }
        return nullptr;
    }

    void borrowBook(User *user, Book *book)
    {
        if (user != nullptr && book != nullptr && book->getAvailability())
        {
            std::cout << user->getUsername() << " has borrowed the book: " << book->getTitle() << std::endl;
            book->setAvailability(false);
        }
    }

    void returnBook(User *user, Book *book)
    {
        if (user != nullptr && book != nullptr && !book->getAvailability())
        {
            std::cout << user->getUsername() << " has returned the book: " << book->getTitle() << std::endl;
            book->setAvailability(true);
        }
    }

    void displayBookInfo(const std::string &title)
    {
        Book *book = getBook(title);
        if (book != nullptr)
        {
            std::cout << "Title: " << book->getTitle() << std::endl;
            std::cout << "Author: " << book->getAuthor() << std::endl;
            std::cout << "Availability: " << (book->getAvailability() ? "Available" : "Borrowed") << std::endl;
        }
        else
        {
            std::cout << "Book not found." << std::endl;
        }
    }

    void displayAllBooks()
    {
        if (books.empty())
        {
            std::cout << "No books available in the library." << std::endl;
        }
        else
        {
            std::cout << "Library Books: " << std::endl;
            for (Book *book : books)
            {
                std::cout << "Title: " << book->getTitle() << ", Author: " << book->getAuthor() << ", Availability: " << book->getAvailability();
            }
        }
    }

    void saveLibraryData(const Library &library, const std::string &filename)
    {
        std::ofstream file(filename);
        if (file.is_open())
        {
            // Save users
            for (const User *user : library.users)
            {
                file << "User," << user->getUsername() << "," << user->getPassword() << "," << user->getRole() << std::endl;
            }

            // Save books
            for (const Book *book : library.books)
            {
                file << "Book," << book->getTitle() << "," << book->getAuthor() << "," << book->getAvailability() << std::endl;
            }

            file.close();
            std::cout << "Library data saved successfully." << std::endl;
        }
        else
        {
            std::cerr << "Unable to save library data to file: " << filename << std::endl;
        }
    }

    void loadLibraryData(Library &library, const std::string &filename)
    {
        std::ifstream file(filename);
        if (file.is_open())
        {
            library.users.clear();
            library.books.clear();

            std::string line;
            std::getline(file, line);
            std::cout<<line;
            while (std::getline(file, line))
            {
                std::cout<<line;
                std::stringstream ss(line);
                std::string type;
                std::getline(ss, type, ',');

                if (type == "User")
                {
                    std::string username, password, role;
                    std::getline(ss, username, ',');
                    std::cout<<username;
                    std::getline(ss, password, ',');
                    std::getline(ss, role, ',');
                    library.addUser(new User(username, password, role));
                }
                else if (type == "Book")
                {
                    std::string title, author;
                    bool availability;
                    std::getline(ss, title, ',');
                    std::getline(ss, author, ',');
                    ss >> availability;
                    library.addBook(new Book(title, author));
                    library.getBook(title)->setAvailability(availability);
                }
            }

            file.close();
            std::cout << "Library data loaded successfully." << std::endl;
        }
        else
        {
            std::cerr << "Unable to load library data from file: " << filename << std::endl;
        }
    }

    void removeBook(Book *book)
    {
        books.erase(std::remove(books.begin(), books.end(), book), books.end());
    }
};
#endif
