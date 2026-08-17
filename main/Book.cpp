#include "Book.h"
#include <iostream>

Book::Book(int id, string t, string a)
{
	bookId = id;
	title = t;
	author = a;
	status = BookStatus::Available;
	dueDate = "";
}

void Book::borrow()
{
	status = BookStatus::Borrowed;
}

void Book::returnBook()
{
	status = return status;
}

void Book::displayBookInfo()
{

}