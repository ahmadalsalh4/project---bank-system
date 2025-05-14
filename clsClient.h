#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsPerson.h"
#include "clsString.h"
#include "clsUtil.h"
using namespace std;

class clsClient : public clsPerson
{
private:
	enum enMode { Empty, Exist };

	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	enMode _Mode;

	void  _SaveRecordsToFile(vector <clsClient> VClients)
	{
		fstream myfile;
		myfile.open("Clients.txt", ios::out);
		if (myfile.is_open())
		{
			for (clsClient& c : VClients)
			{
				if(c._Mode !=enMode::Empty)
					myfile << _ConvertRecordToLine(c) << endl;
			}
			myfile.close();
		}
	}

	void _AddRecordToFile(string line)
	{
		fstream myfile;
		myfile.open("Clients.txt", ios::out | ios::app);
		if (myfile.is_open())
		{
			myfile << line << endl;
			myfile.close();
		}
	}

	static vector <clsClient> _LoadRecordsToVector()
	{
		fstream myfile;
		vector <clsClient> VClients;
		myfile.open("Clients.txt", ios::in);
		if (myfile.is_open())
		{
			string line;
			while (getline(myfile, line))
				VClients.push_back(_ConvertLineDataToRecord(line));
			myfile.close();
		}
		return VClients;
	}
		
	static clsClient _ConvertLineDataToRecord(string ClientData, string separator = "#//#")
	{
		vector <string> vRecord = clsString::SplitString(ClientData, separator);
		return clsClient(vRecord[0], vRecord[1], vRecord[2], vRecord[3], vRecord[4],
			clsUtil::Decrypt_Password(vRecord[5], 10), stof(vRecord[6]), enMode::Exist);
	}

	string _ConvertRecordToLine(clsClient Client, string separator = "#//#")
	{
		string ClientDataString = "";
		ClientDataString += Client.FirstName + separator;
		ClientDataString += Client.LastName + separator;
		ClientDataString += Client.Email + separator;
		ClientDataString += Client.PhoneNumber + separator;
		ClientDataString += Client.GetAccountNumber() + separator;
		ClientDataString += clsUtil::Encrypt_Password(Client.PinCode, 10) + separator;
		ClientDataString += to_string(Client.AccountBalance);
		return ClientDataString;
	}

	static clsClient _EmptyObject()
	{
		return clsClient("", "", "", "", "", "", 0, enMode::Empty);
	}

public:
	clsClient(string FirstName, string LastName, string Email, string PhoneNumber,
		string AccountNumber, string PinCode, float AccountBalance, enMode Mode)
		:clsPerson(FirstName, LastName, Email, PhoneNumber)
	{
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
		_Mode = Mode;
	}

	string GetAccountNumber()
	{
		return _AccountNumber;
	}
	
	string GetPinCode()
	{
		return _PinCode;
	}
	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	string FullName()
	{
		return FirstName + " " + LastName;
	}

	void Update()
	{
		vector <clsClient> VClient = _LoadRecordsToVector();
		for (clsClient& c : VClient)
			if (c.GetAccountNumber() == _AccountNumber)
			{
				c = *this;
				break;
			}
		_SaveRecordsToFile(VClient);
	}

	void Add()
	{
		if(!IsClientExist(_AccountNumber))
			_AddRecordToFile(_ConvertRecordToLine(*this));
		else
			cout << "\nClient with AccountNumber [" << _AccountNumber << "] already exist, Please try another AccountNumber before adding: ";
	}

	void Delete()
	{
		vector <clsClient> VClient = _LoadRecordsToVector();
		for (clsClient& c : VClient)
			if (c.GetAccountNumber() == _AccountNumber)
			{
				*this = _EmptyObject();
				c = *this;
				break;
			}
		_SaveRecordsToFile(VClient);
	}

	void Deposit(float Amount)
	{
		_AccountBalance += Amount;
		Update();
	}

	void Withdraw(float Amount)
	{
		if (Amount > _AccountBalance)
		{

		}
		else
		{
			_AccountBalance -= Amount;
			Update();
		}
	}

	void Transfer(clsClient& DesClient, float Amount)
	{
		if (Amount > AccountBalance)
			return;
		Withdraw(Amount);
		DesClient.Deposit(Amount);
	}

	static clsClient Find(string AccountNumber)
	{
		fstream myfile;
		myfile.open("Clients.txt", ios::in);
		if (myfile.is_open())
		{
			string line;
			while (getline(myfile, line))
			{
				clsClient Client = _ConvertLineDataToRecord(line);
				if (Client._AccountNumber == AccountNumber)
				{
					myfile.close();
					return Client;
				}

			}
			myfile.close();
		}
		return _EmptyObject();
	}

	static bool IsClientExist(string AccountNumber)
	{
		return !IsEmpty(Find(AccountNumber));
	}

	static bool IsEmpty(clsClient Client)
	{
		return (Client._Mode == enMode::Empty);
	}

	static clsClient GetNewClientObject(string AccountNumber)
	{
		return clsClient("", "", "", "", AccountNumber, "", 0, enMode::Exist);
	}

	static vector <clsClient> GetClientList()
	{
		return _LoadRecordsToVector();
	}

	static double GetTotalBalances()
	{
		double TotalBalances = 0;
		vector <clsClient> VClient = _LoadRecordsToVector();
		for (clsClient& c : VClient)
			TotalBalances += c.AccountBalance;
		return TotalBalances;
	}

};
