/*
	[OP] - VJEZBA 9 - ZADATAK 2
	@file Counter.hpp
	@author Anamarija Papic
*/

#pragma once
#include "Animal.hpp"
#include <vector>

class Counter {
	int legs_sum;
	vector<Animal*> animals;
public:
	Counter(vector<Animal*> animals_vector) { legs_sum = 0; animals = animals_vector; }
	void count();
	friend ostream& operator<<(ostream& os, const Counter& cnt);
};

void Counter::count() {
	for (auto animal : animals) {
		legs_sum += animal->get_legs();
	}
}

ostream& operator<<(ostream& os, const Counter& cnt) {
	for (auto animal : cnt.animals) {
		os << "Added: " << animal->get_species() << endl;
	}
	os << "Total legs: " << cnt.legs_sum << endl;
	return os;
}