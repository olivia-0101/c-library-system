#include <iostream> // allows input and output
#include <vector> // for use of book vectors that will later have pointers inside of them!
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


// creating the constructor - template for the book so we can have many different Book objects
	public: // other classes can access this information
		Book(string t, string a, int i) { // placenames for the book values to be passed through
			title = t; // assigning the values
			author = a;
			ISBN = i;
			isAvailable = true; // books are available by default unless this is changed
		}


// methods

// borrowing books
	bool beBorrowed() { // is a boolean because being borrowed can either succeed or fail depending on the user's actions and system availability
		if (isAvailable) { // if the book is available then...
			isAvailable = false; // it becomes 'not available' on the system as it's borrowed successfully
			cout << "Book borrowed successfully."; // displays message
			return true; // means the borrowing has succeeded
		} 
		else {
			cout << "Requested book is unavailable."; // displays message
			return false; // means the borrowing has failed
		}
	}


// returning books
	bool beReturned() { // similar rules apply to borrowing books
		if (!isAvailable) { // if the book isn't available in the system (AKA borrowed) then...
			isAvailable = true; // the book becomes available to the system again because it will be returned
			cout << "This book " << title << " has been returned to the library."; // displays message
			return true; // means the returning has succeeded
		}
		else {
			cout << "Unable to return book."; // displays message
			return false; // means the returning has failed
		}
	}

};


// creating the User class
class User {
// creating the User attributes according to my pseudocode
	protected: // User attributes are set to protected, preventing users from outside the main superclass and subclasses from changing them
	int userID; // UserID
	string name; // User name
	string email; // User email
	string password; // User password
};


// creating the LibraryMember class
class LibraryMember : public User { // adding inheritance (LibraryMember is a kind of User)
// creating the LibraryMember attributes according to my pseudocode
	private: // LibraryMember attributes are private
	vector<Book*>borrowedBooks; // a list of pointers to books a member has borrowed


// creating the constructor so that we can have lots of different library members
	public: // others can access this information
		LibraryMember(int id, string n) { // placenames for the member values to be passed through
			userID = id; // assigning the values
			name = n;
		}

};


// creating the Librarian class
class Librarian {

};


// creating the Administrator class
class Administrator {

};


// creating the LibrarySystem class
class LibrarySystem {
// creating the LibrarySystem attributes according to my pseudocode
	private: // attributes can't be accessed by anyone else, prevents the system from breaking
		vector<Book*>books; // the library system stores all of the books by pointers
		vector<User*>users; // the library system stores all of the users by pointers
};



int main() { // start of the program
	return 0;
}
