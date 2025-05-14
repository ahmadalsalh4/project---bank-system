#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsClient.h"
#include "clsValid.h"
using namespace std;

class clsFindClientScreen : public clsScreen
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
	static void ShowFindClientScreen()
	{
		clsScreen::DrawScreenHeader("Find Client Screen");

		string AccountNumber = clsValid::ReadString("Please enter an AccountNumber : ");
		clsClient Client = clsClient::Find(AccountNumber);

		if (!clsClient::IsEmpty(Client))
		{
			cout << "\nthe following are client details:\n\n";
			_PrintClientInfo(Client);
		}
		else
			cout << "\nClient with account number (" << AccountNumber << ") not found!\n";
		clsValid::CallSystem("\n\nPress any key to go back to main menu...");
	};

};
