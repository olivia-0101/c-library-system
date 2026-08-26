#include <iostream>
#include "Book.h"
#include "LibraryMember.h"
#include "Librarian.h"
#include "LibrarySystem.h"

using namespace std;

void testBookBorrow() // book borrowing test - used in main.cpp
{
	Book testBook(111, "Test Book", "Test Author");

	testBook.borrow();

	if (testBook.getStatus() == BookStatus::Borrowed) // if borrowed then...
	{
		cout << "TEST PASSED: book was successfully borrowed!" << endl; // success message
	}
	else
	{
		cout << "TEST FAILED: book was not successfully borrowed." << endl; // failure message
	}
}

void testBookReturn() // book returning test - used in main.cpp
{
	Book testBook(112, "Test Book 2", "Test Author");

	testBook.borrow();
	testBook.returnBook();

	if (testBook.getStatus() == BookStatus::Available) // if the book becomes available then...
	{
		cout << "TEST PASSED: book was successfully returned!" << endl; // success message
	}
	else
	{
		cout << "TEST FAILED: book was not successfully returned." << endl; // failure message
	}
}

void testBorrowingLimit() // testing the borrowing limit of 5 books maximum
{
	LibraryMember testMember(001, "Test", "test@gmail.com", "pass"); // creating a placeholder library member

	Book book1(1, "Book1", "Author");
	Book book2(2, "Book2", "Author");
	Book book3(3, "Book3", "Author");
	Book book4(4, "Book4", "Author");
	Book book5(5, "Book5", "Author");
	Book book6(6, "Book6", "Author"); // all 6 placeholder books

	testMember.borrowBook(&book1);
	testMember.borrowBook(&book2);
	testMember.borrowBook(&book3);
	testMember.borrowBook(&book4);
	testMember.borrowBook(&book5); // borrowing 5 books

	Book* sixthBook = &book6;
	testMember.borrowBook(sixthBook); // the 6th book borrow

	if (book6.getStatus() == BookStatus::Available) // if book stays available...
	{
		cout << "TEST PASSED: the borrowing limit is 5, so the 6th book is rejected." << endl; // success message
	}
	else
	{
		cout << "TEST FAILED: limit was not reinforced, member borrowed a 6th book." << endl; // failure message
	}
}

void testLibrarianAddBook() // testing the Librarian adding a book to the system
{
	LibrarySystem testLibrary; // creating a test library
	Librarian testLibrarian(102, "Test Librarian", "librarian@gmail.com", "pass", &testLibrary); // creating a placeholder Librarian

	Book* newBook = new Book(100, "Test Added Book", "Test Added Author"); // new test book

	bool result = testLibrarian.addBook(newBook); // Librarian adds the test book to the test library

	if (result == true) // if it works...
	{
		cout << "TEST PASSED: Librarian has added a book." << endl; // success message
	}
	else
	{
		cout << "TEST FAILED: Librarian has not added a book." << endl; // failure message
	}
}