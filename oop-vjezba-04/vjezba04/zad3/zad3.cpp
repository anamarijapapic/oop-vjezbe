/*
	[OP] - VJEZBA 4 - ZADATAK 3
	@file zad3.cpp
	@author Anamarija Papic
*/

#include <iostream>
#include <string>
using namespace std;

void stuffing_bit(string& container)
{
	int cnt = 0;
	for (int i = 0; i < container.size(); i++) {
		if (container[i] == '1') {
			cnt++;
			if (cnt == 5) {
				container.insert(++i, "0");
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
	char digit;
	string container;
	cout << "Enter binary digits (0/1) to save them in container: " << endl;
	while (cin >> digit) {
		if ((digit != '1') && (digit != '0'))
			break;
		container.push_back(digit);
	}
	cout << endl << "Your entered container:" << endl;
	print_container(container);
	stuffing_bit(container);
	cout << endl << "Result of bit stuffing algorithm:" << endl;
	print_container(container);
	return 0;
}