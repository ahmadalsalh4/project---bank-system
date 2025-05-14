#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsValid.h"
#include "clsClientListScreen.h"
#include "clsAddClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsMenuScreen.h"
#include "clsManageUsersScreen.h"
#include "global.h"
#include "clsRegisterLogScreen.h"
#include "clsCurrencyExchanceScreen.h"
using namespace std;

class clsMainMenu : public clsScreen
{
private:
	enum enMainMenuCases {
		enShowClientList = 1, enAddClient, enDeleteClient,
		enUpdateClientInfo, enFindClient, enTransactionsMenu,
		enManageUsers, enRegisterLog, enCurrencyExchance, enLogout
	};

	static void _ShowCurrencyExchanceScreen()
	{
		clsCurrencyExchanceScreen::ShowCurrencyExchanceScreen();
	}

	static void _ShowRegisterLogScreen()
	{
		clsRegisterLogScreen::ShowRegisterLogScreen();
	}

	static void _ShowManageUsersScreen()
	{
		clsManageUsersScreen::ShowManageUsersMenu();
	}

	static void _ShowTransactionsMenuScreen()
	{
		clsTransactionsMenuScreen::ShowTransactionsMenuScreen();
	}

	static void _FindClient()
	{
		clsFindClientScreen::ShowFindClientScreen();
	}

	static void _UpdateClientInfo()
	{
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}

	static void _DeleteClient()
	{
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}
	
	static void _AddClient()
	{
		clsAddClientScreen::ShowAddClientScreen();
	}
	
	static void _ShowClientListScreen()
	{
		clsClientListScreen::ShowClientList();
	}
	
	static bool _HavePermissions(clsUser::enPermissions Permission)
	{
		if (CurrentUser.Permission == clsUser::enPermissions::PerAll)
			return true;

		if ((CurrentUser.Permission & Permission) == Permission)
			return true;
		else
		{
			clsScreen::DrawScreenHeader("Access denied!");
			cout << "\nyou dont have permission to do this\nplease contact your admin\n";
			clsValid::CallSystem("\n\n\nPress any key to go back to main menu...");
			return false;
		}
			
	}

	static void _PrintMainMenu()
	{
		DrawScreenHeader("Main Menu Screen", "Main Menu");
		
		cout << "\t\t\t\t[1] Show clients list.\n";
		cout << "\t\t\t\t[2] Add new client.\n";
		cout << "\t\t\t\t[3] Delete client.\n";
		cout << "\t\t\t\t[4] Update client.\n";
		cout << "\t\t\t\t[5] Find client.\n";
		cout << "\t\t\t\t[6] Transactions Menu.\n";
		cout << "\t\t\t\t[7] Manage Users.\n";
		cout << "\t\t\t\t[8] Register Log.\n";
		cout << "\t\t\t\t[9] Currency Exchance.\n";
		cout << "\t\t\t\t[10] logout.\n\n";
		
	}

public:
	static void ShowMainMenu()
	{
		char Choice;
		do
		{
			_PrintMainMenu();
			Choice = (enMainMenuCases)clsValid::ReadIntNumber("\t\t\t\tChoose what do you want to do [1-10] : ", 1, 10, "\t\t\t\tInvalid input, Choose what do you want to do [1-10] : ");
			switch (Choice)
			{
			case (enMainMenuCases::enShowClientList):
				if (_HavePermissions(clsUser::enPermissions::PerShowClientList))
					_ShowClientListScreen();
				break;
			case (enMainMenuCases::enAddClient):
				if (_HavePermissions(clsUser::enPermissions::PerAddClient))
					_AddClient();
				break;
			case(enMainMenuCases::enDeleteClient):
				if (_HavePermissions(clsUser::enPermissions::PerDeleteClient))
					_DeleteClient();
				break;
			case(enMainMenuCases::enUpdateClientInfo):
				if (_HavePermissions(clsUser::enPermissions::PerUpdateClient))
					_UpdateClientInfo();
				break;
			case(enMainMenuCases::enFindClient):
				if (_HavePermissions(clsUser::enPermissions::PerFindClient))
					_FindClient();
				break;
			case(enMainMenuCases::enTransactionsMenu):
				if (_HavePermissions(clsUser::enPermissions::PerTransactions))
					_ShowTransactionsMenuScreen();
				break;
			case(enMainMenuCases::enManageUsers):
				if (_HavePermissions(clsUser::enPermissions::PerManageUsers))
					_ShowManageUsersScreen();
				break;
			case(enMainMenuCases::enRegisterLog):
				if (_HavePermissions(clsUser::enPermissions::PerRegisterLog))
					_ShowRegisterLogScreen();
				break;
			case(enMainMenuCases::enCurrencyExchance):
				if (_HavePermissions(clsUser::enPermissions::PerCurrencyExchance))
					_ShowCurrencyExchanceScreen();
				break;
			case(enMainMenuCases::enLogout):
				break;
			}
		} while (Choice != enMainMenuCases::enLogout);
	}

};
