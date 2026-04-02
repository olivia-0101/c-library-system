#include <iostream> // allows input and output
#include <vectors> // for use of book vectors that will later have pointers inside of them!
#include <string> // for all of the different string attributes

using namespace std; // efficiency, removes the need to type in std:: each time


// creating the Book class
class Book {
// creating its attributes according to my pseudocode
	private: // the Book's attributes are set to private, preventing users from tampering with them
	string title; // Book title
	string author; // Book author
	int ISBN; // Book ISBN
	int dueDate; // Book due date
	bool isAvailable; // Book availability boolean
};


// creating the User class
class User {
// creating the User attributes according to my pseudocode
	protected: // User attributes are set to protected, preventing users from outside the main superclass and subclasses from changing them
	int UserID; // UserID
	string name; // User name
	string email; // User email
	string password; // User password
};


// creating the LibraryMember class
class LibraryMember {
	private: // LibraryMember attributes are private
	vector<Book*>borrowedBooks; // a list of pointers to books a member has borrowed
};


// creating the Librarian class
class Librarian {

};


// creating the Administrator class
class Administrator {

};


// creating the LibrarySystem class
class LibrarySystem {

};



int main() { // start of the program
	return 0;
}