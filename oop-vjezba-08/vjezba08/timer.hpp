/*
    [OP] - VJEZBA 8
    @file timer.hpp
    @author Anamarija Papic
*/

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef class Timer {
    int h, m;
    double s;
public:
    Timer() : h(0), m(0), s(0) {}
    Timer(int hours, int minutes, double seconds) : h(hours), m(minutes), s(seconds) {}
    int get_hours() { return h; }
    int get_minutes() { return m; }
    double get_seconds() { return s; }
    void set_hours(int hours) { h = hours; }
    void set_minutes(int minutes) { m = minutes; }
    void set_seconds(double seconds) { s = seconds; }
    void set_timer(double time);
    Timer& operator+=(const Timer& t);
    Timer& operator-=(const Timer& t);
    Timer operator+(const Timer& t);
    Timer operator-(const Timer& t);
    Timer& operator/=(const size_t& n);
    Timer operator/(const size_t& n);
    friend ostream& operator<<(ostream& out, const Timer& t);
    operator double() const;
    bool operator<(const Timer& t);
} timer;

typedef class Penalty {
    int p;
public:
    Penalty(double penalty) : p(penalty) {}
    void operator()(Timer& t);
} penalty;