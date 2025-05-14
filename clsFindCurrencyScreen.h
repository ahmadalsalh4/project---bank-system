#pragma once
#include <iostream>
#include "clsValid.h"
#include "clsScreen.h"
#include "clsCurrency.h"
using namespace std;

class clsFindCurrencyScreen : public clsScreen
{
private:
	static void _PrintCurrencyCard(clsCurrency c)
	{
		cout << "\n\nCurrency Card:";
		cout << "\n_______________________________________";
		cout << "\nCountry Name  : " << c.GetCountryName();
		cout << "\nCurrency Code : " << c.GetCurrencyCode();
		cout << "\nCurrrency Name: " << c.GetCurrrencyName();
		cout << "\nRate/(1$)     : " << c.Rate;
		cout << "\n_______________________________________\n\n";
	}

	static void _ShowResult(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency found";
			_PrintCurrencyCard(Currency);
		}
		else
			cout << "\n\nCurrency not found!\n";
	}


public:
	static void ShowFindCurrencyScreen()
	{
		clsScreen::DrawScreenHeader("Find Currency Screen");

		int Choice = clsValid::ReadIntNumber("Find by: [1] Country Name, [2] Currency Code : ", 1, 2);
		if (Choice == 1)
		{
			string CountryName = clsValid::ReadString("Please Enter Country Name: ");
			clsCurrency Currency =	clsCurrency::FindByCountryName(CountryName);
			_ShowResult(Currency);
		}
		else
		{
			string CurrencyCode = clsValid::ReadString("Please Enter Currency Code: ");
			clsCurrency Currency = clsCurrency::FindByCurrencyCode(CurrencyCode);
			_ShowResult(Currency);
		}
		clsValid::CallSystem("\nPress any key to go back to Currency Exchance Menu...");

	}

};
