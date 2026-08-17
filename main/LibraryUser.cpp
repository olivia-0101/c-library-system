#include "LibraryUser.h" // includes LibraryUser header information
#include <iostream> // allows for cout

LibraryUser::LibraryUser(int id, string n, string e, string p) // template for creating a LibraryUser object
{
	userId = id; // attributes
	name = n;
	email = e;
	password = p;
}

void LibraryUser::displayUserInfo() // displaying user info method
{
	cout << "ID: " << userId << endl;
	cout << "Name: " << name << endl;
	cout << "Email: " << email << endl; // doesn't display password
}