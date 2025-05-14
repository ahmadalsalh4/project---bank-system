#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class clsString
{
private:
    string _value;
    
    enum enLetterCounter { capital = 1, small, digit, space, other, all };

public:
    clsString()
    {
        _value = "";
    }
    clsString(string Value)
    {
        _value = Value;
    }

    string GetValue()
    {
        return _value;
    }
    void SetValue(string Value)
    {
        _value = Value;
    }
    __declspec(property(get = GetValue, put = SetValue)) string Value;

    static void PrintFirstLetterOfEcheWord(string text)
    {
        cout << "first letters of eche word in the string:\n";
        bool IsNextCharFirstLetter = 1;
        for (int i = 0; i <= text.length() - 1; i++)
        {
            if (IsNextCharFirstLetter && text[i] != ' ')
                cout << text[i] << endl;
            IsNextCharFirstLetter = (text[i] == ' ') ? 1 : 0;
        }
    }
    void PrintFirstLetterOfEcheWord()
    {
        PrintFirstLetterOfEcheWord(_value);
    }

    static string UpperEcheLetterOfEcheWord(string s1)
    {
        bool IsNextCharFirstLetter = 1;
        for (int i = 0; i <= s1.length() - 1; i++)
        {
            if (IsNextCharFirstLetter && s1[i] != ' ')
                s1[i] = toupper(s1[i]);
            IsNextCharFirstLetter = (s1[i] == ' ') ? 1 : 0;
        }
        return s1;
    }
    void UpperEcheLetterOfEcheWord()
    {
        _value = UpperEcheLetterOfEcheWord(_value);
    }

    static string LowerEcheLetterOfEcheWord(string s1)
    {
        bool IsNextCharFirstLetter = 1;
        for (int i = 0; i <= s1.length() - 1; i++)
        {
            if (IsNextCharFirstLetter && s1[i] != ' ')
                s1[i] = tolower(s1[i]);
            IsNextCharFirstLetter = (s1[i] == ' ') ? 1 : 0;
        }
        return s1;
    }
    void LowerEcheLetterOfEcheWord()
    {
        _value = LowerEcheLetterOfEcheWord(_value);
    }

    static string LowerStringChars(string s1)
    {
        for (int i = 0; i <= s1.length() - 1; i++)
            s1[i] = tolower(s1[i]);
        return s1;
    }
    void LowerStringChars()
    {
        _value = LowerStringChars(_value);
    }

    static string UpperStringChars(string s1)
    {
        for (int i = 0; i <= s1.length() - 1; i++)
            s1[i] = toupper(s1[i]);
        return s1;
    }
    void UpperStringChars()
    {
        _value = UpperStringChars(_value);
    }
    
    static char MyInvertLetter(char x)
    {
        return isupper(x) ? tolower(x) : toupper(x);
    }

    static string InvertAllStringLetter(string s1)
    {
        for (int i = 0; i <= s1.length() - 1; i++)
            s1[i] = MyInvertLetter(s1[i]);
        return s1;
    }
    void InvertAllStringLetter()
    {
        _value = InvertAllStringLetter(_value);
    }

    static int LetterCounterByType(string s1, enLetterCounter LetterType)
    {
        if (LetterType == enLetterCounter::all)
            return s1.length();
        int counter = 0;
        for (int i = 0; i <= s1.length() - 1; i++)
        {
            switch (LetterType)
            {
            case(enLetterCounter::capital):
            {
                if (isupper(s1[i]))
                    counter++;
                break;
            }
            case(enLetterCounter::small):
            {
                if (islower(s1[i]))
                    counter++;
                break;
            }
            case(enLetterCounter::digit):
            {
                if (isdigit(s1[i]))
                    counter++;
                break;
            }
            case(enLetterCounter::space):
            {
                if (isspace(s1[i]))
                    counter++;
                break;
            }
            case(enLetterCounter::other):
            {
                if (!isupper(s1[i]) && !islower(s1[i]) && !isdigit(s1[i]) && !isspace(s1[i]))
                    counter++;
                break;
            }
            }
        }
        return counter;
    }
    int LetterCounter(enLetterCounter LetterType)
    {
        return LetterCounterByType(_value, LetterType);
    }

    static int CountCapitalLetters(string s1)
    {
        int c = 0;
        for (int i = 0; i <= s1.length() - 1; i++)
            if (isupper(s1[i]))
                c++;
        return c;
    }
    int CountCapitalLetters()
    {
        return CountCapitalLetters(_value);
    }

    static int CountSmallLetters(string s1)
    {
        int c = 0;
        for (int i = 0; i <= s1.length() - 1; i++)
            if (islower(s1[i]))
                c++;
        return c;
    }
    int CountSmallLetters()
    {
        return CountSmallLetters(_value);
    }

    static int CountLetterInString(string s1, char Letter, bool CareToCaseSensitive = false)
    {
        int counter = 0;
        for (int i = 0; i <= s1.length() - 1; i++)
        {
            if (CareToCaseSensitive)
            {
                if (s1[i] == Letter)
                    counter++;
            }
            else
            {
                if (s1[i] == Letter || MyInvertLetter(s1[i]) == Letter)
                    counter++;
            }
        }
        return counter;
    }
    int CountLetterInString(char Letter, bool CareToCaseSensitive)
    {
        return CountLetterInString(_value, Letter, CareToCaseSensitive);
    }
    
    static int CountWordsInString(string s1)
    {
        string delim = " ";
        string NullString = "";
        string word;
        int pos = 0;
        int counter = 0;
        while ((pos = s1.find(delim)) != s1.npos)
        {
            word = s1.substr(0, pos);
            if (word != NullString)
                counter++;
            s1.erase(0, pos + delim.length());
        }
        if (s1 != NullString)
            counter++;
        return counter;
    }
    int CountWordsInString()
    {
        return CountWordsInString(_value);
    }

    static bool MyIsItVowel(char ch1)
    {
        char vowel[5] = { 'a','e','i','o','u' };
        ch1 = tolower(ch1);
        for (char c : vowel)
            if (ch1 == c)
                return 1;
        return 0;
    }

    static int CountVowels(string s1)
    {
        int counter = 0;
        for (int i = 0; i <= s1.length() - 1; i++)
            if (MyIsItVowel(s1[i]))
                counter++;
        return counter;
    }
    int CountVowels()
    {
        return CountVowels(_value);
    }

    static void PrintVowelsInString(string s1)
    {
        for (int i = 0; i <= s1.length() - 1; i++)
            if (MyIsItVowel(s1[i]))
                cout << s1[i] << "    ";
    }
    void PrintVowelsInString()
    {
        PrintVowelsInString(_value);
    }

    static void PrintEachWordInString(string s1)
    {
        string delim = " ";
        string NullString = "";
        string word;
        int pos = 0;
        while ((pos = s1.find(delim)) != s1.npos)
        {
            word = s1.substr(0, pos);
            if (word != NullString)
                cout << word << endl;
            s1.erase(0, pos + delim.length());
        }
        if (s1 != NullString)
            cout << s1 << endl;
    }
    void PrintEachWordInString()
    {
        PrintEachWordInString(_value);
    }

    static vector <string> SplitString(string s1, string delim)
    {
        vector <string> vs1;
        string NullString = "";
        string word;
        int pos = 0;
        while ((pos = s1.find(delim)) != s1.npos)
        {
            word = s1.substr(0, pos);
            //if (word != NullString)
                vs1.push_back(word);
            s1.erase(0, pos + delim.length());
        }
        if (s1 != NullString)
            vs1.push_back(s1);
        return vs1;
    }
    vector <string> SplitString(string delim)
    {
        return SplitString(_value, delim);
    };

    static string TrimRight(string s1)
    {
        for (short i = s1.length() - 1; i >= 0; i--)
        {
            if (s1[i] != ' ')
                return s1.substr(0, i + 1);
        }
        return "";
    }
    void TrimRight()
    {
        _value = TrimRight(_value);
    }

    static string TrimLeft(string s1)
    {
        for (short i = 0; i <= s1.length() - 1; i++)
        {
            if (s1.at(i) != ' ')
                return s1.substr(i, s1.length() - i);
        }
        return "";
    }
    void TrimLeft()
    {
        _value = TrimLeft(_value);
    }

    static string Trim(string s1)
    {
        return TrimLeft(TrimRight(s1));
    }
    void Trim()
    {
        _value = Trim(_value);
    }

    static string JoinString(vector <string> vs1, string separator)
    {
        string s1 = "";
        for (string& word : vs1)
            s1 += word + separator;
        return s1.substr(0, s1.length() - separator.length());
    }
    
    static string JoinString(string arrofstring[], string separator, short arrofstring_length)
    {
        string s1 = "";
        for (short i = 0; i <= arrofstring_length - 1; i++)
            s1 += arrofstring[i] + separator;
        return s1.substr(0, s1.length() - separator.length());
    }

    static string ReverseString(string s1)
    {
        vector <string> vs1 = SplitString(s1, " ");
        string s2 = "";
        vector <string>::iterator iter;
        iter = vs1.end();
        while (iter != vs1.begin())
        {
            iter--;
            s2 += *iter + " ";
        }
        return s2.substr(0, s2.length() - 1);
    }
    void ReverseString()
    {
        _value = ReverseString(_value);
    }

    static string RemovePunctions(string s1)
    {
        string s2 = "";
        for (short i = 0; i <= s1.length() - 1; i++)
        {
            if (!ispunct(s1[i]))
                s2 += s1[i];
        }
        return s2;
    }
    void RemovePunctions()
    {
        _value = RemovePunctions(_value);
    }

    static string ReplaceWordUsingBuiltInFunction(string CompleteString, string ReplaceThisWord, string ToThisWord)
    {
        int pos = CompleteString.find(ReplaceThisWord);
        while (pos != CompleteString.npos)
        {
            CompleteString = CompleteString.replace(pos, ReplaceThisWord.length(), ToThisWord);
            pos = CompleteString.find(ReplaceThisWord);
        }
        return CompleteString;
    }
    void ReplaceWordUsingBuiltInFunction(string ojword, string newword)
    {
        _value =  ReplaceWordUsingBuiltInFunction(_value, ojword, newword);
    }

    static string ReplaceWord(string s1, string oldword, string newword, bool CaseSensitive = 1)
    {
        vector <string> vs1 = SplitString(s1, " ");
        for (string& word : vs1)
        {
            if (CaseSensitive)
            {
                if (word == oldword)
                    word = newword;
            }
            else
            {
                if (LowerStringChars(word) == LowerStringChars(oldword))
                    word = newword;
            }
        }
        return JoinString(vs1, " ");
    }
    void ReplaceWord(string oldword, string newword, bool CaseSensitive = 1)
    {
        _value = ReplaceWord(_value, oldword, newword, CaseSensitive = 1);
    }

};
