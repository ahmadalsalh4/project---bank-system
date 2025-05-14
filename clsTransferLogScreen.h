#pragma once
#include <iostream>
#include <vector>
#include "clsTransferLog.h"
#include "clsValid.h"
#include "clsScreen.h"
using namespace std;

class clsTransferLogScreen : public clsScreen
{
private:
    static void _PrintTransferLogInList(clsTransferLog::stTransferLogRecord Record)
    {
        cout << "| " << setw(25) << left << Record.Date;
        cout << " | " << setw(25) << left << Record.SCFullName;
        cout << " | " << setw(15) << left << Record.SCAccountNumber;
        cout << " | " << setw(25) << left << Record.DCFullName;
        cout << " | " << setw(15) << left << Record.DCAccountNumber;
        cout << " | " << setw(15) << left << Record.Amount;
        cout << " | " << setw(15) << left << Record.SCBalance;
        cout << " | " << setw(15) << left << Record.DCBalance;
        cout << " | " << setw(15) << left << Record.UserName << " |";
    }

public:
	static void ShowTransferLogScreen()
	{
        vector <clsTransferLog::stTransferLogRecord> TransferLogList = clsTransferLog::GetTransferLogList();

        clsScreen::DrawScreenHeader("Transfer Log Screen",
            "(" + to_string(TransferLogList.size()) + ") Record(s)");

        cout << "_________________________________________________________________________________________________________________________________________________________________________________________________\n";
        cout << "| " << setw(25) << left << "Date/Time";
        cout << " | " << setw(25) << left << "SC FullName";
        cout << " | " << setw(15) << left << "SC AccNumber";
        cout << " | " << setw(25) << left << "DC FullName";
        cout << " | " << setw(15) << left << "DC AccNumber";
        cout << " | " << setw(15) << left << "Amount";
        cout << " | " << setw(15) << left << "SC Balance";
        cout << " | " << setw(15) << left << "DC Balance";
        cout << " | " << setw(15) << left << "UserName" << " |\n";
        cout << "_________________________________________________________________________________________________________________________________________________________________________________________________\n";
        if (!(TransferLogList.size() == 0))
        {
            for (clsTransferLog::stTransferLogRecord& Record : TransferLogList)
            {
                _PrintTransferLogInList(Record);
                cout << endl;
            }
        }
        else
            cout << "\t\t\t\t  No Records Found.            \n";

        cout << "_________________________________________________________________________________________________________________________________________________________________________________________________\n";
        clsValid::CallSystem("\n\n\nPress any key to go back to Transactions Menu...");
	}

};
