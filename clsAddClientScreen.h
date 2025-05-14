#pragma once
#include <iostream>
#include "clsClient.h"
#include "clsScreen.h"
#include "clsValid.h"
using namespace std;

class clsAddClientScreen : public clsScreen
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

public:
	static void ShowAddClientScreen()
	{
		clsScreen::DrawScreenHeader("Add Client Screen");
		if (toupper(clsValid::ReadLetter("\nAre you sure you want to Add new client (Y/N) ?")) == 'Y')
		{
			cout << "\nAdding New Client: \n\n";
			string AccountNumber = clsValid::ReadString("Please enter an AccountNumber: ");
			while (clsClient::IsClientExist(AccountNumber))
			{
				cout << "\nClient with AccountNumber [" << AccountNumber << "] already exist, Please enter another AccountNumber: ";
				AccountNumber = clsValid::ReadString("");
			}
			clsClient Client = clsClient::GetNewClientObject(AccountNumber);
			_ReadClientData(Client);
			Client.Add();
			cout << "\nClient Added Successfully\n";
		}
		

		clsValid::CallSystem("\nPress any key to go back to main menu...");
	}

};
