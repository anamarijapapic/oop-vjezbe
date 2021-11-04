/*
    [OP] - VJEZBA 3 - ZADATAK 6
    @file zad6.cpp
    @author Anamarija Papic
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void vector_string_custom_function(vector<string>& myVector)
{
    string input;
    while(cin >> input) {
        myVector.push_back(input);
    }
    for (size_t i = 0; i < myVector.size(); i++) {
        reverse(myVector[i].begin(), myVector[i].end());
    }
    sort(myVector.begin(), myVector.end());
}

void vector_print(vector<string>& myVector)
{
    for (size_t i = 0; i < myVector.size(); i++) {
        cout << myVector[i] << endl;
    }
}

int main()
{
    vector<string> v;
    cout << "Enter strings, Ctrl+z (Win) or Ctrl+d (Linux) for exit:" << endl;
    vector_string_custom_function(v);
    cout << endl << "Sorted vector of reversed strings: " << endl;
    vector_print(v);
    return 0;
}
