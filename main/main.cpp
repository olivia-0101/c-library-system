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
	return 0;
}