// hash.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <cassert>
#include <set>
#include <boost/functional/hash.hpp>


class Point
{
public:
	Point()
		: m_x(0)
		, m_y(0)
	{
	}

	Point(int x, int y)
		: m_x(x)
		, m_y(y)
	{
	}

	bool operator==(const Point& other) const
	{
		return ((m_x == other.m_x) && (m_y == other.m_y));
	}

	friend std::size_t hash_value(const Point& p)
	{
		std::size_t seed = 0;
		boost::hash_combine(seed, p.m_x);
		boost::hash_combine(seed, p.m_y);

		return seed;
	}

private:
	int m_x;
	int m_y;
};

int _tmain(int argc, _TCHAR* argv[])
{
	boost::hash<Point> pointHasher;

	Point p1(0, 0);
  Point p2(1, 2);
  Point p3(4, 1);
  Point p4 = p1;

  assert(pointHasher(p1) == pointHasher(p4));

  assert(pointHasher(p1) != pointHasher(p2));
  assert(pointHasher(p1) != pointHasher(p3));

	//std::set<Point, boost::hash<Point> > pointContainer;
	//pointContainer.insert(p1);

	return 0;
}

