#pragma once
#include <iostream>
#include "clsClient.h"
#include "clsScreen.h"
#include "clsValid.h"
using namespace std;

class clsUpdateClientScreen : public clsScreen
{
private:
	static void _ReadClientData(clsClient& Client)
	{
		Client.FirstName = clsValid::ReadString("Please enter a FirstName: ");
		Client.LastName = clsValid::ReadString("Please enter a LastName: ");
		Client.Email = clsValid::ReadString("Please enter an Email: ");
		Client.PhoneNumber = clsValid::ReadString("Please enter a PhoneNumber: ");
		Client.PinCode = clsValid::ReadString("Please enter a PinCode: ");
		Client.AccountBalance = clsValid::ReadFloatNumber("Please enter an AccountBalance: ");
	}

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
	static void ShowUpdateClientScreen()
	{
		clsScreen::DrawScreenHeader("Update Client Screen");

		string AccountNumber = clsValid::ReadString("Please enter an AccountNumber : ");
		clsClient Client = clsClient::Find(AccountNumber);

		if (!clsClient::IsEmpty(Client))
		{
			cout << "\nThe following are client details:\n\n";
			_PrintClientInfo(Client);
			if (toupper(clsValid::ReadLetter("\nAre you sure you want to update this client (Y/N) ?")) == 'Y')
			{
				cout << "\nUpdating Client: \n\n";
				_ReadClientData(Client);
				Client.Update();
				cout << "\nClient Date Updated Successfully\n";
			}
		}
		else
			cout << "\nClient with AccountNumber (" << AccountNumber << ") not found!";
		clsValid::CallSystem("\n\nPress any key to go back to main menu...");
	}

};
