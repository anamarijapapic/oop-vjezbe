/*
    [OP] - VJEZBA 3 - ZADATAK 5
    @file zad5.cpp
    @author Anamarija Papic
*/

#include <iostream>
#include <string>
using namespace std;

int substrRepeatCounter(string& sub, string& str)
{
    int lenSub = sub.length();
    int lenStr = str.length();
    int cnt = 0;

    for (int i = 0; i < lenStr; i++) {
        if (sub == str.substr(i, lenSub)) {
            cnt++;
        }
    }

    return cnt;
}

int main()
{
    string str = "hihahihahahalol";
    string sub = "ha";
    cout << "In string " << str << " substring " << sub << " is repeated " << substrRepeatCounter(sub, str) << " times.";
    return 0;
}
