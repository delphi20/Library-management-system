#include <iostream>
#include <string>
#include <vector>
#include<fstream>
#include "classes.h"
#include "functions.h"
using namespace std;

int main()
{
    string line;
    Library library;
    library.loadLibraryData(library, "library_data.txt");
    fstream file("library_data.txt");
    getline(file, line);
    cout<<line;
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;
    User *user = library.getUser(username);

    if (user != nullptr && user->getPassword() == password)
    {
        std::cout << "Login successful!" << std::endl;
        if (user->getRole() == "admin")
        {
            std::cout << "Welcome admin!" << std::endl;
            performAdminOperations(library);
        }
        else
        {
            std::cout << "Welcome user!" << std::endl;
            performUserOperations(library, user);
        }
    }
    else
    {
        cout<<user;
        std::cout << "Login failed. Please try again." << std::endl;
    }

    library.saveLibraryData(library, "library_data.txt");

    return 0;
}