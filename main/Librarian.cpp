#include "Librarian.h" // includes LibraryMember header information
#include "LibrarySystem.h" // needs to know the LibrarySystem to work
#include <iostream> // allows for cout

Librarian::Librarian(int id, string n, string e, string p, LibrarySystem* system) // giving the object attributes and also the LibrarySystem they work with
	: LibraryUser(id, n, e, p), librarySystem(system) // calling the parent class constructor to make the child object, storing the LibrarySystem - "this Librarian works in this LibrarySystem"
{
}

bool Librarian::addBook(Book* book) // adding a specific book to the LibrarySystem with a pointer
{
	return librarySystem->addBook(book); // the Librarian requests the code inside the addBook method, which is in the LibrarySystem class, and whatever answer of true or false they get, it executes it
}


bool Librarian::removeBook(Book* book) // removing a specific book from the LibrarySystem with a pointer
{
	return librarySystem->removeBook(book); // the Librarian requests the code inside the removeBook method, which is in the LibrarySystem class, and whatever answer of true or false they get, it executes it
}


bool Librarian::updateBook(Book* book, string newTitle, string newAuthor) // updating a specific book in the LibrarySystem with a pointer
{
	return librarySystem->updateBook(book, newTitle, newAuthor); // the Librarian basically requests the code inside the updateBook method, which is in the LibrarySystem class, and whatever answer of true or false they get, it executes it
}

void Librarian::displayUserInfo() // displaying user info method
{
	LibraryUser::displayUserInfo(); // has to call this because the attributes are private, polymorphism
	cout << "Librarian" << endl;
}