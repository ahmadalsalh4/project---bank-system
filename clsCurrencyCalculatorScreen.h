#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsValid.h"
#include "clsCurrency.h"
using namespace std;

class clsCurrencyCalculatorScreen : public clsScreen
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

	static void PrintConvertResult(clsCurrency Currency1, clsCurrency Currency2, float Amount)
	{
		cout << "\n\nConvert From :\n";
		_PrintCurrencyCard(Currency1);
		
		float AmountInUsd = Currency1.GetAmountInUsd(Amount);
		cout << Amount << " " << Currency1.GetCurrencyCode() << " = " << AmountInUsd << " USD\n";

		if (Currency2.GetCurrencyCode() != "USD")
		{
			cout << "\n\nTo :\n";
			_PrintCurrencyCard(Currency2);
			float AmountInOtherCurrnacy = Currency1.GetAmountInOtherCurrnacy(Amount, Currency2);
			cout << Amount << " " << Currency1.GetCurrencyCode()
				<< " = " << AmountInOtherCurrnacy << " " << Currency2.GetCurrencyCode() << endl;
		}
	}

public:
	static void ShowCurrencyCalculatorScreen()
	{
		bool calculateMore = true;
		while (calculateMore)
		{
			clsScreen::DrawScreenHeader("Currency Calculator Screen");

			string CurrencyCode1 = clsValid::ReadString("\nPlease Enter Currency1 Code: ");
			clsCurrency Currency1 = clsCurrency::FindByCurrencyCode(CurrencyCode1);
			if (Currency1.IsEmpty())
			{
				cout << "\n\nCurrency not found!\n";
				break;
			}
			string CurrencyCode2 = clsValid::ReadString("\nPlease Enter Currency2 Code: ");
			clsCurrency Currency2 = clsCurrency::FindByCurrencyCode(CurrencyCode2);
			if (Currency2.IsEmpty())
			{
				cout << "\n\nCurrency not found!\n";
				break;
			}
			float Amount = clsValid::ReadFloatNumber("\nPlease enter Amount to Exchance: ",0);

			PrintConvertResult(Currency1, Currency2, Amount);

			if (toupper(clsValid::ReadLetter("\n\nDo you want to calculate more currency exchances: (Y/N) ?")) != 'Y')
				calculateMore = false;
		}
		clsValid::CallSystem("\nPress any key to go back to Currency Exchance Menu...");
	}

};
