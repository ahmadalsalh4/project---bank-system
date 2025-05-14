#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsValid.h"
#include "clsUser.h"
using namespace std;

class clsUsersList : public clsScreen
{
private:
    static void _PrintUserDataInList(clsUser User)
    {
        cout << "| " << setw(13) << left << User.GetUserName();
        cout << " | " << setw(22) << left << User.FullName();
        cout << " | " << setw(20) << left << User.Email;
        cout << " | " << setw(11) << left << User.PhoneNumber;
        cout << " | " << setw(12) << left << User.Password;
        cout << " | " << setw(10) << right << User.Permission << " |";
    }

public:
	static void ShowUsersListScreen() 
	{
        vector <clsUser> VUsers = clsUser::GetUsersList();

        clsScreen::DrawScreenHeader("Users List Screen",
            "Users List(" + to_string( VUsers.size()) + ") User(s)");

        cout << "__________________________________________________________________________________________________________\n";
        cout << "| " << setw(13) << left << "UserName";
        cout << " | " << setw(22) << left << "FullName";
        cout << " | " << setw(20) << left << "Email";
        cout << " | " << setw(11) << left << "PhoneNumber";
        cout << " | " << setw(12) << left << "Password";
        cout << " | " << setw(10) << left << "Permission" << " |\n";
        cout << "__________________________________________________________________________________________________________\n";
        if (!(VUsers.size() == 0))
        {
            for (clsUser& User : VUsers)
            {
                _PrintUserDataInList(User);
                cout << endl;
            }
        }
        else
            cout << "\t\t\t\t  No Users Found.            \n";

        cout << "__________________________________________________________________________________________________________";

        clsValid::CallSystem("\n\n\nPress any key to go back to Manage Users menu...");
        
	}

};
