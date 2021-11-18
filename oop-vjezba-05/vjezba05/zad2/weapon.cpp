/*
	[OP] - VJEZBA 5 - ZADATAK 2
	@file weapon.cpp
	@author Anamarija Papic
*/

#include <iostream>
#include "weapon.hpp"
using namespace std;

Weapon::Weapon(Point position, int bulletsCapacity)
{
	this->position = position;
	this->bulletsCapacity = bulletsCapacity;
	this->bulletsLeft = bulletsCapacity;
}

bool Weapon::is_empty() const
{
	return (bulletsLeft == 0);
}

void Weapon::shoot()
{
	--bulletsLeft;
}

void Weapon::reload()
{
	bulletsLeft = bulletsCapacity;
}