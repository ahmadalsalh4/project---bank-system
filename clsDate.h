#pragma once
#pragma warning(disable : 4996)

#include <iostream>
#include "clsString.h"
#include <string>

using namespace std;

class clsDate
{
private:
    int _Day;
    int _Month;
    int _Year;

    enum enDateCompareResult { Before = -1, Equal = 0, After = 1 };

public:
    clsDate()
    {
        time_t t = time(0);
        tm* now = localtime(&t);
        _Day = now->tm_mday;
        _Month = now->tm_mon + 1;
        _Year = now->tm_year + 1900;
    }

    clsDate(string StringDate)
    {
        vector <string> v1 = clsString::SplitString(StringDate, "/");
        _Day = stoi(v1[0]);
        _Month = stoi(v1[1]);
        _Year = stoi(v1[2]);
    }

    clsDate(int Day, int Month, int Year)
    {
        _Day = Day;
        _Month = Month;
        _Year = Year;
    }

    clsDate(int DaysFromBegingOfTheYear, int Year)
    {
        clsDate Date1 = GetDateFromDayOrderInYear(DaysFromBegingOfTheYear, Year);
        
        _Day = Date1.Day;
        _Month = Date1.Month;
        _Year = Date1.Year;
    }

    int GetDay()
    {
        return _Day;
    }
    void SetDay(int Day)
    {
        _Day = Day;
    }
    __declspec(property(get = GetDay, put = SetDay)) int Day;

    int GetMonth()
    {
        return _Month;
    }
    void SetMonth(int Month)
    {
        _Month = Month;
    }
    __declspec(property(get = GetMonth, put = SetMonth)) int Month;

    int GetYear()
    {
        return _Year;
    }
    void SetYear(int Year)
    {
        _Year = Year;
    }
    __declspec(property(get = GetYear, put = SetYear)) int Year;

    static void Print(clsDate Date)
    {
        cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
    }
    void Print()
    {
        Print(*this);
    }

    static string GetFullDate()
    {
        time_t t = time(0);
        tm* now = localtime(&t);
        string S1 = "";
        S1 += to_string(now->tm_mday) + "/";
        S1 += to_string(now->tm_mon + 1) + "/";
        S1 += to_string(now->tm_year + 1900) + " - ";
        S1 += to_string(now->tm_hour) + ":";
        S1 += to_string(now->tm_min) + ":";
        S1 += to_string(now->tm_sec);
        return S1;
    }

    static bool IsLeapYear(int year)
    {
        return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }
    bool IsLeapYear()
    {
        return IsLeapYear(_Year);
    }

    static int NumberOfDaysInYear(int year)
    {
        return IsLeapYear(year) ? 366 : 365;
    }
    int NumberOfDaysInYear()
    {
        return NumberOfDaysInYear(_Year);
    }

    static int NumberOfHoursInYear(int year)
    {
        return NumberOfDaysInYear(year) * 24;
    }
    int NumberOfHoursInYear()
    {
        return NumberOfHoursInYear(_Year);
    }

    static int NumberOfMinutsInYear(int year)
    {
        return NumberOfHoursInYear(year) * 60;
    }
    int NumberOfMinutsInYear()
    {
        return NumberOfMinutsInYear(_Year);
    }

    static int NumberOfSecondsInYear(int year)
    {
        return NumberOfMinutsInYear(year) * 60;
    }
    int NumberOfSecondsInYear()
    {
        return NumberOfSecondsInYear(_Year);
    }

