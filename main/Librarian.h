#pragma once

#include "LibraryUser.h" // child class inherits from LibraryUser parent class, so needs to know what it is
#include "Book.h" // includes information about books, so needs to know about the Book class

using namespace std;

class LibrarySystem; // writing this so it knows about the LibrarySystem class

class Librarian : public LibraryUser // Librarian inherits from the parent class LibraryUser
{
private:
	LibrarySystem* librarySystem; // giving each Librarian object a pointer to the LibrarySystem

public: // public methods
	Librarian(int id, string n, string e, string p, LibrarySystem* system); // when we create a Librarian object we also give them the LibrarySystem system

	bool addBook(Book* book);
	bool updateBook(Book* book);
	bool removeBook(Book* book);
};