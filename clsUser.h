#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsPerson.h"
#include "clsString.h"
#include "clsUtil.h"
using namespace std;

class clsUser : public clsPerson
{
private:
	enum enMode { Empty, Exist };

	string _UserName;
	string _Password;
	int _Permission;
	enMode _Mode;

	void _SaveRecordsToFile(vector <clsUser> VUsers)
	{
		fstream myfile;
		myfile.open("Users.txt", ios::out);
		if (myfile.is_open())
		{
			for (clsUser& c : VUsers)
			{
				if (c._Mode != enMode::Empty)
					myfile << _ConvertRecordToLine(c) << endl;
			}
			myfile.close();
		}
	}

	void _AddRecordToFile(string line)
	{
		fstream myfile;
		myfile.open("Users.txt", ios::out | ios::app);
		if (myfile.is_open())
		{
			myfile << line << endl;
			myfile.close();
		}
	}

	static vector <clsUser> _LoadRecordsToVector()
	{
		fstream myfile;
		vector <clsUser> VUsers;
		myfile.open("Users.txt", ios::in);
		if (myfile.is_open())
		{
			string line;
			while (getline(myfile, line))
				VUsers.push_back(_ConvertLineDataToRecord(line));
			myfile.close();
		}
		return VUsers;
	}

	static clsUser _ConvertLineDataToRecord(string UserData, string separator = "#//#")
	{
		vector <string> vRecord = clsString::SplitString(UserData, separator);
		return clsUser(vRecord[0], vRecord[1], vRecord[2], vRecord[3], vRecord[4],
			clsUtil::Decrypt_Password(vRecord[5], 10), stoi(vRecord[6]), enMode::Exist);
	}

	string _ConvertRecordToLine(clsUser User, string separator = "#//#")
	{
		string UserDataString = "";
		UserDataString += User.FirstName + separator;
		UserDataString += User.LastName + separator;
		UserDataString += User.Email + separator;
		UserDataString += User.PhoneNumber + separator;
		UserDataString += User.GetUserName() + separator;
		UserDataString += clsUtil::Encrypt_Password(User.Password, 10) + separator;
		UserDataString += to_string(User.Permission);
		return UserDataString;
	}

public:
	enum enPermissions {
		PerAll = -1 ,PerShowClientList = 1, PerAddClient = 2, PerDeleteClient = 4,
		PerUpdateClient = 8, PerFindClient = 16, PerTransactions = 32,
		PerManageUsers = 64, PerRegisterLog = 128,
		PerCurrencyExchance = 256
	};

	clsUser(string FirstName, string LastName, string Email, string PhoneNumber,
		string UserName, string Password, int Permission, enMode Mode)
		:clsPerson(FirstName, LastName, Email, PhoneNumber)
	{
		_UserName = UserName;
		_Password = Password;
		_Permission = Permission;
		_Mode = Mode;
	}

	string GetUserName()
	{
		return _UserName;
	}

	string GetPassword()
	{
		return _Password;
	}
	void SetPassword(string Password)
	{
		_Password = Password;
	}
	__declspec(property(get = GetPassword, put = SetPassword)) string Password;

	int GetPermission()
	{
		return _Permission;
	}
	void SetPermission(int Permission)
	{
		_Permission = Permission;
	}
	__declspec(property(get = GetPermission, put = SetPermission)) int Permission;

	string FullName()
	{
		if (FirstName == "" && LastName == "")
			return "";
		return FirstName + " " + LastName;
	}

	void Update()
	{
		vector <clsUser> VUsers = _LoadRecordsToVector();
		for (clsUser& c : VUsers)
			if (c.GetUserName() == _UserName)
			{
				c = *this;
				break;
			}
		_SaveRecordsToFile(VUsers);
	}

	void Add()
	{
		if (!IsUserExist(_UserName))
			_AddRecordToFile(_ConvertRecordToLine(*this));
		else
			cout << "\nUser with UserName [" << _UserName << "] already exist, Please try another UserName before adding: ";
	}

	void Delete()
	{
		vector <clsUser> VUsers = _LoadRecordsToVector();
		for (clsUser& c : VUsers)
			if (c.GetUserName() == _UserName)
			{
				*this = EmptyObject();
				c = *this;
				break;
			}
		_SaveRecordsToFile(VUsers);
	}

	static clsUser Find(string UserName)
	{
		fstream myfile;
		myfile.open("Users.txt", ios::in);
		if (myfile.is_open())
		{
			string line;
			while (getline(myfile, line))
			{
				clsUser User = _ConvertLineDataToRecord(line);
				if (User._UserName == UserName)
				{
					myfile.close();
					return User;
				}

			}
			myfile.close();
		}
		return EmptyObject();
	}

	static clsUser Find(string UserName, string Password)
	{
		fstream myfile;
		myfile.open("Users.txt", ios::in);
		if (myfile.is_open())
		{
			string line;
			while (getline(myfile, line))
			{
				clsUser User = _ConvertLineDataToRecord(line);
				if (User._UserName == UserName && User._Password == Password)
				{
					myfile.close();
					return User;
				}

			}
			myfile.close();
		}
		return EmptyObject();
	}

	static bool IsUserExist(string UserName)
	{
		return !IsEmpty(Find(UserName));
	}

	static bool IsUserExist(string UserName, string Password)
	{
		return !IsEmpty(Find(UserName, Password));
	}

	static bool IsEmpty(clsUser User)
	{
		return (User._Mode == enMode::Empty);
	}

	static clsUser GetNewUserObject(string UserName)
	{
		return clsUser("", "", "", "", UserName, "", 0, enMode::Exist);
	}

	static vector <clsUser> GetUsersList()
	{
		return _LoadRecordsToVector();
	}

	static clsUser EmptyObject()
	{
		return clsUser("", "", "", "", "", "", 0, enMode::Empty);
	}

};
