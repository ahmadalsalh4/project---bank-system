#pragma once
#include <iostream>
#include "clsValid.h"
#include "clsScreen.h"
#include "clsClient.h"
using namespace std;

class clsDepositScreen : public clsScreen
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
	static void ShowDepositScreen()
	{
        clsScreen::DrawScreenHeader("Deposit Screen");
        string AccountNumber = clsValid::ReadString("please enter account number: ");
        clsClient Client = clsClient::Find(AccountNumber);
        if (!clsClient::IsEmpty(Client))
        {
            cout << "\nthe following are client details:\n\n";
            _PrintClientInfo(Client);
            float Amount = clsValid::ReadFloatNumber("\nPlease enter Deposit Amount: ");
            while (Amount <= 0)
            {
                cout << "\nDeposit Amount cant be 0 or negatif\n";
                Amount = clsValid::ReadFloatNumber("Please enter another Deposit Amount: ");
            }
            if (toupper(clsValid::ReadLetter("\nAre you sure you want to perform this transaction (Y/N) ?")) == 'Y')
            {
                Client.Deposit(Amount);
                cout << "\nTransaction completed Successfully, new Account Balance = " << Client.AccountBalance << endl;
            }

        }
        else
            cout << "\nClient with account number (" << AccountNumber << ") not found!";
        clsValid::CallSystem("\n\n\nPress any key to go back to Transactions Menu...");

    }

};
