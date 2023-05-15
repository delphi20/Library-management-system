#include <iostream>
#include <string>
#include <vector>
#include<fstream>
#include "classes.h"
#include "functions.h"
using namespace std;

int main()
{
    Library library;
    library.loadLibraryData(library, "library_data.txt");
    //system("cls");
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;
    User *user = library.getUser(username);

    if (user != nullptr && user->getPassword() == password)
    {
        std::cout << "\nLogin successful!" << std::endl;
        if (user->getRole() == "admin")
        {
            std::cout << "\nWelcome to Admin Portal!!" << std::endl;
            performAdminOperations(library);
        }
        else
        {
            std::cout << "Welcome to User Portal!!" << std::endl;
            performUserOperations(library, user);
        }
    }
    else
    {
        std::cout << "Login failed. Please try again." << std::endl;
    }

    library.saveLibraryData(library, "library_data.txt");

    return 0;
}