#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsValid.h"
#include "clsClient.h"
#include "clsTransferLog.h"
using namespace std;

class clsTransferScreen : public clsScreen
{
private:
	static void _PrintClientCardForTransfer(clsClient Cleint)
	{
		cout << "\n\nClient Card:";
		cout << "\n______________________________________________";
		cout << "\nFull Name       :" << Cleint.FullName();
		cout << "\nAccountg Number :" << Cleint.GetAccountNumber();
		cout << "\nBalance         :" << Cleint.AccountBalance;
		cout << "\n______________________________________________\n\n";
	}

	static float _ReadAmount(clsClient Client)
	{
		float Amount = clsValid::ReadFloatNumber("\nPlease enter Transfer Amount: ");
		while (Amount <= 0 || Amount > Client.AccountBalance)
		{
			if (Amount <= 0)
				cout << "\nTransfer Amount cant be 0 or negatif, ";
			if (Amount > Client.AccountBalance)
				cout << "\nAmount exceeds the Balance, you can Transfer up to : " << Client.AccountBalance << endl;
			Amount = clsValid::ReadFloatNumber("Please enter another Withdraw Amount: ");
		}
		return Amount;
	}

public:
	static void ShowTransferScreen()
	{
		clsScreen::DrawScreenHeader("Transfer Screen");
		while (1)
		{
			string Accfrom = clsValid::ReadString("Please enter account number to transfer from: ");
			clsClient ClientForm = clsClient::Find(Accfrom);
			if (!clsClient::IsEmpty(ClientForm))
			{
				_PrintClientCardForTransfer(ClientForm);
				if (ClientForm.AccountBalance == 0)
				{
					cout << ClientForm.FullName() << "\ndont have any money to transfer.";
					break;
				}
			}
			else
			{
				cout << "\nClient with account number (" << Accfrom << ") not found!";
				break;
			}

			string AccTo = clsValid::ReadString("Please enter account number to transfer To: ");
			while(Accfrom == AccTo)
			{
				cout << "\nYou cant transfer money to the same account number!\n";
				AccTo = clsValid::ReadString("Please enter account number to transfer To: ");
			}
			clsClient ClientTo = clsClient::Find(AccTo);
			if (!clsClient::IsEmpty(ClientTo))
			{
				_PrintClientCardForTransfer(ClientTo);
			}
			else
			{
				cout << "\nClient with account number (" << AccTo << ") not found!";
				break;
			}

			float Amount = _ReadAmount(ClientForm);
			if (toupper(clsValid::ReadLetter("\nAre you sure you want to perform this transaction (Y/N) ?")) == 'Y')
			{
				ClientForm.Transfer(ClientTo, Amount);
				cout << "\n\nTransfer completed Successfully"<< endl;
				_PrintClientCardForTransfer(ClientForm);
				_PrintClientCardForTransfer(ClientTo);
				clsTransferLog::SaveTransferLog(ClientForm, ClientTo, Amount);
				break;
			}
			else
				break;
		}
		clsValid::CallSystem("\n\n\t\t\t\tPress any key to go back to Transactions Menu...");
	}

};
