/*
	[OP] - VJEZBA 5 - ZADATAK 3
	@file target.hpp
	@author Anamarija Papic
*/

#pragma once
#include "../zad1/point.hpp"

class Target {
	bool is_hit = false;
public:
	Point bottomLeft, upperRight;
	void set_hit_status(bool status) { is_hit = status; }
	bool get_hit_status() const { return is_hit; };
};