#include <iostream>
#include "Book.h"

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