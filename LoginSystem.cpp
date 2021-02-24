// #include <stdafx.h>
#include <iostream>
#include <string>
// #include <windows.h>
#include <fstream>
#include <sys/stat.h>

using namespace std;

void Login();
void Register();
int main();
int main() {
	bool again;
	int selection;


	cout << "Login System C++\n";
	cout << "Bugs is everywhere:)\n 1 == Login \n 2 == Register \n 3 == Exit() \n";

	cout << ">> ";
	cin >> selection;
	if (selection == 1) {
		Login();
	} else if (selection == 2) {
		Register();
	} else if (selection == 3) {
		cout << "Bye!\n";
		again = false; 
	}
}

void Register() {
	// fixed bugs 
	fstream reg; // load files to register
	string usrname;
	string usrpass;
	cout << "Enter your username: ";
	cin.get(); // skip some lines for getline, otherwise it won't work.
	getline(cin, usrname);
	if (usrname.empty()) { // if user leaves username section is empty
		cout << "Here's empty, I will came again, username is empty:)\n";
		Register(); //return back to registration.
	} else if (usrname.length() < 10) { //check if length is smaller than 4
		cout << "Minimum username length should be 10 characters ++\n";
		Register(); 
	} else { //if everything is fine get password
		cout << "Enter Password: ";
		getline(cin, usrpass); //get [password and start intialization]
		if (usrpass.empty()) {  //if password is empty cancel registration 
			cout << "U dont have password! Check again: \n";
			Register(); //return back to first registration line
		} else if (usrpass.length() < 10) { //for security (You will be hacked!)
			cout << "Your password can't be less than 10 characters! \n";
			Register(); //return back
		} else { //if everything is fine do this
			reg.open(usrname.c_str(), fstream::out); //create and open user file.
			reg << usrpass; //write to file
			reg.close(); //close file
			cout << "Registration complete. Returning you to main menu!. \n\n\n";
			main();
		}
	}
}

void Login() {
	// start login
	ifstream checklog;
	string username;
	string password;
	string output;
	cout << "Hi There! Login. Your username? : \n";
	cout << ">> ";
	cin.get();
	getline(cin, username);
	if (username.empty()){
		cout << "Dont play with me! You didn't entered anything. \n Returning to main \n";
		main();
	} else {
		checklog.open(username);
		if (checklog) {
			checklog >> output;
			cout << "Enter password: \n";
			cout << ">> ";
			cin >> password;
				if (password == output) {
					cout << "Login succesful. \n\n";
					main();
				} else {
					cout << "Password is wrong! \n";
					main();
				}
		} else {
			cout << "Username does not exists \n";
			main();
		}
	}
}