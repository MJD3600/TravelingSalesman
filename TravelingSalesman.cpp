/****************************************************************************
*																			*
*	Program:	TravelingSalesman.cpp										*
*																			*
*	Author:		Michael James Davis											*
*																			*
*	Date:		Mar 4, 2020													*
*																			*
*	Purpose:	This program will solve the Traveling Salesman problem		*
*																			*
****************************************************************************/

//	Include header files

#include <iostream>
#include <cfloat>
#include <algorithm>
#include <ctime>
#include <fstream>
#include <string>
#include <windows.h>
#include "hiResTimer.h"
#include "Point Class/point.h"

using namespace std;

/****************************************************************************
*																			*
*	The definition of the City class										*
*																			*
****************************************************************************/

class City
{
//	Public member functions

	public:

	//	Constructors

		City() {};
		City(string nm, Point loc) : name(nm), location(loc) {}

	//	Inspectors

		Point getLocation() const {return location;}
		string getName() const {return name;}

//	Private data members

	private:
		string name;
		Point location;
};

//	Function prototypes

City* shortestPath(City* city, int n);

/****************************************************************************
*																			*
*	Function:	main														*
*																			*
****************************************************************************/

int main()
{
	CHighResTimer timer;
	srand(time(NULL));
	
//	Open an Excel output file

	ofstream fout("FactorialGrowth.xls");
	if (!fout)
	{
		cerr << "Failed to open output file.  Be sure file is not in use.";
		exit(1);
	}

//	City names

	string name[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", 
		"N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
	
//	Get starting value

	cout << "Enter the number of cities:  ";
	int first;
	cin >> first;

//	Execute the loop with values n, n + 1, n + 2, ..., n + 9

	for (int n = first; n < first + 1; n++)
	{
	//	Get the data on the cities

		City* city = new City[n];
	
		for (int i = 0; i < n; i++)
		{
			Point loc = Point(rand() % 10, rand() % 10);
			city[i] = City(name[i], loc);
			cout << "City " << city[i].getName() << " at " << city[i].getLocation() << endl;
		}

	// Get start time

		timer.StartTime();
		
	//	Find the shortest path

		City* path = shortestPath(city, n);

	//	Print the results

		cout << "For " << n << " cities: ";
		for (int i = 0; i < n - 1; i++)
			cout << path[i].getName() << ", ";
		cout << path[n - 1].getName() << endl;
		
	//	Report run time

		double time = timer.GetSeconds();
		
		cout << "Elapsed time = " << time << " secs" << endl << endl;
		fout << n << '\t' << time << '\r';
	}
	cout << "Done" << endl;
	
	return 0;
}

bool operator<(const City& c1, const City& c2);
bool operator<(const City& c1, const City& c2)
{
	return c1.getName() < c2.getName();
}

/****************************************************************************
*																			*
*	Function:	shortestPath												*
*																			*
*	Purpose:	To find the shortest path that passes through all	 		*
*				the cities, starting and ending at city[0]					*
*																			*
****************************************************************************/

City* shortestPath(City* city, int n)
{
//	Arrange the cities in the lexicographically-first permutation

	sort(city, city + n);
	
//	Initialize the minimum distance

	double minDist = FLT_MAX;	// Defined in cfloat
	City* path = new City[n];	// Sequence of cities

//	Try every permutation

	do
	{
	//	Always start at city[0]
	
		double dist = city[0].getLocation().distance(city[1].getLocation());
		
	//	Compute distances for this permutation
	
		for (int i = 1; i < n - 1; i++)
			dist += city[i].getLocation().distance(city[i + 1].getLocation());
	
	//	Always end at city[0]
	
		dist += city[n - 1].getLocation().distance(city[0].getLocation());
		
	//	See if this is the best so far
	
		if (dist < minDist)
		{
			minDist = dist;
			for (int i = 0; i < n; i++)
				path[i] = city[i];		// Save this path
		}
	
	//	Continue to the next permutation of cities

	} while (next_permutation(city + 1, city + n));

//	Report length of shortest and second-shortest paths

	cout << "Shortest path: " << minDist << endl;
	
//	Return the shortest path

	return path;
}