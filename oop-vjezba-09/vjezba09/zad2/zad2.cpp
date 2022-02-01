/*
	[OP] - VJEZBA 9 - ZADATAK 2
	@file zad2.cpp
	@author Anamarija Papic
*/

#include <iostream>
#include <vector>
#include "Tarantula.hpp"
#include "Cockroach.hpp"
#include "Sparrow.hpp"
#include "Counter.hpp"

int main()
{
	vector<Animal*> animals = { new Tarantula, new Cockroach, new Sparrow };
	Counter cnt(animals);
	cnt.count();
	cout << cnt;
    return 0;
}
