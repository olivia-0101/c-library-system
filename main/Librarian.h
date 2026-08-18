#pragma once

#include "LibraryUser.h" // child class inherits from LibraryUser parent class, so needs to know what it is
#include "Book.h" // includes information about books, so needs to know about the Book class

using namespace std;

class Librarian : public LibraryUser // Librarian inherits from the parent class LibraryUser
{
public: // public methods
	Librarian(int id, string n, string e, string p);

	void addBook(Book* book);
	void updateBook(Book* book);
	void removeBook(Book* book);
};