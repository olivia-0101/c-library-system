#pragma once

#include <string>

using namespace std;

enum class BookStatus
{
	Available,
	Borrowed,
	Reserved
};

class Book
{
private:
	string title;
	string author;
	int bookId;
	BookStatus status;
	string dueDate;

public:
	Book(int id, string t, string a);
	void borrow();
	void returnBook();
	BookStatus getStatus();
	void displayBookInfo();

};