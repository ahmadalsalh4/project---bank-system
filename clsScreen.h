#pragma once
#include <iostream>
#include "global.h"
#include "clsDate.h"
using namespace std;

class clsScreen
{
protected:
	static void DrawScreenHeader(string ScreenTitle, string SubTitle = "")
	{
		system("cls");
		cout << "\t\t\t\t\t____________________________________________\n";
		cout << "\t\t\t\t\t\t\t" << ScreenTitle << endl;
		cout << "\t\t\t\t\t____________________________________________\n\n";

		if (SubTitle != "")
		{
			cout << "\t\t\t\t\t     ==================================\n";
			cout << "\t\t\t\t\t\t\t  " << SubTitle << endl;
			cout << "\t\t\t\t\t     ==================================\n";
		}

		cout << "\t\t\t\t\tUser: " << CurrentUser.GetUserName() << endl;
		cout << "\t\t\t\t\tDate: ";
		clsDate::Print(clsDate::clsDate());
		cout << endl;
	}

};
