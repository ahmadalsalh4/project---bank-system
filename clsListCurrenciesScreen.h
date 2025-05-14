#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsValid.h"
#include "clsCurrency.h"
#include <iomanip>
using namespace std;

class clsListCurrenciesScreen : public clsScreen
{
private:
	
	static void _PrintCurrencyDataInLine(clsCurrency c)
	{
		cout << "| " << setw(35) << left << c.GetCountryName();
		cout << " | " << setw(15) << left << c.GetCurrencyCode();
		cout << " | " << setw(50) << left << c.GetCurrrencyName();
		cout << " | " << setw(15) << left << c.GetRate() << " |";
	}
	
public:
	static void ShowCurrenciesListScreen()
	{
		
		vector <clsCurrency> CurrenciesList = clsCurrency::GetCurrenciesList();
		clsScreen::DrawScreenHeader("Currencies List Screen", "Currencies List (" +
			to_string(CurrenciesList.size()) + ") Client (s)");
		cout << "________________________________________________________________________________________________________________________________\n";
		cout << "| " << setw(35) << left << "Country Name";
		cout << " | " << setw(15) << left << "Currency Code";
		cout << " | " << setw(50) << left << "Currrency Name";
		cout << " | " << setw(15) << left << "Rate/(1$)" << " |\n";
		cout << "________________________________________________________________________________________________________________________________\n";
		if (!(CurrenciesList.size() == 0))
		{
			for (clsCurrency& c : CurrenciesList)
			{
				_PrintCurrencyDataInLine(c);
				cout << endl;
			}
		}
		else
			cout << "\t\t\t\t  No Currencies Found.\n";
		cout << "________________________________________________________________________________________________________________________________\n";

		clsValid::CallSystem("\nPress any key to go back to Currency Exchance Menu...");
	
	}

};
