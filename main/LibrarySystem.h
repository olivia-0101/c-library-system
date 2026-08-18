#pragma once

#include "LibraryUser.h" // includes information about LibraryUsers, so needs to know about the LibraryUser class
#include "Book.h" // includes information about books, so needs to know about the Book class
#include <vector> // includes vectors of books and users

using namespace std;

class LibrarySystem // LibrarySystem class
{
private: // private methods
	vector<LibraryUser*> users; // vector list of all LibraryUsers
	vector<Book*> books; // vector list of all books in the library

public: // public methods
	LibrarySystem(); // creates and runs the library system
};