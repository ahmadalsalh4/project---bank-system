#pragma once
#include <iostream>
#include "clsValid.h"
#include "clsClient.h"
#include "clsScreen.h"
using namespace std;

class clsWithdrawScreen : public clsScreen
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
	static void ShowWithdrawScreen()
	{
        clsScreen::DrawScreenHeader("Withdraw Screen");

        string AccountNumber = clsValid::ReadString("please enter account number: ");
        clsClient Client = clsClient::Find(AccountNumber);
        if (!clsClient::IsEmpty(Client))
        {
            cout << "\nthe following are client details:\n\n";
            _PrintClientInfo(Client);
            if (Client.AccountBalance == 0)
            {
                cout << "\nYou dont have any money to withdraw.";
            }
            else
            {
                float Amount = clsValid::ReadFloatNumber("\nPlease enter Withdraw Amount: ");
                while (Amount <= 0 || Amount > Client.AccountBalance)
                {
                    if (Amount <= 0)
                        cout << "\nWithdraw Amount cant be 0 or negatif, ";
                    if (Amount > Client.AccountBalance)
                        cout << "\nAmount exceeds the Balance, you can Withdraw up to : " << Client.AccountBalance << endl;
                    Amount = clsValid::ReadFloatNumber("Please enter another Withdraw Amount: ");
                }
                if (toupper(clsValid::ReadLetter("\nAre you sure you want to perform this transaction (Y/N) ?")) == 'Y')
                {
                    Client.Withdraw(Amount);
                    cout << "\nTransaction completed Successfully, new Account Balance = " << Client.AccountBalance << endl;
                }
            }
        }
        else
            cout << "\nClient with account number (" << AccountNumber << ") not found!";
        clsValid::CallSystem("\n\n\nPress any key to go back to Transactions Menu...");

	}

};
