#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsValid.h"
#include "clsClient.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"
using namespace std;

class clsTransactionsMenuScreen : public clsScreen
{
private:
    enum enTransactionsMenuCases {
        Deposit = 1, Withdraw, TotalBalances, TransferScreen, TransferLogScreen, MainMenu
    };

    static void _DrawTransactionsMenuScreen()
    {
        clsScreen::DrawScreenHeader("Transactions Menu Screen", "Transactions Menu");

        cout << "\t\t\t\t[1] Deposit.\n";
        cout << "\t\t\t\t[2] Withdraw.\n";
        cout << "\t\t\t\t[3] Total Balances.\n";
        cout << "\t\t\t\t[4] Transfer Screen.\n";
        cout << "\t\t\t\t[5] Transfer Log Screen.\n";
        cout << "\t\t\t\t[6] Main Menu.\n";
    }

    static void _DepositScreen()
    {
        clsDepositScreen::ShowDepositScreen();
    }

    static void _WithdrawScreen()
    {
        clsWithdrawScreen::ShowWithdrawScreen();
    }

    static void _TotalBalancesScreen()
    {
        clsTotalBalancesScreen::ShowDepositScreen();
    }

    static void _TransferScreen()
    {
        clsTransferScreen::ShowTransferScreen();
    }

    static void _TransferLogScreen()
    {
        clsTransferLogScreen::ShowTransferLogScreen();
    }

public:
    
    static void ShowTransactionsMenuScreen()
    {
        char Choice;
        do
        {
            _DrawTransactionsMenuScreen();
            Choice = (enTransactionsMenuCases)clsValid::ReadIntNumber("\t\t\t\tChoose what do you want to do [1-6] : ", 1, 6, "\t\t\t\tInvalid input, Choose what do you want to do [1-6] : ");
            switch (Choice)
            {
            case (enTransactionsMenuCases::Deposit):
                _DepositScreen();
                break;
            case (enTransactionsMenuCases::Withdraw):
                _WithdrawScreen();
                break;
            case (enTransactionsMenuCases::TotalBalances):
                _TotalBalancesScreen();
                break;
            case (enTransactionsMenuCases::TransferScreen):
                _TransferScreen();
                break;
            case (enTransactionsMenuCases::TransferLogScreen):
                _TransferLogScreen();
                break;
            case (enTransactionsMenuCases::MainMenu):
                break;
            }
        } while (Choice != enTransactionsMenuCases::MainMenu);
    }

};
