#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsValid.h"
#include "clsListCurrenciesScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"
using namespace std;

class clsCurrencyExchanceScreen : public clsScreen
{
private:
    enum enCurrencyExchanceMenuCases {
        enListCurrencies = 1, enFindCurrency, enUpdateRate,
        enCurrencyCalculator, enMainMenu
    };

    static void _CurrencyCalculator()
    {
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }

    static void _UpdateRate()
    {
        clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
    }

    static void _FindCurrency()
    {
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }

    static void _ListCurrencies()
    {
        clsListCurrenciesScreen::ShowCurrenciesListScreen();
    }

    static void _DrawCurrencyExchanceMenuScreen()
    {
        clsScreen::DrawScreenHeader("Currency Exchance Menu Screen", "Currency Exchance Menu");

        cout << "\t\t\t\t[1] List Currencies.\n";
        cout << "\t\t\t\t[2] Find Currency.\n";
        cout << "\t\t\t\t[3] Update Rate.\n";
        cout << "\t\t\t\t[4] Currency Calculator.\n";
        cout << "\t\t\t\t[5] Main Menu.\n";
    }

public:
	static void ShowCurrencyExchanceScreen()
	{
        char Choice;
        do
        {
            _DrawCurrencyExchanceMenuScreen();
            Choice = (enCurrencyExchanceMenuCases)clsValid::ReadIntNumber("\t\t\t\tChoose what do you want to do [1-5] : ", 1, 5, "\t\t\t\tInvalid input, Choose what do you want to do [1-5] : ");
            switch (Choice)
            {
            case (enCurrencyExchanceMenuCases::enListCurrencies):
                _ListCurrencies();
                break;
            case (enCurrencyExchanceMenuCases::enFindCurrency):
                _FindCurrency();
                break;
            case (enCurrencyExchanceMenuCases::enUpdateRate):
                _UpdateRate();
                break;
            case (enCurrencyExchanceMenuCases::enCurrencyCalculator):
                _CurrencyCalculator();
                break;
            case (enCurrencyExchanceMenuCases::enMainMenu):
                break;
            }
        } while (Choice != enCurrencyExchanceMenuCases::enMainMenu);
    }
	
};
