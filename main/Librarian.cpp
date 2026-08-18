#include "Librarian.h" // includes LibraryMember header information
#include <iostream> // allows for cout

Librarian::Librarian(int id, string n, string e, string p)
	: LibraryUser(id, n, e, p) // calling the parent class constructor to make the child object
{
}

// cannot do methods yet because I need to do the Library System class