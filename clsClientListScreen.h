#pragma once
#include <iostream>
#include "clsClient.h"
#include "clsScreen.h"
#include "clsValid.h"
#include <iomanip>
using namespace std;

class clsClientListScreen : public clsScreen
{
private:
	static void _PrintClientDataInLine(clsClient Client)
	{
		cout << "| " << setw(13) << left << Client.GetAccountNumber();
		cout << " | " << setw(22) << left << Client.FullName();
		cout << " | " << setw(20) << left << Client.Email;
		cout << " | " << setw(11) << left << Client.PhoneNumber;
		cout << " | " << setw(7) << left << Client.PinCode;
		cout << " | " << setw(14) << left << Client.AccountBalance << " |";
	}

public:
	static void ShowClientList()
	{
		vector <clsClient> ClientsList = clsClient::GetClientList();
		clsScreen::DrawScreenHeader("Client List Screen", "Client List (" +
			to_string(ClientsList.size()) + ") Client (s)");
		cout << "__________________________________________________________________________________________________________\n";
		cout << "| " << setw(13) << left << "AccountNumber";
		cout << " | " << setw(22) << left << "FullName";
		cout << " | " << setw(20) << left << "Email";
		cout << " | " << setw(11) << left << "PhoneNumber";
		cout << " | " << setw(7) << left << "PinCode";
		cout << " | " << setw(14) << left << "AccountBalance" << " |\n";
		cout << "__________________________________________________________________________________________________________\n";
		if (!(ClientsList.size() == 0))
		{
			for (clsClient& Client : ClientsList)
			{
				_PrintClientDataInLine(Client);
				cout << endl;
			}
		}
		else
			cout << "\t\t\t\t  No Clients Found.\n";
		cout << "__________________________________________________________________________________________________________\n";

		clsValid::CallSystem("\nPress any key to go back to main menu...");
	}

};