    static int NumberOfDaysInMonth(int year, int month)
    {
        int arr[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        return (IsLeapYear(year) && month == 2) ? 29 : arr[month];
    }
    int NumberOfDaysInMonth()
    {
        return NumberOfDaysInMonth(_Year, _Month);
    }

    static int NumberOfHoursInMonth(int year, int month)
    {
        return NumberOfDaysInMonth(year, month) * 24;
    }
    int NumberOfHoursInMonth()
    {
        return NumberOfHoursInMonth(_Year, _Month);
    }

    static int NumberOfMinutsInMonth(int year, int month)
    {
        return NumberOfHoursInMonth(year, month) * 60;
    }
    int NumberOfMinutsInMonth()
    {
        return NumberOfMinutsInMonth(_Year, _Month);
    }

    static int NumberOfSecondsInMonth(int year, int month)
    {
        return NumberOfMinutsInMonth(year, month) * 60;
    }
    int NumberOfSecondsInMonth()
    {
        return NumberOfSecondsInMonth(_Year, _Month);
    }

    static int DayOrderInWeek(clsDate Date)
    {
        int a = ((14 - Date.Month) / 12);
        int y = Date.Year - a;
        int m = Date.Month + (12 * a) - 2;
        int d = ((Date.Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7);
        return d;
    }
    int DayOrderInWeek()
    {
        return DayOrderInWeek(*this);
    }

    static string DayName(clsDate Date)
    {
        string arr[] = { "sun","mon","tue","wed","thu","fri","sat" };
        return arr[DayOrderInWeek(Date)];
    }
    string DayName()
    {
        return DayName(*this);
    }

    static string MonthName(int month)
    {
        string arr[] = { "","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
        return arr[month];
    }
    string MonthName()
    {
        return MonthName(_Month);
    }

    static void PrintMonthCalendar(int year, int month)
    {
        clsDate Date;
        Date.Day = 1;
        Date.Month = month;
        Date.Year = year;

        cout << "\n\n  _______________" << MonthName(month) << "_______________" << endl << endl;
        cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";

        int DaysInMonth = NumberOfDaysInMonth(year, month);
        int DayOrder = DayOrderInWeek(Date);
        int iindex;

        for (iindex = 0; iindex <= DayOrder - 1; iindex++)
            cout << "     ";

        for (int i = 1; i <= DaysInMonth; i++)
        {
            printf("%5d", i);

            iindex++;
            if (iindex == 7 && i != DaysInMonth)
            {
                cout << endl;
                iindex = 0;
            }
        }
        cout << "\n  __________________________________" << endl;
    }
    void PrintMonthCalendar()
    {
        PrintMonthCalendar(_Year, _Month);
    }

    static void PrintYearCalendar(int year)
    {
        cout << "  _________________________________";
        cout << "\n             " << year << " - calendar\n";
        cout << "  _________________________________";

        for (int i = 1; i <= 12; i++)
        {
            PrintMonthCalendar(year, i);
            cout << "\n";
        }
    }
    void PrintYearCalendar()
    {
        PrintYearCalendar(_Year);
    }

    static int HowManyDayGoneFromTheStartOfTheYear(clsDate Date)
    {
        int TotalDays = 0;
        for (int i = 1; i <= Date.Month - 1; i++)
        {
            TotalDays += NumberOfDaysInMonth(Date.Year, i);
        }
        TotalDays += Date.Day;
        return TotalDays;
    }
    int HowManyDayGoneFromTheStartOfTheYear()
    {
        return HowManyDayGoneFromTheStartOfTheYear(*this);
    }

    void AddDaysToDate(int DaysToAdd)
    {
        int remaninDays = DaysToAdd + HowManyDayGoneFromTheStartOfTheYear(*this);

        _Month = 1;

        int daysInMonth = NumberOfDaysInMonth(_Year, _Month);

        while (remaninDays > daysInMonth)
        {
            remaninDays -= daysInMonth;
            _Month++;
            if (_Month == 13)
            {
                _Month = 1;
                _Year++;
            }
            daysInMonth = NumberOfDaysInMonth(_Year, _Month);
        }
        _Day = remaninDays;
    }
    
    static bool IsDateBeforeDate2(clsDate date1, clsDate date2)
    {
        if (date1.Year < date2.Year)
            return 1;
        else if (date1.Year > date2.Year)
            return 0;
        else if (date1.Month < date2.Month)
            return 1;
        else if (date1.Month > date2.Month)
            return 0;
        else if (date1.Day < date2.Day)
            return 1;
        else if (date1.Day > date2.Day)
            return 0;
        else
            return 0;
    }
    bool IsDateBeforeDate2(clsDate date2)
    {
        return IsDateBeforeDate2(*this, date2);
    }

    static bool IsDateEqualDate2(clsDate date1, clsDate date2)
    {
        return (date1.Year == date2.Year) ? ((date1.Month == date2.Month) ? ((date1.Day == date2.Day) ? 1 : 0) : 0) : 0;
    }
    bool IsDateEqualDate2(clsDate date2)
    {
        return IsDateEqualDate2(*this, date2);
    }

    static bool IsLastMontheInTheYear(int month)
    {
        return 12 == month;
    }
    bool IsLastMontheInTheYear()
    {
        return IsLastMontheInTheYear(_Month);
    }

    static bool IsLastDayInTheMonth(clsDate Date)
    {
        return NumberOfDaysInMonth(Date.Year, Date.Month) == Date.Day;
    }
    bool IsLastDayInTheMonth()
    {
        return IsLastDayInTheMonth(*this);
    }

    static void IncressDateByOneDay(clsDate& Date)
    {
        if (IsLastDayInTheMonth(Date))
        {
            if (IsLastMontheInTheYear(Date.Month))
            {
                Date.Day = 1;
                Date.Month = 1;
                Date.Year++;
            }
            else
            {
                Date.Day = 1;
                Date.Month++;
            }
        }
        else
            Date.Day++;
    }
    void IncressDateByOneDay()
    {
        IncressDateByOneDay(*this);
    }

    static void SwapDates(clsDate &Date1, clsDate &Date2)
    {
        clsDate temp;

        temp = Date1;
        Date1 = Date2;
        Date2 = temp;
    }
    void SwapDates(clsDate& Date2)
    {
        SwapDates(*this, Date2);
    }

    static int DifrenceBetwenDates(clsDate date1, clsDate date2, bool includeLastDay = 0)
    {
        int days = 0;
        int multiplayer = 1;

        if (!IsDateBeforeDate2(date1, date2))
        {
            SwapDates(date1, date2);
            multiplayer = -1;
        }

        while (IsDateBeforeDate2(date1, date2))
        {
            IncressDateByOneDay(date1);
            days++;
        }

        return  includeLastDay ? ++days * multiplayer : days * multiplayer;
    }
    int DifrenceBetwenDates(clsDate date2, bool includeLastDay = 0)
    {
        return DifrenceBetwenDates(*this, date2, includeLastDay);
    }

    void IncressDateByXDays(int c)
    {
        for (int i = 1; i <= c; i++)
            IncressDateByOneDay(*this);
    }

    void IncressDateByOneWeek()
    {
        for (int i = 1; i <= 7; i++)
            IncressDateByOneDay(*this);
    }

    void IncressDateByXWeeks(int c)
    {
        for (int i = 1; i <= c; i++)
            IncressDateByOneWeek();
    }

    void IncressDateByOneMonth()
    {
        _Month++;

        if (_Month == 13)
        {
            _Month = 1;
            _Year++;
        }
        int numberOfDaysInMonth = NumberOfDaysInMonth(_Year, _Month);
        if (_Day > numberOfDaysInMonth)
            _Day = numberOfDaysInMonth;
    }

    void IncressDateByXMonths(int c)
    {
        for (int i = 1; i <= c; i++)
            IncressDateByOneMonth();
    }

    void IncressDateByOneYear()
    {
        if (_Day == 29 && _Month == 2)
            _Day--;
        _Year++;
    }
    
    void IncressDateByXYears(int c)
    {
        for (int i = 1; i <= c; i++)
            IncressDateByOneYear();
    }

    void IncressDateByXYearsFaster(int c)
    {
        if (_Day == 29 && _Month == 2)
            _Day--;
        _Year += c;
    }

    void IncressDateByOneDecade()
    {
        if (_Day == 29 && _Month == 2)
            _Day--;
        _Year += 10;
    }

    void IncressDateByXDecades(int c)
    {
        for (int i = 1; i <= c; i++)
            IncressDateByOneDecade();
    }

    void IncressDateByXDecadesFaster(int c)
    {
        if (_Day == 29 && _Month == 2)
            _Day--;

        _Year += 10 * c;
    }

    void DecreaseDateByOneDay()
    {
        if (_Day == 1)
        {
            if (_Month == 1)
            {
                _Month = 12;
                _Day = 31;
                _Year--;
            }
            else
            {
                _Month--;
                _Day = NumberOfDaysInMonth(_Year,_Month);
            }
        }
        else
            _Day--;
    }

    void DecreaseDateByXDays(int c)
    {
        for (int i = 1; i <= c; i++)
            DecreaseDateByOneDay();
    }

    void DecreaseDateByOneWeek()
    {
        for (int i = 1; i <= 7; i++)
            DecreaseDateByOneDay();
    }

    void DecreaseDateByXWeeks(int c)
    {
        for (int i = 1; i <= c; i++)
            DecreaseDateByOneWeek();
    }

    void DecreaseDateByOneMonth()
    {

        _Month--;

        if (_Month == 0)
        {
            _Month = 12;
            _Year--;
        }
        int numberOfDaysInMonth = NumberOfDaysInMonth(_Year, _Month);
        if (_Day > numberOfDaysInMonth)
            _Day = numberOfDaysInMonth;
    }

    void DecreaseDateByXMonths(int c)
    {
        for (int i = 1; i <= c; i++)
            DecreaseDateByOneMonth();
    }

    void DecreaseDateByOneYear()
    {
        if (_Day == 29 && _Month == 2)
            _Day--;
        _Year--;
    }

    void DecreaseDateByXYears(int c)
    {
        for (int i = 1; i <= c; i++)
            DecreaseDateByOneYear();
    }

    void DecreaseDateByXYearsFaster(int c)
    {
        if (_Day == 29 && _Month == 2)
            _Day--;
        _Year -= c;
    }

    void DecreaseDateByOneDecade()
    {
        if (_Day == 29 && _Month == 2)
            _Day--;
        _Year -= 10;
    }

    void DecreaseDateByXDecades(int c)
    {
        for (int i = 1; i <= c; i++)
            DecreaseDateByOneDecade();
    }

    void DecreaseDateByXDecadesFaster(int c)
    {
        if (_Day == 29 && _Month == 2)
            _Day--;

        _Year -= 10 * c;
    }

    static bool IsItEndOfWeek(clsDate Date)
    {
        return DayOrderInWeek(Date) == 6;
    }
    bool IsItEndOfWeek()
    {
        return IsItEndOfWeek(*this);
    }

    static bool IsItWeekEnd(clsDate Date)
    {
        int dayorder = DayOrderInWeek(Date);
        return ((dayorder == 5) || (dayorder == 6));
    }
    bool IsItWeekEnd()
    {
        return IsItWeekEnd(*this);
    }

    static bool IsItBusinessDay(clsDate Date)
    {
        return !IsItWeekEnd(Date);
    }
    bool IsItBusinessDay()
    {
        return IsItBusinessDay(*this);
    }

    static int DaysUntilEndOfWeek(clsDate Date)
    {
        return 6 - DayOrderInWeek(Date);
    }
    int DaysUntilEndOfWeek()
    {
        return DaysUntilEndOfWeek(*this);
    }

    static int DaysUntilEndOfMonth(clsDate Date)
    {
        clsDate endOfMonth;

        endOfMonth.Day = NumberOfDaysInMonth(Date.Year, Date.Month);
        endOfMonth.Month = Date.Month;
        endOfMonth.Year = Date.Year;

        return DifrenceBetwenDates(Date, endOfMonth, 1);
    }
    int DaysUntilEndOfMonth()
    {
        return DaysUntilEndOfMonth(*this);
    }

    static int DaysUntilEndOfYear(clsDate Date)
    {
        clsDate endOfMonth;

        endOfMonth.Day = 31;
        endOfMonth.Month = 12;
        endOfMonth.Year = Date.Year;

        return DifrenceBetwenDates(Date, endOfMonth, 1);
    }
    int DaysUntilEndOfYear()
    {
        return DaysUntilEndOfYear(*this);
    }

    static int TotalVacationDays(clsDate from, clsDate to)
    {
        int c = 0;
        while (!IsDateEqualDate2(from, to))
        {
            if (IsItBusinessDay(from))
                c++;
            IncressDateByOneDay(from);
        }
        return c;
    }
    
    static clsDate VacationReturnDate(clsDate date1, int VacationPeriod)
    {
        while (VacationPeriod != 0)
        {
            if (IsItBusinessDay(date1))
                VacationPeriod--;
            IncressDateByOneDay(date1);
        }
        return date1;
    }

    static bool IsDateAfterDate2(clsDate date1, clsDate date2)
    {
        return !IsDateBeforeDate2(date1, date2) && !IsDateEqualDate2(date1, date2);
    }
    bool IsDateAfterDate2(clsDate date2)
    {
        return IsDateAfterDate2(*this, date2);
    }

    static enDateCompareResult CompareDate(clsDate date1, clsDate date2)
    {
        if (IsDateBeforeDate2(date1, date2))
            return enDateCompareResult::Before;
        else if (IsDateEqualDate2(date1, date2))
            return enDateCompareResult::Equal;
        return enDateCompareResult::After;
    }

    static bool IsValidDate(clsDate Date)
    {
        if (Date.Day < 1 || Date.Day > NumberOfDaysInMonth(Date.Year, Date.Month))
            return 0;

        if (Date.Month < 1 || Date.Month > 12)
            return 0;

        if (Date.Year < 1)
            return 0;

        return 1;
    }
    bool IsValidDate()
    {
        return IsValidDate(*this);
    }

    static string ConvertDateToDateString(clsDate Date)
    {
        return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
    }
    string ConvertDateToDateString()
    {
        return ConvertDateToDateString(*this);
    }

    static string FormateDate(clsDate Date, string format = "dd/mm/yyyy")
    {
        format = clsString::ReplaceWordUsingBuiltInFunction(format, "dd", to_string(Date.Day));
        format = clsString::ReplaceWordUsingBuiltInFunction(format, "mm", to_string(Date.Month));
        format = clsString::ReplaceWordUsingBuiltInFunction(format, "yyyy", to_string(Date.Year));
        return format;
    }
    string FormateDate(string format = "dd/mm/yyyy")
    {
        return FormateDate(*this, format);
    }

    static int AgeInDays(clsDate Date)
    {
        return DifrenceBetwenDates(Date, clsDate());
    }
    int AgeInDays()
    {
        return AgeInDays(*this);
    }

    static clsDate GetDateFromDayOrderInYear(int DaysFromBegingOfTheYear, int Year)
    {
        clsDate Date1;
        Date1.Year = Year;
        Date1.Month = 1;

        int daysInMonth = NumberOfDaysInMonth(Date1.Year, Date1.Month);

        while (DaysFromBegingOfTheYear > daysInMonth)
        {
            DaysFromBegingOfTheYear -= daysInMonth;
            Date1.Month++;
            daysInMonth = NumberOfDaysInMonth(Date1.Year, Date1.Month);
        }
        Date1.Day = DaysFromBegingOfTheYear;

        return Date1;
    }

};
