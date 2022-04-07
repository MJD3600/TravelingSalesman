/****************************************************************************
*																			*
*	File:		point.h														*
*																			*
*	Author:		Michael Davis												*
*																			*
*	Date:		Jan 27, 2020												*
*																			*
*	Purpose:	This file contains the definition of the Point class		*
*				and related operators										*
*																			*
****************************************************************************/

#ifndef POINT_H
#define POINT_H

//	Header files

#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

/****************************************************************************
*																			*
*	Definition of the Point class											*
*																			*
****************************************************************************/

class Point
{
	//	Public member functions

public:

	//	Constructors

		Point() : m_x(0), m_y(0) {}			// Default constructor
		Point(double xval, double yval)		// Construct point from 2 doubles
			: m_x(xval), m_y(yval) {}

	//	Inspectors
	
		double x() const { return m_x; }	// Return the x-coordinate
		double y() const { return m_y; }	// Return the y-coordinate

	//	Mutators
	
		void x(double xval) { m_x = xval; }	// Set the x-coordinate
		void y(double yval) { m_y = yval; }	// Set the y-coordinate

	//	Facilitators
	
		void input(istream& in);			// Extract this pt from istream
		void output(ostream& out) const;	// Insert this pt into ostream
		bool isEqual(const Point& p) const	// See if pt equals this pt
		{ return m_x == p.m_x && m_y == p.m_y; }
		Point add(const Point& p) const		// Add pt to this pt
		{ return Point(m_x + p.m_x, m_y + p.m_y); }
		Point scalarMultiply(double s) const	// Multiply this pt by scalar
		{ return Point(s*m_x, s*m_y); }
		bool isLessThan(const Point& p) const
		{
			if (m_x + m_y != p.m_x + p.m_y) return m_x + m_y < p.m_x + p.m_y; else return m_x < p.m_x;
		}
		
	//	Operators
	
		Point operator-() const				// Negate this point
		{ return Point(-m_x, -m_y); }
	
	//	Other member functions
	
		double distance(const Point& p) const;	// Distance between points
		double angle() const;				// Angle made with pos x-axis

//	Private data members

	private:

		double m_x;		// x-coordinate of the point
		double m_y;		// y-coordinate of the point
};

/****************************************************************************
*																			*
*	Operators																*
*																			*
****************************************************************************/

//	Input-Output Operators

istream& operator>>(istream& in, Point& p);
ostream& operator<<(ostream& out, const Point& p);

//	Equality Operators

bool operator==(const Point& p, const Point& q);
bool operator!=(const Point& p, const Point& q);

//	Arithmetic Operators

Point operator+(const Point& p, const Point& q);
Point operator-(const Point& p, const Point& q);
Point operator*(double s, const Point& p);

bool operator<(const Point& p, const Point& q);

#endif