/*
	[OP] - VJEZBA 5 - ZADATAK 1
	@file point.cpp
	@author Anamarija Papic
*/

#include <cstdlib>
#include <cmath>
#include "point.hpp"
using namespace std;

void Point::set(double x, double y, double z)
{
	this->x = x, this->y = y, this->z = z;
}

void Point::set_pseudorandom(double lowerBound, double upperBound)
{
	x = lowerBound + ((double)rand() / RAND_MAX) * (upperBound - lowerBound);
	y = lowerBound + ((double)rand() / RAND_MAX) * (upperBound - lowerBound);
	z = lowerBound + ((double)rand() / RAND_MAX) * (upperBound - lowerBound);
}

void Point::get(double& x, double& y) const
{
	x = this->x, y = this->y;
}

void Point::get(double& x, double& y, double& z) const
{
	x = this->x, y = this->y, z = this->z;
}

double Point::calculate_2D_distance(Point P) const
{
	double xP, yP;
	P.get(xP, yP);
	return sqrt(pow(this->x - xP, 2) + pow(this->y - yP, 2));
}

double Point::calculate_3D_distance(Point P) const
{
	double xP, yP, zP;
	P.get(xP, yP, zP);
	return sqrt(pow(this->x - xP, 2) + pow(this->y - yP, 2) + pow(this->z - zP, 2));
}

void Point::print() const
{
	cout << "x = " << x << ", y = " << y << ", z = " << z << endl;
}