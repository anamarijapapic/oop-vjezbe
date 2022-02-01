/*
	[OP] - VJEZBA 9 - ZADATAK 2
	@file Sparrow.hpp
	@author Anamarija Papic
*/

#pragma once
#include "Bird.hpp"

class Sparrow : public Bird {
protected:
	int legs = 2;
	string species = "Sparrow";
public:
	Sparrow() {}
	int get_legs() { return legs; }
	string get_species() { return species; }
	~Sparrow() {}
};