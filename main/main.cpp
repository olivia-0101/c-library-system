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
	Librarian librarian(2, "Librarian", "librarian@library.com", "password", &library); // creating a Librarian

	while (true)
	{
		// general welcome page where users can choose their role
		cout << "Welcome to the Smart Library Management System!" << endl;
		cout << "Please select the number of your role, or 3 to exit the system:" << endl;
		cout << "1. Library Member" << endl;
		cout << "2. Librarian" << endl;
		cout << "3. Exit" << endl;

		int roleChoice; // variable that allows members to choose which role they are
		cin >> roleChoice; // allows users to input their role

		// Library Member front page menu with options
		if (roleChoice == 1) // number 1 means you are a library member, so takes you to that menu
		{
			while (true)
			{
				cout << "Welcome to the library!" << endl;
				cout << "1. Search for the book you are looking for" << endl;
				cout << "2. Check the availability of a book" << endl;
				cout << "3. Borrow a book" << endl;
				cout << "4. Return a book" << endl;
				cout << "5. View my borrowed books" << endl;
				cout << "6. Exit" << endl;

				int choice;
				cin >> choice; // user can input the number they want the system to execute

				///

				// menu pathways
				if (choice == 1) // option 1 (searching)
				{
					string title; // title variable that will contain the title the user inputs

					cout << "Please enter the title of the book you are looking for: "; // display message
					cin.ignore();
					getline(cin, title); // get rid of the leftover enter key, process the user's answer

					vector<Book*> results = library.searchByTitle(title); // system will search through all books in the library by title

					if (results.empty()) // if it cannot find that title
					{
						cout << "There is no book available with that title." << endl; // display message for failure
					}
					else
					{
						for (Book* book : results) // when it finds the specific book
						{
							book->displayBookInfo(); // will display info about the book
						}
					}
				}

				if (choice == 2) // option 2 (availability checker)
				{
					string title; // title variable that will contain the title the user inputs

					cout << "Please enter the title of the book you are looking for: "; // display message
					cin.ignore();
					getline(cin, title); // get rid of the leftover enter key, process the user's answer

					vector<Book*> results = library.searchByTitle(title); // system will search through all books in the library by title

					if (results.empty()) // if it cannot find that title
					{
						cout << "There is no book available with that title." << endl; // display message for failure
					}
					else
					{
						for (Book* book : results) // when it finds the specific book
						{
							library.checkAvailability(book); // library will check the availability
						}
					}
				}

				if (choice == 3) // option 3 (borrowing)
				{
					string title; // title variable that will contain the title the user inputs

					cout << "Please enter the title of the book you are looking for: "; // display message
					cin.ignore();
					getline(cin, title); // get rid of the leftover enter key, process the user's answer

					vector<Book*> results = library.searchByTitle(title); // system will search through all books in the library by title

					if (results.empty()) // if it cannot find that title
					{
						cout << "There is no book available with that title." << endl; // display message for failure
					}
					else
					{
						member1.borrowBook(results[0]); // asks the library for the first book it finds, to borrow it
					}
				}

				if (choice == 4) // option 4 (returning)
				{
					string title; // title variable that will contain the title the user inputs

					cout << "Please enter the title of the book you are looking for: "; // display message
					cin.ignore();
					getline(cin, title); // get rid of the leftover enter key, process the user's answer

					vector<Book*> results = library.searchByTitle(title); // system will search through all books in the library by title

					if (results.empty()) // if it cannot find that title
					{
						cout << "There is no book available with that title." << endl; // display message for failure
					}
					else
					{
						if (member1.hasBorrowedBook(results[0])) // asks the member for the first book it finds, to return it
						{
							member1.returnBook(results[0]);
						}
						else
						{
							cout << "You have not borrowed this book." << endl;
						}
					}
				}


				if (choice == 5) // option 5 (viewing borrowed books)
				{
					member1.viewBorrowing();
				}

				if (choice == 6) // option 6 (exit)
				{
					cout << "Returning to role selection!" << endl; // display message
					break; // stops the loop and returns to the Librarian menu
				}

			}
		}

		if (roleChoice == 2) // number 2 means you are a librarian, so takes you to that menu
		{
			while (true) // loops the menu
			{
				cout << "Welcome to the Librarian menu!" << endl;
				cout << "1. Add a book" << endl;
				cout << "2. Remove a book" << endl;
				cout << "3. Update a book" << endl;
				cout << "4. Exit" << endl;

				int librarianChoice; // variable allowing the Librarian to enter their choice
				cin >> librarianChoice;

				if (librarianChoice == 1) // if the Librarian chooses 1 (add a book)
				{
					int id;
					string title;
					string author; // book attributes

					cout << "Enter the book ID: ";
					cin >> id; // enter the ID

					cout << "Enter the title: ";
					cin.ignore();
					getline(cin, title); // enter the title

					cout << "Enter the author: ";
					getline(cin, author); // enter the author

					Book* newBook = new Book(id, title, author); // the specific book is made with a pointer

					librarian.addBook(newBook); // this is added to the librarian's addBook method
				}

				if (librarianChoice == 2) // if the Librarian chooses 2 (remove a book)
				{
					string title; // searching for the book via title

					cout << "Enter the title of the book you wish to remove from the system: "; // asks the user to input a title
					cin.ignore();
					getline(cin, title); // input the title

					Book* bookToRemove = library.findBook(title); // finds the specific book from the library

					if (bookToRemove != nullptr) // if it finds the specific book...
					{
						librarian.removeBook(bookToRemove); // removes the book from the library
					}
					else
					{
						cout << "Book could not be found." << endl; // otherwise if it fails, displays this message
					}
				}

				if (librarianChoice == 3) // if the Librarian chooses 3 (update a book)
				{
					string title;
					string newTitle;
					string newAuthor; // book attributes

					cout << "Enter the title of the book you want to update: " << endl; // asking for a new title
					cin.ignore();
					getline(cin, title); // user input

					Book* bookToUpdate = library.findBook(title); // finding the specific book by title

					if (bookToUpdate != nullptr) // if the specific book is found...
					{
						cout << "Enter the updated title: "; // asking for the updated title
						getline(cin, newTitle);

						cout << "Enter the updated author: "; // asking for the updated author
						getline(cin, newAuthor);

						librarian.updateBook(bookToUpdate, newTitle, newAuthor); // the Librarian updates this book
					}
					else
					{
						cout << "The book you have searched for could not be found." << endl; // failure display message
					}
				}

				if (librarianChoice == 4) // if the Librarian chooses 4 (exit)
				{
					cout << "Returning to role selection!" << endl; // display message
					break; // stops the loop and returns to the Librarian menu
				}
			}
		}

		if (roleChoice == 3) // number 3 exits the entire system
		{
			cout << "Thank you for using the library; have a nice day! This program will now close." << endl;
			break;
		}
	}
}