#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsValid.h"
#include "clsUser.h"
using namespace std;

class clsFindUser : public clsScreen
{
private:
    static void _PrintUserData(clsUser User)
    {
        cout << "User details: \n";
        cout << "________________________________________" << endl;

        cout << "First Name  : " << User.FirstName << endl;
        cout << "Last Name   : " << User.LastName << endl;
        cout << "FullName    : " << User.FullName() << endl;
        cout << "Email       : " << User.Email << endl;
        cout << "PhoneNumber : " << User.PhoneNumber << endl;
        cout << "UserName    : " << User.GetUserName() << endl;
        cout << "Password    : " << User.Password << endl;
        cout << "Permissions : " << User.Permission << endl;
        cout << "________________________________________" << endl;
    }

public:
    static void ShowFindUserScreen()
    {
        
        clsScreen::DrawScreenHeader("Find User Screen");

        string Username = clsValid::ReadString("please enter Username: ");
        clsUser User = clsUser::Find(Username);
        if (!clsUser::IsEmpty(User))
        {
            cout << "\nthe following are User details:\n\n";
            _PrintUserData(User);
        }
        else
            cout << "\nUser with User Name (" << Username << ") not found!";
        clsValid::CallSystem("\n\n\nPress any key to go back to Manage Users menu...");
        
    }

};
