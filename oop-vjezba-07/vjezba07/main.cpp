/*
	[OP] - VJEZBA 7
	@file main.cpp
*/

#include "Board.hpp"

int main()
{
	Point p1(2, 2), p2(8, 8), p3(2, 8), p4(16, 8);
	Board b(20, 10);
	b.draw_line(p1, p2, 'x');
	b.draw_line(p3, p4, 'x');
	b.display();
}