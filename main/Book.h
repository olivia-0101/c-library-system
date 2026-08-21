#pragma once

#include <string>

using namespace std;

enum class BookStatus // allows BookStatus to be set to three different states rather than a boolean true/false availability system
{
	Available,
	Borrowed,
	Reserved
};

class Book
{
private: // private attributes of the Book class
	string title;
	string author;
	int bookId;
	BookStatus status;
	string dueDate;

public: // all of its public methods according to the pseudocode
	Book(int id, string t, string a);
	void borrow();
	void reserve();
	void returnBook();
	BookStatus getStatus();
	void displayBookInfo();
	string getTitle();
	string getAuthor();
	void updateBookInfo(string newTitle, string newAuthor);

};