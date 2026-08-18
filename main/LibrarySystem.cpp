#include "LibrarySystem.h"
#include <iostream>
#include <algorithm>

LibrarySystem::LibrarySystem() // function that gets called when we create a LibrarySystem object
{
}

vector<Book*> LibrarySystem::searchByTitle(string title) // search by title method
{
	vector<Book*> results; // results vector begins empty

	for (Book* book : books) // goes through all books in a for loop
	{
		if (book->getTitle() == title) // if the specific pointer book has the title we need...
		{
			results.push_back(book); // books with the correct title get added to it
		}
	}
	return results; // results are then shown
}


vector<Book*> LibrarySystem::searchByAuthor(string title) // search by author method
{
	vector<Book*> results; // results vector begins empty

	for (Book* book : books) // goes through all books in a for loop
	{
		if (book->getAuthor() == author) // if the specific pointer book has the author we need...
		{
			results.push_back(book); // books with the correct author get added to it
		}
	}
	return results; // results are then shown
}


bool LibrarySystem::checkAvailability(Book* book) // checking book availability method
{
	return book->getStatus() == BookStatus::Available; // if the book is available will return true, if not will return false
}


void LibrarySystem::sendAlert() // sending alerts
{
	cout << "Library system alert." << endl; // *****haven't figured out how I want the alerts to appear on the system yet, will return to this!
}


void LibrarySystem::handleReservations() // handling reservations
{
	cout << "Library reservations handled." << endl; // *****haven't figured out how I want the alerts to appear on the system yet, will return to this!
}


Book* LibrarySystem::findBook(string title) // finding a particular book method
{
	for (Book* book : books) // goes through all books in a for loop
	{
		if (book->getTitle() == title) // if the specific pointer book has the title we need...
		{
			return book; // gives us the first book
		}
	}
	return nullptr; // otherwise returns nothing
}


