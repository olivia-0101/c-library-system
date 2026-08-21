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
	LibrarySystem library; // creating the empty library
	Book book1(1, "Alice's Adventures in Wonderland", "Lewis Carroll"); // creating a random book according to the book constructor
	library.addBook(&book1); // addBook wants a pointer to a book, so we give it book1 and the & points to its address; this then gets added to the library

	Book book2(2, "Pride and Prejudice", "Jane Austen");
	library.addBook(&book2); // adding the second book to see if it works

	Book book3(3, "A Christmas Carol", "Charles Dickens");
	library.addBook(&book3);

	Book book4(4, "King Lear", "William Shakespeare");
	library.addBook(&book4);

	Book book5(5, "The Picture of Dorian Gray", "Oscar Wilde");
	library.addBook(&book5);

	Book book6(6, "The Bell Jar", "Sylvia Plath");
	library.addBook(&book6);

	LibraryMember member1(1, "Bob", "Bob@gmail.com", "pass"); // testing creating a Library Member

	member1.borrowBook(&book1); // testing borrowing
	member1.borrowBook(&book2);
	member1.borrowBook(&book3);
	member1.borrowBook(&book4);
	member1.borrowBook(&book5);
	member1.borrowBook(&book6); // checking the borrowing limit

	return 0;
}