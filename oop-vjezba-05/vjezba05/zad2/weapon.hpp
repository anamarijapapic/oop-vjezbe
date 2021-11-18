/*
	[OP] - VJEZBA 5 - ZADATAK 2
	@file weapon.hpp
	@author Anamarija Papic
*/

#pragma once
#include "../zad1/point.hpp"

class Weapon {
	int bulletsCapacity, bulletsLeft;
public:
	Point position;
	Weapon() : position(), bulletsCapacity(10), bulletsLeft(bulletsCapacity) {};
	Weapon(Point position, int bulletsCapacity);
	bool is_empty() const;
	int get_capacity() { return bulletsCapacity; };
	void shoot();
	void reload();
};