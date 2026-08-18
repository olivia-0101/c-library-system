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


bool LibrarySystem::addBook(Book* book) // adding a book to the library method
{
	if (findBook(book->getTitle()) != nullptr) // if the library cannot find this book already in the library, it gives us nullptr (nothing), so != nullptr means it found the same book already in the library
	{
		cout << "This book is already in the library." << endl; // display message according to pseudocode
		return false; // cannot add book as it's already in the library
	}

	books.push_back(book); // else add the book to the end of the book vector list, and into the library

	cout << "Book added successfully to the library." << endl; // display message according to pseudocode
	return true; // successful adding of book
}


bool LibrarySystem::removeBook(Book* book) // removing a book from the library method
{
	if (findBook(book->getTitle()) == nullptr) // if the library cannot find this book already in the library, it gives us nullptr (nothing)
	{
		cout << "This book isn't in the library." << endl; // display message according to pseudocode
		return false; // cannot remove book as it doesn't exist in the library
	}

	books.erase( // else remove the book from the end of the book vector list
		remove(books.begin(), books.end(), book),
		books.end()
	);

	cout << "Book removed from the library." << endl; // display message according to pseudocode
	return true; // successful removal of book
}


bool LibrarySystem::updateBook(Book* book, string newTitle, string newAuthor) // updating a book method
{
	if (findBook(book->getTitle()) == nullptr) // if the library cannot find this book already in the library, it gives us nullptr (nothing)
	{
		cout << "Requested book couldn't be found." << endl; // display message according to pseudocode
		return false; // cannot update book as it doesn't exist in the library
	}

	book->updateBookInfo(newTitle, newAuthor); // updates the title and author of the specific book

	cout << "Book information has been updated successfully." << endl; // display message according to pseudocode
	return true; // updates the book
}