#pragma once
#include <iostream>

using namespace std;

class clsUtil
{
private:
    

public:
    enum enTypeOfChar { small_letter, capital_letter, special_chars, digit };

    static void SwapNumber(int& num1, int& num2)
    {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }

    static bool IsEven(int number)
    {
        if (number % 2 == 0)
            return 1;
        else
            return 0;
    }

    static bool IsPrimePrime(int x)
    {
        int m = round(x / 2);
        for (int i = 2; i <= m; i++)
        {
            if (x % i == 0)
            {
                return false;
            }
        }
        return true;
    }

    static string NumberToText(int number)
    {
        if (number < 20)
        {
            string arr1[] = { "","one","two","three","four","five","six","seven","eight","nine",
                              "ten","eleven","twelve","thirteen","fourteen","fifteen",
                              "sixteen","seventeen","eighteen","nineteen" };
            return arr1[number];
        }
        if (number < 99)
        {
            string arr2[] = { "","","twenty","thirty","forty","fifty",
                              "sixty","seventy","eighty","ninety" };
            return arr2[number / 10] + " " + NumberToText(number % 10);
        }

        if (number < 199)
            return  "one hundred " + NumberToText(number % 100);

        if (number < 999)
            return  NumberToText(number / 100) + " hundreds " + NumberToText(number % 100);

        if (number < 1999)
            return  "one thousand " + NumberToText(number % 1000);

        if (number < 999999)
            return  NumberToText(number / 1000) + " thousands " + NumberToText(number % 1000);

        if (number < 1999999)
            return  "one million " + NumberToText(number % 1000000);

        if (number < 999999999)
            return  NumberToText(number / 1000000) + " millions " + NumberToText(number % 1000000);

        if (number < 1999999999)
            return  "one billion " + NumberToText(number % 1000000);

        if (number < 999999999999)
            return  NumberToText(number / 1000000) + " billions " + NumberToText(number % 1000000);

        return "";
    }

    static bool IsPerfectNumber(int number)
    {
        int sum = 0;
        for (int i = 1; i < number; i++)
        {
            if (number % i == 0)
                sum += i;
        }
        return sum == number;
    }

    static int SumOfDigits(int number)
    {
        int sum = 0;
        while (number > 0)
        {
            sum += number % 10;
            number /= 10;
        }
        return sum;
    }

    static int ReverseDigit(int number)
    {
        int reversed_number = 0;
        while (number > 0)
        {
            reversed_number = reversed_number * 10 + number % 10;
            number /= 10;
        }
        return reversed_number;
    }

    static int CheckFrequencyOfSearchedDigitInNumber(int number, int searched_digit)
    {
        int frequency = 0;
        while (number > 0)
        {
            if (number % 10 == searched_digit)
                frequency++;
            number /= 10;
        }
        return frequency;
    }

    static bool IsPalindromeNumber(int number)
    {
        return number == ReverseDigit(number);
    }

    static bool SercheForPassword(string password)
    {
        cout << endl;
        string word;
        int trial = 0;
        for (int i = 65; i <= 90; i++)
            for (int j = 65; j <= 90; j++)
                for (int t = 65; t <= 90; t++)
                {
                    trial++;
                    cout << "trail [" << trial << "] : ";
                    word = char(i);
                    word += char(j);
                    word += char(t);
                    cout << word << endl;
                    if (word == password)
                    {
                        cout << "\npassword is " << word << "\nfound after " << trial << " trial(s)\n";
                        return true;
                    }
                    word = "";
                }
        cout << "\npassword not found!\n";
        return false;
    }

    static string Encrypt_Password(string password, short encryption_key)
    {
        for (int i = 0; i <= password.length(); i++)
            password[i] = char((int)password[i] + encryption_key);
        return password;
    }

    static string Decrypt_Password(string password, short encryption_key)
    {
        for (int i = 0; i <= password.length(); i++)
            password[i] = char((int)password[i] - encryption_key);
        return password;
    }

    static int RandomNumber(int min, int max)
    {
        return rand() % (max - min + 1) + min;
    }
    
    static char Randomcahr(enTypeOfChar type)
    {
        switch (type)
        {
        case enTypeOfChar::small_letter:
            return RandomNumber(97, 122);
        case enTypeOfChar::capital_letter:
            return RandomNumber(65, 90);
        case enTypeOfChar::special_chars:
            return RandomNumber(33, 47);
        case enTypeOfChar::digit:
            return RandomNumber(48, 57);
        }
    }

    static string GetRandomWord(enTypeOfChar type, int wordlength)
    {
        string word = "";
        for (int i = 1; i <= wordlength; i++)
            word += Randomcahr(type);
        return word;
    }

    static string GetRandomKey()
    {
        string key = "";
        for (int i = 1; i <= 4; i++)
        {
            key += GetRandomWord(enTypeOfChar::capital_letter, 4);
            if (i == 4)
                continue;
            key += "-";
        }
        return key;
    }

};
