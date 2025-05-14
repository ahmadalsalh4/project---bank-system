#pragma once
#include <iostream>
#include "clsDate.h"
#include "global.h"
#include <fstream>
#include <string>
#include <vector>
#include "clsString.h"
#include "clsUser.h"
#include "clsClient.h"
using namespace std;

class clsTransferLog
{
public:
	struct stTransferLogRecord {
		string Date;
		string SCFullName;
		string SCAccountNumber;
		string DCFullName;
		string DCAccountNumber;
		int Amount = 0;
		int SCBalance = 0;
		int DCBalance = 0;
		string UserName;
	};

private:
	static stTransferLogRecord _ConvertTransferLogLineToRecord(string TransferLogLine)
	{
		stTransferLogRecord Record;
		vector <string> VRecord = clsString::SplitString(TransferLogLine, "#//#");
		Record.Date = VRecord[0];
		Record.SCFullName = VRecord[1];
		Record.SCAccountNumber = VRecord[2];
		Record.DCFullName = VRecord[3];
		Record.DCAccountNumber = VRecord[4];
		Record.Amount = stoi(VRecord[5]);
		Record.SCBalance = stoi(VRecord[6]);
		Record.DCBalance = stoi(VRecord[7]);
		Record.UserName = VRecord[8];

		return Record;
	}

	static string _MakeTransferLog(clsClient ClientForm, clsClient ClientTo, float Amount, string separator = "#//#")
	{
		string log = "";
		log += clsDate::GetFullDate() + separator;
		log += ClientForm.FullName() + separator;
		log += ClientForm.GetAccountNumber() + separator;
		log += ClientTo.FullName() + separator;
		log += ClientTo.GetAccountNumber() + separator;
		log += to_string(Amount) + separator;
		log += to_string(ClientForm.AccountBalance) + separator;
		log += to_string(ClientTo.AccountBalance) + separator;
		log += CurrentUser.GetUserName();
		return log;
	}

public:
	static void SaveTransferLog(clsClient ClientForm, clsClient ClientTo, float Amount)
	{
		fstream Myfile;
		Myfile.open("TransferLog.txt", ios::out | ios::app);

		if (Myfile.is_open())
		{
			Myfile << _MakeTransferLog(ClientForm, ClientTo, Amount) << endl;
			Myfile.close();
		}
	}

	static vector <stTransferLogRecord> GetTransferLogList()
	{
		fstream MyFile;
		vector <stTransferLogRecord> TransferLogRecords;

		MyFile.open("TransferLog.txt", ios::in);

		if (MyFile.is_open())
		{
			string s1;
			while (getline(MyFile, s1))
			{
				TransferLogRecords.push_back(_ConvertTransferLogLineToRecord(s1));
			}
			MyFile.close();
		}
		return TransferLogRecords;
	}

};
