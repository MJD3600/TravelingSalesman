/****************************************************************************
*																			*
*	File:		point.cpp													*
*																			*
*	Author:		Michael James Davis											*
*																			*
*	Date:		Jan 27, 2020												*
*																			*
*	Purpose:	This file implements the member functions and operators		*
*				of the Point class											*
*																			*
****************************************************************************/

//	Header files

#include <iostream>
#include <cassert>
#include "point.h"

/****************************************************************************
*																			*
*	Function:	input														*
*																			*
*	Purpose:	To read a point from the specified input stream				*
*																			*
****************************************************************************/

void Point::input(istream& in)
{
	char c;
	in >> c;			// Read open parenthesis
	assert(c == '(');	// Verify open parenthesis
	
	in >> m_x;			// Read x-coordinate
	
	in >> c;			// Read comma
	assert(c == ',');	// Verify comma
	
	in >> m_y;			// Read y-coordinate
	
	in >> c;			// Read close parenthesis
	assert(c == ')');	// Verify close parenthesis
	
	return;
}

/****************************************************************************
*																			*
*	Function:	output														*
*																			*
*	Purpose:	To write a point into the specified output stream			*
*																			*
****************************************************************************/

void Point::output(ostream& out) const
{
	out << '(' << m_x << ", " << m_y << ')';
	return;
}

/****************************************************************************
*																			*
*	Function:	distance													*
*																			*
*	Purpose:	To find the distance between two points						*
*																			*
****************************************************************************/

double Point::distance(const Point& p) const
{
	return sqrt(pow(m_x - p.m_x, 2) + pow(m_y - p.m_y, 2));
}
		
/****************************************************************************
*																			*
*	Function:	angle														*
*																			*
*	Purpose:	To find the angle between the positive x-axis and the ray	*
*				from the origin to the point								*
*																			*
****************************************************************************/

double Point::angle() const
{
	if (m_x == 0 && m_y == 0)
		return 0;
	else
		return atan2(m_y, m_x);
}

/****************************************************************************
*																			*
*	Function:	operator>>(istream, Point)									*
*																			*
*	Purpose:	To extract a point from the specified input stream			*
*																			*
****************************************************************************/

istream& operator>>(istream& in, Point& p)
{
	p.input(in);
	return in;
}

/****************************************************************************
*																			*
*	Function:	operator<<(ostream, Point)									*
*																			*
*	Purpose:	To insert a point into the specified output stream			*
*																			*
****************************************************************************/

ostream& operator<<(ostream& out, const Point& p)
{
	p.output(out);
	return out;
}

/****************************************************************************
*																			*
*	Function:	operator==(Point, Point)									*
*																			*
*	Purpose:	To determine whether two points are equal					*
*																			*
****************************************************************************/

bool operator==(const Point& p, const Point& q)
{
	return p.isEqual(q);
}

/****************************************************************************
*																			*
*	Function:	operator!=(Point, Point)									*
*																			*
*	Purpose:	To determine whether two points are unequal					*
*																			*
****************************************************************************/

bool operator!=(const Point& p, const Point& q)
{
	return !p.isEqual(q);
}

/****************************************************************************
*																			*
*	Function:	operator+(Point, Point)										*
*																			*
*	Purpose:	To add two points together									*
*																			*
****************************************************************************/

Point operator+(const Point& p, const Point& q)
{
	return p.add(q);
}

/****************************************************************************
*																			*
*	Function:	operator-(Point, Point)										*
*																			*
*	Purpose:	To subtract one point from another point					*
*																			*
****************************************************************************/

Point operator-(const Point& p, const Point& q)
{
	return p.add(-q);
}

/****************************************************************************
*																			*
*	Function:	operator*(double, Point)									*
*																			*
*	Purpose:	To multiply a point by a scalar								*
*																			*
****************************************************************************/

Point operator*(double s, const Point& p)
{
	return p.scalarMultiply(s);
}

/****************************************************************************
*																			*
*	Function:	operator<(Point, Point)										*
*																			*
*	Purpose:	To determine whether one point is less than another point	*
*																			*
****************************************************************************/

bool operator<(const Point& p, const Point& q)
{
	return p.isLessThan(q);
}
