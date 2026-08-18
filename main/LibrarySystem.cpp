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