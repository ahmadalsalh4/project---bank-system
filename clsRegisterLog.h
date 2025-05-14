#pragma once
#include <iostream>
#include "clsDate.h"
#include "global.h"
#include <fstream>
#include <string>
#include <vector>
#include "clsString.h"
#include "clsUser.h"
#include "clsUtil.h"
using namespace std;

class clsRegisterLog
{
public:
    enum enRegisterLogTypes {
        enLogin = 1, enLogOut, enSysOpened, enSysClosed
    };

    struct stRecord{
        string Date;
        string LogType;
        string FullName;
        string UserName;
        string Password;
        int Permission = 0;
    };

private:
    static string _enRegisterLogTypesToString(enRegisterLogTypes LogTypes)
    {
        switch (LogTypes)
        {
        case(enRegisterLogTypes::enLogin):
            return "Login";
        case(enRegisterLogTypes::enLogOut):
            return "Logout";
        case(enRegisterLogTypes::enSysOpened):
            return "SysOpened";
        case(enRegisterLogTypes::enSysClosed):
            return "SysClosed";
        }
    }

    static string _MakeRegisterLog(enRegisterLogTypes LogTypes, string separator = "#//#")
    {
        string log = "";
        log += clsDate::GetFullDate() + separator;
        log += _enRegisterLogTypesToString(LogTypes) + separator;
        log += CurrentUser.FullName() + separator;
        log += CurrentUser.GetUserName() + separator;
        log += clsUtil::Encrypt_Password(CurrentUser.Password, 10) + separator;
        log += to_string(CurrentUser.Permission);
        return log;
    }

    static stRecord _ConvertRegisterLogLineToRecord(string RegisterLogLine)
    {
        stRecord Record;
        vector <string> VRecord = clsString::SplitString(RegisterLogLine, "#//#");
        Record.Date = VRecord[0];
        Record.LogType = VRecord[1];
        Record.FullName = VRecord[2];
        Record.UserName = VRecord[3];
        Record.Password = clsUtil::Decrypt_Password(VRecord[4], 10);
        Record.Permission = stoi(VRecord[5]);
        return Record;
    }

public:
    static void SaveRegisterLog(enRegisterLogTypes LogTypes)
    {
        fstream Myfile;

        Myfile.open("RegisterLog.txt", ios::out | ios::app);

        if (Myfile.is_open())
        {
            Myfile << _MakeRegisterLog(LogTypes) << endl;
            Myfile.close();
        }
    }

    static vector <stRecord> GetRegisterLogList()
    {
        fstream MyFile;
        vector <stRecord> Records;

        MyFile.open("RegisterLog.txt", ios::in);

        if (MyFile.is_open())
        {
            string s1;
            while (getline(MyFile, s1))
            {
                Records.push_back(_ConvertRegisterLogLineToRecord(s1));
            }
            MyFile.close();
        }
        return Records;
    }

};
