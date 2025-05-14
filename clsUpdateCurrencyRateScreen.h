#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsValid.h"
#include "clsCurrency.h"
using namespace std;

class clsUpdateCurrencyRateScreen : public clsScreen
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

	static void _UpdateCurrencyRate(clsCurrency Currency)
	{
		float NewRate = clsValid::ReadFloatNumber("Please enter new Rate: ");
		if (toupper(clsValid::ReadLetter("\nAre you sure you want to update the Rate: (Y/N) ?")) == 'Y')
		{
			Currency.UpdateRate(NewRate);
			_PrintCurrencyCard(Currency);
		}
	}

public:
	static void ShowUpdateCurrencyRateScreen()
	{
		clsScreen::DrawScreenHeader("Update Currency Rate Screen");

		string CurrencyCode = clsValid::ReadString("Please Enter Currency Code: ");
		clsCurrency Currency = clsCurrency::FindByCurrencyCode(CurrencyCode);
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency found";
			_PrintCurrencyCard(Currency);
			_UpdateCurrencyRate(Currency);

		}
		else
			cout << "\n\nCurrency not found!\n";

		clsValid::CallSystem("\nPress any key to go back to Currency Exchance Menu...");

	}

};
