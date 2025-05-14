#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsValid.h"
#include "clsUsersList.h"
#include "clsFindUser.h"
#include "clsAddUser.h"
#include "clsDeleteUser.h"
#include "clsUpdateUserScreen.h"
using namespace std;

class clsManageUsersScreen : public clsScreen
{
private:
    enum enManageUsersMenuCases {
        enListUsers = 1, enAddNewUser, enDeleteUser, enUpdateUser,
        enFindUser, enMainMenu
    };

    static void _DrawManageUsersMenu()
    {
        clsScreen::DrawScreenHeader("Manage Users Screen", "Manage Users Menu");

        cout << "\t\t\t\t[1] List Users.\n";
        cout << "\t\t\t\t[2] Add New User.\n";
        cout << "\t\t\t\t[3] Delete User.\n";
        cout << "\t\t\t\t[4] Update User.\n";
        cout << "\t\t\t\t[5] Find User.\n";
        cout << "\t\t\t\t[6] Main Menu.\n";
    }

    static void _UsersList()
    {
        clsUsersList::ShowUsersListScreen();
    }

    static void _FindUser()
    {
        clsFindUser::ShowFindUserScreen();
    }

    static void _AddUser()
    {
        clsAddUser::ShowAddUserScreen();
    }

    static void _DeleteUser()
    {
        clsDeleteUser::ShowDeleteUserScreen();
    }

    static void _UpdateUser()
    {
        clsUpdateUserScreen::ShowUpdateUserScreen();
    }

public:
    static void ShowManageUsersMenu()
    {
        char Choice;
        do
        {
            _DrawManageUsersMenu();
            Choice = (enManageUsersMenuCases)clsValid::ReadIntNumber("\t\t\t\tChoose what do you want to do [1-6] : ", 1, 6, "\t\t\t\tInvalid input, Choose what do you want to do [1-6] : ");
            switch (Choice)
            {
            case (enManageUsersMenuCases::enListUsers):
                _UsersList();
                break;
            case (enManageUsersMenuCases::enAddNewUser):
                _AddUser();
                break;
            case (enManageUsersMenuCases::enDeleteUser):
                _DeleteUser();
                break;
            case (enManageUsersMenuCases::enUpdateUser):
                _UpdateUser();
                break;
            case (enManageUsersMenuCases::enFindUser):
                _FindUser();
                break;
            case (enManageUsersMenuCases::enMainMenu):
                break;
            }
        } while (Choice != enManageUsersMenuCases::enMainMenu);
    }

};
