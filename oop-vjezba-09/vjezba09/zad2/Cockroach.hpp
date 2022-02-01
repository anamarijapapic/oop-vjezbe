/*
	[OP] - VJEZBA 9 - ZADATAK 2
	@file Cockroach.hpp
	@author Anamarija Papic
*/

#pragma once
#include "Insect.hpp"

class Cockroach : public Insect {
protected:
	int legs = 6;
	string species = "Cockroach";
public:
	Cockroach() {}
	int get_legs() { return legs; }
	string get_species() { return species; }
	~Cockroach() {}
};