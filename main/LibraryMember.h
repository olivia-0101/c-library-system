#pragma once

#include "LibraryUser.h" // child class inherits from LibraryUser parent class, so needs to know what it is
#include "Book.h" // includes information about books, so needs to know about the Book class
#include <vector> // includes vectors of books

using namespace std;

class LibraryMember : public LibraryUser // LibraryMember inherits from the parent class LibraryUser
{
private: // the library member's private vector list of borrowed books
	vector<Book*> borrowedBooks; // each specific book will be at a pointer

public: // public methods
	LibraryMember(int id, string n, string e, string p);

	void viewBorrowing();
	void borrowBook(Book* book); // each specific book involves a pointer
	void returnBook(Book* book);
	void reserveBook(Book* book);
	bool checkAvailability(Book* book);

	void displayUserInfo() override; // overrides the parent class version of this method to allow for the child specific version
};