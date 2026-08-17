#include "LibraryMember.h" // includes LibraryMember header information
#include <iostream> // allows for cout

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

bool LibraryMember::checkAvailability() // return true if the book is available, otherwise return false
{
	return book->getStatus() == BookStatus::Available;
}

