#include "Book.h" // includes Book header information
#include <iostream> // allows for cout

Book::Book(int id, string t, string a) // template for creating a Book object
{
	bookId = id; // attributes
	title = t;
	author = a;
	status = BookStatus::Available; // each book starts as Available as per pseudocode
	dueDate = "";
}

void Book::borrow() // borrowing method
{
	status = BookStatus::Borrowed; // sets the book's status to 'Borrowed'
}

void Book::returnBook() // returning method
{
	status = BookStatus::Available; // sets the book's status back to 'Available' without directly changing the private status variable
}

void Book::reserve() // reserving books
{
	status = BookStatus::Reserved;
}

BookStatus Book::getStatus() // showing the book's status method
{
	return status; // simply displays it
}

void Book::displayBookInfo() // method for displaying a book's info
{
	cout << "ID: " << bookId << endl; // attributes will be displayed as per pseudocode
	cout << "Title: " << title << endl;
	cout << "Author: " << author << endl;

	if (status == BookStatus::Available) // if a book is 'Available'
	{
		cout << "Status: Available" << endl;
	}
	else if (status == BookStatus::Reserved) // if a book is 'Reserved'
	{
		cout << "Status: Reserved" << endl;
	}
	else if (status == BookStatus::Borrowed) // if a book is 'Borrowed'
	{
		cout << "Status: Borrowed" << endl;
	}
}

string Book::getTitle() // getter that grabs the book's title (private attribute) and allows it to be seen
{
	return title;
}

string Book::getAuthor() // getter that grabs the book's author (private attribute) and allows it to be seen
{
	return author;
}

void Book::updateBookInfo(string newTitle, string newAuthor) // book is responsible for changing its own title and author
{
	title = newTitle;
	author = newAuthor;
}