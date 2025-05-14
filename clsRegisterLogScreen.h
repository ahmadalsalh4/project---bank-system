#pragma once
#include <iostream>
#include "clsValid.h"
#include "clsScreen.h"
#include <vector>
#include "clsRegisterLog.h"
using namespace std;

class clsRegisterLogScreen : public clsScreen
{
private:
    static void _PrintUserDataInList(clsRegisterLog::stRecord Record)
    {
        cout << "| " << setw(20) << left << Record.Date;
        cout << " | " << setw(12) << left << Record.LogType;
        cout << " | " << setw(21) << left << Record.FullName;
        cout << " | " << setw(10) << left << Record.UserName;
        cout << " | " << setw(12) << left << Record.Password;
        cout << " | " << setw(12) << left << Record.Permission << " |";
    }

public:
	static void ShowRegisterLogScreen()
	{
        vector <clsRegisterLog::stRecord> RegisterLogList = clsRegisterLog::GetRegisterLogList();

        clsScreen::DrawScreenHeader("Register Log Screen",
            "(" + to_string(RegisterLogList.size()) + ") Record(s)");

        cout << "__________________________________________________________________________________________________________\n";
        cout << "| " << setw(20) << left << "Date/Time";
        cout << " | " << setw(12) << left << "LogType";
        cout << " | " << setw(21) << left << "FullName";
        cout << " | " << setw(10) << left << "UserName";
        cout << " | " << setw(12) << left << "Password";
        cout << " | " << setw(12) << left << "Permission" << " |\n";
        cout << "__________________________________________________________________________________________________________\n";
        if (!(RegisterLogList.size() == 0))
        {
            for (clsRegisterLog::stRecord& Record : RegisterLogList)
            {
                _PrintUserDataInList(Record);
                cout << endl;
            }
        }
        else
            cout << "\t\t\t\t  No Records Found.            \n";

        cout << "__________________________________________________________________________________________________________";
		clsValid::CallSystem("\n\n\nPress any key to go back to main menu...");
	}

};
