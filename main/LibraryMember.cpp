#include "LibraryMember.h" // includes LibraryMember header information
#include <iostream> // allows for cout
#include <algorithm>

LibraryMember::LibraryMember(int id, string n, string e, string p)
	: LibraryUser(id, n, e, p) // calling the parent class constructor to make the child object
{
}

void LibraryMember::viewBorrowing() // library member keeps track of which books they've borrowed, meanwhile book itself is responsible for its attributes
{
	cout << "Borrowed books: " << endl;
	for (Book* book : borrowedBooks) // for loop goes through each book at a time and calls each object book
	{
		book->displayBookInfo(); // specifies to go to the book referred to by the pointer; then call the method on this particular book
	}
}

bool LibraryMember::checkAvailability(Book* book) // return true if the book is available, otherwise return false
{
	return book->getStatus() == BookStatus::Available;
}

void LibraryMember::borrowBook(Book* book) // method for borrowing books
{
	if (borrowedBooks.size() >= 5) // if the user has five books already...
	{
		cout << "You have reached your borrowing limit." << endl; // displays as written in pseudocode
		return;
	}

	if (checkAvailability(book)) // if the book is available
	{
		book->borrow(); // that specific book at the pointer will be borrowed
		borrowedBooks.push_back(book); // adds the book on the end of the vector of borrowedBooks

		book->setDueDate("14 days from borrowing."); // displaying how long to borrow for

		cout << "You have successfully borrowed " << book->getTitle() << "." << endl; // getTitle method allows us to display the specific title of the book the user has borrowed
		cout << "Due date: 14 days from borrowing." << endl; // display message about when to return
	}

	else
	{
		cout << "This book is currently unavailable." << endl; // if the book is unavailable, display this message as per pseudocode
	}
} 

void LibraryMember::returnBook(Book* book) // method for returning books
{
	book->returnBook(); // asking the book to change its status back to 'Available'
	book->setDueDate(""); // erases the due date

	borrowedBooks.erase( // removing the book from the user's vector list
		remove(borrowedBooks.begin(), borrowedBooks.end(), book),
		borrowedBooks.end()
	);

	cout << "You have successfully returned " << book->getTitle() << "." << endl; // getTitle method allows us to display the specific title of the book the user has returned
}

void LibraryMember::reserveBook(Book* book) // method to reserve books
{
	if (book->getStatus() == BookStatus::Borrowed) // if the book is currently borrowed...
	{
		book->reserve();
		cout << "You have successfully reserved " << book->getTitle() << "." << endl; // we reserve it
	}
	else if (book->getStatus() == BookStatus::Reserved) // if the book is currently already reserved...
	{
		cout << "This book is already reserved." << endl; // we cannot reserve it
	}
	else // if the book is freely available...
	{
		cout << "This book is currently available, you can borrow it." << endl; // we are pushed to borrow instead
	}
}

void LibraryMember::displayUserInfo() // displaying user info method
{
	LibraryUser::displayUserInfo(); // has to call this because the attributes are private
	cout << "Library Member" << endl;
}

bool LibraryMember::hasBorrowedBook(Book* book) // checking what books the library member has borrowed
{
	for (Book* borrowedBook : borrowedBooks) // for loop going through all the borrowed books, checks "is this the book we're looking for?"
	{
		if (borrowedBook == book) // if it's the book we're looking for...
		{
			return true; // confirm they have that book
		}
	}

	return false; // otherwise they don't have that book

}