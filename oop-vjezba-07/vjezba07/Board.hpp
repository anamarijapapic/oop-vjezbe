/*
	[OP] - VJEZBA 7
	@file Board.hpp
	@author Anamarija Papic
*/

#pragma once
using namespace std;

typedef struct Point {
public:
	double x, y;
	Point() = default;
	Point(double px, double py) : x(px), y(py) {};
} Point;

class Board {
	int rows, cols;
	char** frame;
public:
	Board() = default;
	Board(int col, int row);
	Board(const Board& b);
	Board(Board&& b);
	~Board();
	void draw_char(Point p, char ch);
	void draw_up_line(Point p, char ch);
	void draw_line(Point p1, Point p2, char ch);
	void display();
};