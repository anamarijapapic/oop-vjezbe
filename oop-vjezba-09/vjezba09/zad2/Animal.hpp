/*
	[OP] - VJEZBA 9 - ZADATAK 2
	@file Animal.hpp
	@author Anamarija Papic
*/

#pragma once
#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
    virtual int get_legs() = 0;
    virtual string get_species() = 0;
};