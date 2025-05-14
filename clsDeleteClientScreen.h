#pragma once
#include <iostream>
#include "clsClient.h"
#include "clsScreen.h"
#include "clsValid.h"
using namespace std;

class clsDeleteClientScreen : public clsScreen
{
private:
	static void _PrintClientInfo(clsClient Client)
	{
		cout << "Client Details : " << endl;
		cout << "________________________________________" << endl;
		cout << "FirstName      : " << Client.FirstName << endl;
		cout << "LastName       : " << Client.LastName << endl;
		cout << "FullName       : " << Client.FullName() << endl;
		cout << "Email          : " << Client.Email << endl;
		cout << "PhoneNumber    : " << Client.PhoneNumber << endl;
		cout << "AccountNumber  : " << Client.GetAccountNumber() << endl;
		cout << "PinCode        : " << Client.PinCode << endl;
		cout << "AccountBalance : " << Client.AccountBalance << endl;
		cout << "________________________________________" << endl;
	}

public:
	static void ShowDeleteClientScreen()
	{
		clsScreen::DrawScreenHeader("Delete Client Screen");
		string AccountNumber = clsValid::ReadString("Please enter an AccountNumber: ");
		clsClient Client = clsClient::Find(AccountNumber);
		if (!clsClient::IsEmpty(Client))
		{
			cout << "\nThe following are client details:\n\n";
			_PrintClientInfo(Client);
			if (toupper(clsValid::ReadLetter("\nAre you sure you want to Delete this client (Y/N) ?")) == 'Y')
			{
				Client.Delete();
				cout << "\nClient Deleted Successfully\n";
			}
		}
		else
			cout << "\nClient with AccountNumber (" << AccountNumber << ") not found\n";
		clsValid::CallSystem("\nPress any key to go back to main menu...");
	}

};
