#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "clsString.h"
using namespace std;

class clsCurrency
{
private:
	enum enState { enEmpty, enExist };
	
	string _CountryName;
	string _CurrencyCode;
	string _CurrrencyName;
	float _Rate = 0;
	enState _State;

	static clsCurrency _ConvertLineToCurrencyObject(string Line)
	{
		vector <string> VRecord = clsString::SplitString(Line, "#//#");
		return clsCurrency(VRecord[0], VRecord[1], VRecord[2],
			stof(VRecord[3]), enState::enExist);
	}

	string _ConvertObjectToCurrencyLine(clsCurrency c, string Separator = "#//#")
	{
		string Line = "";
		Line += c.GetCountryName() + Separator;
		Line += c.GetCurrencyCode() + Separator;
		Line += c.GetCurrrencyName() + Separator;
		Line += to_string(c.Rate);
		return Line;
	}

	static vector <clsCurrency> _Load()
	{
		vector <clsCurrency> VRecords;

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				VRecords.push_back(_ConvertLineToCurrencyObject(Line));
			}
			MyFile.close();
		}
		return VRecords;
	}

	void _Update()
	{
		vector <clsCurrency> Vrecords = _Load();

		for (clsCurrency& c : Vrecords)
		{
			if (c.GetCurrencyCode() == _CurrencyCode)
			{
				c = *this;
				break;
			}	
		}
		_Save(Vrecords);
	}

	void _Save(vector <clsCurrency> Vrecords)
	{
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);

		if (MyFile.is_open())
		{
			for (clsCurrency& c : Vrecords)
			{
				MyFile << _ConvertObjectToCurrencyLine(c) << endl;
			}
			MyFile.close();
		}
	}

	static clsCurrency _EmptyObject()
	{
		return clsCurrency("", "", "", 0, enState::enEmpty);
	}

public:
	clsCurrency(string CountryName, string CurrencyCode,
		string CurrrencyName, float Rate, enState State)
	{
		_CountryName = CountryName;
		_CurrencyCode = CurrencyCode;
		_CurrrencyName = CurrrencyName;
		_Rate = Rate;
		_State = State;
	}

	string GetCountryName()
	{
		return _CountryName;
	}

	string GetCurrencyCode()
	{
		return _CurrencyCode;
	}

	string GetCurrrencyName()
	{
		return _CurrrencyName;
	}

	void SetRate(float Rate)
	{
		_Rate = Rate;
	}
	float GetRate()
	{
		return _Rate;
	}
	__declspec(property(get = GetRate, put = SetRate)) float Rate;

	static clsCurrency FindByCountryName(string CountryName)
	{
		fstream MyFile;
		CountryName = clsString::UpperStringChars(CountryName);
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency c = _ConvertLineToCurrencyObject(Line);
				if (clsString::UpperStringChars(c.GetCountryName()) == CountryName)
				{
					MyFile.close();
					return c;
				}	
			}
		}
		MyFile.close();
		return _EmptyObject();
	}

	static clsCurrency FindByCurrencyCode(string CurrencyCode)
	{
		fstream MyFile;
		CurrencyCode = clsString::UpperStringChars(CurrencyCode);
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency c = _ConvertLineToCurrencyObject(Line);
				if (c.GetCurrencyCode() == CurrencyCode)
				{
					MyFile.close();
					return c;
				}
			}
		}
		MyFile.close();
		return _EmptyObject();
	}

	bool IsEmpty()
	{
		return (_State == enState::enEmpty);
	}

	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();
	}

	static vector <clsCurrency> GetCurrenciesList()
	{
		return _Load();
	}

	float GetAmountInUsd(float Amount)
	{
		return (Amount / Rate);
	}

	float GetAmountInOtherCurrnacy(float Amount, clsCurrency OtherCurrancy)
	{
		return GetAmountInUsd(Amount) * OtherCurrancy.Rate;
	}

};
