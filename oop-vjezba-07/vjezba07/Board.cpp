/*
	[OP] - VJEZBA 7
	@file Board.cpp
	@author Anamarija Papic
*/

#include "Board.hpp"
#include <iostream>

Board::Board(int col, int row)
{
	cols = col;
	rows = row;
	frame = new char* [rows];
	for (int i = 0; i < rows; i++) {
		frame[i] = new char[cols];
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1)
				frame[i][j] = 'o';
			else
				frame[i][j] = ' ';
		}
	}
}

Board::Board(const Board& other)
{
	rows = other.rows;
	cols = other.cols;
	frame = other.frame;
}

Board::Board(Board&& other)
{
	rows = other.rows;
	cols = other.cols;
	frame = other.frame;

	other.rows = 0;
	other.cols = 0;
	other.frame = nullptr;
}

Board::~Board()
{
	for (int i = 0; i < rows; i++) {
		delete[] frame[i];
	}
	delete[] frame;
}

void Board::draw_char(Point p, char ch)
{
	if ((int)p.x <= 0 || (int)p.x >= cols - 1 || (int)p.y <= 0 || (int)p.y >= rows - 1) {
		cout << "Coordinates of point (" << p.x << ", " << p.y << ") exceed dimensions of the board." << endl;
	}
	else {
		// frame[i][j] -> i represents rows, j represents columns in terms of board as a matrix
		// but i represents the y-axis, while j represents the x-axis in terms of a quasi-coordinate system where points are to be drawn
		// so because of that -> frame[p.y][p.x]
		frame[(int)p.y][(int)p.x] = ch;
	}
}

void Board::draw_up_line(Point p, char ch)
{
	Point p0(p.x, 1);
	draw_line(p, p0, ch);
}

void Board::draw_line(Point p1, Point p2, char ch)
{
	Point p;
	double i, j;
	// draw point when both points are equal
	if (p1.x == p2.x && p1.y == p2.y) {
		draw_char(p1, ch);
	}
	// draw vertical line
	else if (p1.x == p2.x) {
		p.x = p1.x;
		for (i = min(p1.y, p2.y); i <= max(p1.y, p2.y); i++) {
			p.y = i;
			draw_char(p, ch);
		}
	}
	// draw horizontal line
	else if (p1.y == p2.y) {
		p.y = p1.y;
		for (j = min(p1.x, p2.x); j <= max(p1.x, p2.x); j++) {
			p.x = j;
			draw_char(p, ch);
		}
	}
	// draw diagonal line
	else if (abs(p1.x - p2.x) == abs(p1.y - p2.y)) {
		if (p1.x > p2.x) {
			swap(p1, p2);
		}
		for (i = p1.y, j = p1.x; j <= p2.x; j++) {
			p.x = j, p.y = i;
			(p1.y < p2.y) ? i++ : i--;
			draw_char(p, ch);
		}
	}
	else {
		cout << "The line between points (" << p1.x << ", " << p1.y << ") and (" << p2.x << ", " << p2.y << ") can't be drawn." << endl;
	}
}

void Board::display()
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << frame[i][j];
		}
		cout << endl;
	}
}