#pragma once
#include <iostream>
#include <string>
using namespace std;

class clsValid
{
public:
    static int ReadIntNumber(string message = "please enter a number : \n", int min = -2000000000, int max = 2000000000, string error = "invalid input,")
    {
        int number;
        if (error == "invalid input,")
            error += message;
        cout << message;
        cin >> number;
        while (cin.fail() || number < min || number > max)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << error;
            cin >> number;
        }
        return number;
    }

    static float ReadFloatNumber(string message = "please enter a number : \n", float min = -2000000000, float max = 2000000000)
    {
        float number;
        cout << message;
        cin >> number;
        while (cin.fail() || number < min || number > max)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "invalid input, " << message;
            cin >> number;
        }
        return number;
    }

    static string ReadString(string massage = "please enter your text : \n")
    {
        string text;
        cout << massage;
        getline(cin >> ws, text);
        return text;
    }
    
    static char ReadLetter(string massage = "please enter your text : \n")
    {
        char c;
        cout << massage;
        cin >> c;
        return c;
    }
    
    static void CallSystem(string massege)
    {
        cout << massege;
        system("pause>0");
        system("cls");
    }

};
