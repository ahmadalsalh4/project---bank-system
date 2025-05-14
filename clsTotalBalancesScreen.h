#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsClient.h"
#include "clsUtil.h"
#include <iomanip>
using namespace std;

class clsTotalBalancesScreen : public clsScreen
{
private:
    static void _PrintClientBalancesInLine(clsClient Client)
    {
        cout << "\t\t\t\t| " << setw(13) << left << Client.GetAccountNumber();
        cout << " | " << setw(22) << left << Client.FullName();
        cout << " | " << setw(14) << left << Client.AccountBalance << " |";
    }

public:
	static void ShowDepositScreen()
	{
        vector <clsClient> ClientsList = clsClient::GetClientList();
        clsScreen::DrawScreenHeader("Total Balances Screen", "Total Balances List (" +
            to_string(ClientsList.size()) + ") Client (s)");

        cout << "\t\t\t\t___________________________________________________________\n";
        cout << "\t\t\t\t| " << setw(13) << left << "AccountNumber";
        cout << " | " << setw(22) << left << "FullName";
        cout << " | " << setw(14) << left << "AccountBalance" << " |\n";
        cout << "\t\t\t\t___________________________________________________________\n";
        double TotalBalances = clsClient::GetTotalBalances();
        if (!(ClientsList.size() == 0))
        {
            for (clsClient& Client : ClientsList)
            {
                _PrintClientBalancesInLine(Client);
                cout << endl;
            }
        }
        else
            cout << "\t\t\t\t\t     No Clients Found.\n";
        cout << "\t\t\t\t___________________________________________________________\n";
        cout << "\t\t\t\t\t          Total Balances = " << TotalBalances;
        cout << "\n\t\t\t\t    ( " << clsUtil::NumberToText(TotalBalances) << " ) TL" << endl;
        cout << "\t\t\t\t___________________________________________________________\n";
        clsValid::CallSystem("\n\n\t\t\t\tPress any key to go back to Transactions Menu...");

	}

};
