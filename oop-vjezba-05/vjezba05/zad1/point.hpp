/*
	[OP] - VJEZBA 5 - ZADATAK 1
	@file point.hpp
	@author Anamarija Papic
*/

#pragma once
#include <iostream>

class Point {
	double x, y, z;
public:
	Point(double x, double y, double z) { set(x, y, z); };
	Point() : Point(0, 0, 0) {};
	void set(double x, double y, double z);
	void set_pseudorandom(double lowerBound, double upperBound);
	void get(double& x, double& y) const;
	void get(double& x, double& y, double& z) const;
	double getX() { return x; };
	double getY() { return y; };
	double getZ() { return z; };
	double calculate_2D_distance(Point P) const;
	double calculate_3D_distance(Point P) const;
	void print() const;
};