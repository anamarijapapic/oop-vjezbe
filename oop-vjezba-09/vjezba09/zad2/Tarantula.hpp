/*
	[OP] - VJEZBA 9 - ZADATAK 2
	@file Tarantula.hpp
	@author Anamarija Papic
*/

#pragma once
#include "Spider.hpp"

class Tarantula : public Spider {
protected:
	int legs = 8;
	string species = "Tarantula";
public:
	Tarantula() {}
	int get_legs() { return legs; }
	string get_species() { return species; }
	~Tarantula() {}
};