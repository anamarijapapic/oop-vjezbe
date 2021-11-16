/*
	[OP] - VJEZBA 4 - ZADATAK 4
	@file zad4.cpp
	@author Anamarija Papic
*/

#include <iostream>
#include <string>
using namespace std;

void unstuffing_bit(string& container)
{
	int cnt = 0;
	for (int i = 0; i < container.size(); i++) {
		if (container[i] == '1') {
			cnt++;
			if (cnt == 5) {
				container.erase(++i, 1);
				cnt = 0;
			}
		}
		else
			cnt = 0;
	}
}

void print_container(string& container)
{
	for (int i = 0; i < container.size(); i++) {
		cout << container[i];
	}
	cout << endl;
}

int main()
{
	string container;
	cout << "Enter modified container:" << endl;
	getline(cin, container);
	cout << endl << "Your entered modified container:" << endl;
	print_container(container);
	unstuffing_bit(container);
	cout << endl << "Result of bit unstuffing algorithm - original sequence:" << endl;
	print_container(container);
	return 0;
}