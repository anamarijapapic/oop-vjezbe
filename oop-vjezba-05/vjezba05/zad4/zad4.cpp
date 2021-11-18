/*
	[OP] - VJEZBA 5 - ZADATAK 4
	@file zad4.cpp
	@author Anamarija Papic
*/

#define MIN_BOUND -20
#define MAX_BOUND 20
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../zad1/point.hpp"
#include "../zad1/point.cpp"
#include "../zad2/weapon.hpp"
#include "../zad2/weapon.cpp"
#include "../zad3/target.hpp"
using namespace std;

int main()
{
	srand((unsigned)time(NULL));

	// generate targets
	int targetNum;
	do {
		cout << "Enter the number of targets to generate: ";
		cin >> targetNum;
		if (targetNum <= 0)
			cout << "Invalid entry! Number of targets must be larger than 0." << endl;
	} while (targetNum <= 0);
	Target* targets = new Target[targetNum];
	Point bottomLeft, upperRight;
	for (int i = 0; i < targetNum; i++) {
		targets[i].bottomLeft.set_pseudorandom(MIN_BOUND, MAX_BOUND);
		targets[i].upperRight.set_pseudorandom(MIN_BOUND, MAX_BOUND);
		while (targets[i].upperRight.getZ() <= targets[i].bottomLeft.getZ())
			targets[i].upperRight.set_pseudorandom(MIN_BOUND, MAX_BOUND);
	}

	// generate weapon
	int capacity;
	do {
		cout << endl << "Enter the bullet capacity for your gun: ";
		cin >> capacity;
		if (capacity <= 0)
			cout << "Invalid entry! Capacity must be larger than 0." << endl;
	} while (capacity <= 0);
	Point gunPosition;
	gunPosition.set_pseudorandom(MIN_BOUND, MAX_BOUND);
	Weapon gun(gunPosition, capacity);
	cout << "Gun position is: ";
	gunPosition.print();

	gun.reload();

	// shoot and check how many targets are hit
	int hitTargets = 0;
	while (!gun.is_empty()) {
		gun.shoot();
		for (int i = 0; i < targetNum; i++) {
			if ((gun.position.getZ() >= targets[i].bottomLeft.getZ()) && (gun.position.getZ() <= targets[i].upperRight.getZ()))
				targets[i].set_hit_status(true);
		}
	}
	for (int i = 0; i < targetNum; i++)
		if (targets[i].get_hit_status())
			hitTargets++;
	cout << endl << hitTargets << " targets were hit with one fully loaded gun magazine (" << gun.get_capacity() << " bullets)." << endl;
	
	delete[] targets;
	return 0;
}