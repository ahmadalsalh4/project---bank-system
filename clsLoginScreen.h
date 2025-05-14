#pragma once
#include <iostream>
#include "clsMainMenu.h"
#include "clsScreen.h"
#include "clsValid.h"
#include "clsUser.h"
#include "global.h"
#include <fstream>
#include "clsDate.h"
#include <string>
#include "clsRegisterLog.h"
using namespace std;

class clsLoginScreen : public clsScreen
{
private:
    enum enLoginMenuCases {
        enMainMenu = 1, enReRead, enExit
    };

    static void _PrintLoginScreen()
    {
        clsScreen::DrawScreenHeader("Login Screen", "Login Menu");

        cout << "\t\t\t\t\t\tdefault:\n";
        cout << "\t\t\t\t\t\tusername = admin\n";
        cout << "\t\t\t\t\t\tpassword = 1234\n\n\n";
        cout << "\t\t\t\t\t\tto close the porgram enter:\n";
        cout << "\t\t\t\t\t\tusername = 0\n";
        cout << "\t\t\t\t\t\tpassword = 0\n\n\n";
    }

    static enLoginMenuCases _login(bool& FaildState, short& Trials)
    {
        _PrintLoginScreen();

        if (FaildState)
        {
            cout << "\t\t\t\t\t\tinvalid username/password!\n";
            cout << "\t\t\t\t\t\tyou have " << Trials << " trials left to login\n";
        }

        if (Trials == 0)
        {
            cout << "\n\t\t\t\t\t\tyou are locked after 3 faild trials";
            return enLoginMenuCases::enExit;
        }

        string username = clsValid::ReadString("\t\t\t\t\t\tplease enter Username: ");
        string password = clsValid::ReadString("\t\t\t\t\t\tplease enter Password: ");

        if (username == "0" && password == "0")
            return enLoginMenuCases::enExit;
        CurrentUser = clsUser::Find(username, password);
        if (!clsUser::IsEmpty(CurrentUser))
        {
            FaildState = false;
            Trials = 3;
            return enLoginMenuCases::enMainMenu;
        }
        else
        {
            FaildState = true;
            Trials--;
            return enLoginMenuCases::enReRead;
        }
    }

public:
    static void ShowLoginScreen()
    {
        clsRegisterLog::SaveRegisterLog(clsRegisterLog::enRegisterLogTypes::enSysOpened);
        short Trials = 3;
        bool FaildState = false;
        enLoginMenuCases loginState;
        do
        {
            loginState = _login(FaildState, Trials);
            switch (loginState)
            {
            case(enLoginMenuCases::enMainMenu):
                clsRegisterLog::SaveRegisterLog(clsRegisterLog::enRegisterLogTypes::enLogin);
                clsMainMenu::ShowMainMenu();
                clsRegisterLog::SaveRegisterLog(clsRegisterLog::enRegisterLogTypes::enLogOut);
                CurrentUser = clsUser::EmptyObject();
                break;
            case(enLoginMenuCases::enReRead):
                break;
            case(enLoginMenuCases::enExit):
                break;
            }
        } while (loginState != enLoginMenuCases::enExit);
        clsRegisterLog::SaveRegisterLog(clsRegisterLog::enRegisterLogTypes::enSysClosed);
    }

};
