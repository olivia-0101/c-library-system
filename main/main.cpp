#include <iostream> // allows input and output
#include <vector> // for use of book vectors that will later have pointers inside of them!
#include <string> // for all of the different string attributes
#include "Book.h" // including all the classes
#include "LibraryUser.h"
#include "LibraryMember.h"
#include "Librarian.h"
#include "LibrarySystem.h"

using namespace std; // efficiency, removes the need to type in std:: each time

int main()
{
	LibrarySystem library; // creating the empty library system

	Book book1(1, "Alice's Adventures in Wonderland", "Lewis Carroll"); // creating book number 1 according to the book constructor
	Book book2(2, "Pride and Prejudice", "Jane Austen"); // same process as book 1, adding all of the other books below!
	Book book3(3, "A Christmas Carol", "Charles Dickens");
	Book book4(4, "King Lear", "William Shakespeare");
	Book book5(5, "The Picture of Dorian Gray", "Oscar Wilde");
	Book book6(6, "The Bell Jar", "Sylvia Plath");

	library.addBook(&book1); // addBook wants a pointer to a book, so we give it book1 and the & points to its address; this then gets added to the library
	library.addBook(&book2); // same process with the rest of the books, adding them to the library
	library.addBook(&book3);
	library.addBook(&book4);
	library.addBook(&book5);
	library.addBook(&book6);

	LibraryMember member1(1, "Jane", "Jane@gmail.com", "pass"); // creating a Library Member

	// creating a front page menu with options
	cout << "Welcome to the library!" << endl;
	cout << "1. Search for the book you are looking for" << endl;
	cout << "2. Check the availability of a book" << endl;
	cout << "3. Borrow a book" << endl;
	cout << "4. Return a book" << endl;
	cout << "5. View my borrowed books" << endl;
	cout << "6. Exit" << endl;

	int choice;
	cin >> choice; // user can input thw number they want the system to execute

	return 0;
}