#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsValid.h"
#include "clsUser.h"
using namespace std;

class clsUpdateUserScreen : public clsScreen
{
private:
    static int _ReadUserPermissions()
    {
        if ((toupper(clsValid::ReadLetter("\ndo you want to give full access to this user (Y/N) ?")) == 'Y'))
            return -1;
        else
        {
            short Permissions = 0;
            if ((toupper(clsValid::ReadLetter("\nShow clients list (Y/N) ?")) == 'Y'))
                Permissions += clsUser::enPermissions::PerShowClientList;
            if ((toupper(clsValid::ReadLetter("\nAdd new client (Y/N) ?")) == 'Y'))
                Permissions += clsUser::enPermissions::PerAddClient;
            if ((toupper(clsValid::ReadLetter("\nDelete client (Y/N) ?")) == 'Y'))
                Permissions += clsUser::enPermissions::PerDeleteClient;
            if ((toupper(clsValid::ReadLetter("\nUpdate client info (Y/N) ?")) == 'Y'))
                Permissions += clsUser::enPermissions::PerUpdateClient;
            if ((toupper(clsValid::ReadLetter("\nFind client (Y/N) ?")) == 'Y'))
                Permissions += clsUser::enPermissions::PerFindClient;
            if ((toupper(clsValid::ReadLetter("\nTransactions Menu (Y/N) ?")) == 'Y'))
                Permissions += clsUser::enPermissions::PerTransactions;
            if ((toupper(clsValid::ReadLetter("\nManage Users (Y/N) ?")) == 'Y'))
                Permissions += clsUser::enPermissions::PerManageUsers;
            if ((toupper(clsValid::ReadLetter("\nRegister Log (Y/N) ?")) == 'Y'))
                Permissions += clsUser::enPermissions::PerRegisterLog;
            if ((toupper(clsValid::ReadLetter("\nCurrency Exchance (Y/N) ?")) == 'Y'))
                Permissions += clsUser::enPermissions::PerCurrencyExchance;
            return Permissions;
        }
    }

    static void _ReadUserData(clsUser& User)
    {
        User.FirstName = clsValid::ReadString("Please enter a FirstName: ");
        User.LastName = clsValid::ReadString("Please enter a LastName: ");
        User.Email = clsValid::ReadString("Please enter a Email: ");
        User.PhoneNumber = clsValid::ReadString("Please enter a PhoneNumber: ");
        User.Password = clsValid::ReadString("Please enter a Password: ");
        User.Permission = _ReadUserPermissions();
    }

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
    static void ShowUpdateUserScreen()
    {
        
        clsScreen::DrawScreenHeader("Update User Screen");

        string Username = clsValid::ReadString("please enter Username: ");
        clsUser User = clsUser::Find(Username);
        if (!clsUser::IsEmpty(User))
        {
            cout << "\nthe following are User details:\n\n";
            _PrintUserData(User);

            if (toupper(clsValid::ReadLetter("\nAre you sure you want to update this User (Y/N) ?")) == 'Y')
            {
                _ReadUserData(User);
                User.Update();

                cout << "\nUser data Updated Successfully\n";
            }
        }
        else
            cout << "\nUser with User Name (" << Username << ") not found!";
        clsValid::CallSystem("\n\n\nPress any key to go back to Manage Users menu...");
    
    }

};
