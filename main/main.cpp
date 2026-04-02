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
			cout << "This book \"" << title << "\" has been returned to the library."; // displays message
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

// creating the constructor so that we can have lots of different Users
public: // others can access this information
	User(int id, string n, string e, string p) { // placenames for the User values to be passed through
		userID = id; // UserID
		name = n;
		email = e;
		password = p;
	}
};


// creating the LibraryMember class
class LibraryMember : public User { // adding inheritance (LibraryMember is a kind of User)
// creating the LibraryMember attributes according to my pseudocode
	private: // LibraryMember attributes are private
	vector<Book*>borrowedBooks; // a list of pointers to books a member has borrowed

// constructor
public: // allows creation of a library member in main()
	LibraryMember(int id, string n, string e, string p)
		: User(id, n, e, p) { // takes the values from User (inheritance)
		}


// methods

// (LibraryMember) borrowing a book
	bool borrowBook(Book* book) { // boolean to borrow a specific book with pointers

		if (borrowedBooks.size() >= 5) { // if the amount of books they've borrowed is >= 5 (borrowing limit)
			cout << "Cannot borrow more than five books at a time." << endl; // display message
			return false; // means borrowing failed
		}

		if (book->beBorrowed()) { // pointer to if the specific book is borrowed, calling method from Book class
			borrowedBooks.push_back(book); // adds book to the end of the member's list of books
			cout << "Book borrowed successfully." << endl; // display message
			return true; // means borrowing successful
		}

		cout << "Book is not available." << endl; // display message
		return false; // if borrowing fails in general regardless
	}


// (LibraryMember) returning a book
	bool returnBook(Book* book) { // boolean to return a specific book with pointers

		for (int i = 0; i < borrowedBooks.size(); i++) { // for loop that goes through every book the member has borrowed

		if (borrowedBooks[i] == book) { // if the specific book found in the list is the one we want...
			book->beReturned(); // pointer to the specific book to call the Book's beReturned function
			borrowedBooks.erase(borrowedBooks.begin() + i); // erase the book (return it)

			cout << "This book \"" << title << "\" has been returned to the library." << endl; // display message
			return true; // the returning worked
			}
		}

		cout << "Book not found." << endl; // display message
		return false; // if returning fails in general regardless
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
	Book b1("Alice in Wonderland", "Lewis Carroll", 123);
	LibraryMember User1(150, "Mary", "mary@gmail.com", "abcde");

	User1.borrowBook(&b1);
	return 0;
}
