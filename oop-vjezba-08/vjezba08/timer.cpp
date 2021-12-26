/*
    [OP] - VJEZBA 8
    @file timer.cpp
    @author Anamarija Papic
*/

#include "timer.hpp"

void Timer::set_timer(double time)
{
    h = time / 3600;
    m = (time - (double)h * 3600) / 60;
    s = time - ((double)h * 3600 + (double)m * 60);
}

Timer& Timer::operator+=(const Timer& t)
{
    double time = double(*this);
    time += double(t.h) * 3600 + double(t.m) * 60 + t.s;
    set_timer(time);
    return *this;
}

Timer& Timer::operator-=(const Timer& t)
{
    double time = double(*this);
    time -= double(t.h) * 3600 + double(t.m) * 60 + t.s;
    set_timer(time);
    return *this;
}

Timer Timer::operator+(const Timer& t) 
{
    timer new_timer;
    double time = double(*this) + (double(t.h) * 3600 + double(t.m) * 60 + t.s);
    new_timer.set_timer(time);
    return new_timer;
}

Timer Timer::operator-(const Timer& t)
{
    timer new_timer;
    double time = double(*this) - (double(t.h) * 3600 + double(t.m) * 60 + t.s);
    new_timer.set_timer(time);
    return new_timer;
}

Timer& Timer::operator/=(const size_t& n)
{
    double time = double(*this);
    time /= n;
    set_timer(time);
    return *this;
}

Timer Timer::operator/(const size_t& n) 
{
    timer new_timer;
    double time = double(*this) / n;
    new_timer.set_timer(time);
    return new_timer;
}

ostream& operator<<(ostream& os, const Timer& t)
{
    return os << t.h << ":" << t.m << ":" << t.s;
}

Timer::operator double() const
{
    return double(h) * 3600 + double(m) * 60 + s;
}

bool Timer::operator<(const Timer& t)
{
    return(double(*this) < double(t));
}

void Penalty::operator()(Timer& t)
{  
    t.set_timer(double(t) + p);
}