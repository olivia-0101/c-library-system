#pragma once

#include <string>

using namespace std;

class LibraryUser // private attributes of the LibraryUser class
{
private:
	int userId;
	string name;
	string email;
	string password;

public: // its public method according to pseudocode
	LibraryUser(int id, string n, string e, string p);

	virtual void displayUserInfo(); // virtual will allow the children of this parent class to use their own version of displayUserInfo
};