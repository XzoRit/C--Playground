// mem_fun.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

class Status
{
public:

	static void printTwo(Status s1, Status s2)
	{
		std::cout << s1.m_id << " und " << s2.m_id << std::endl;
	}

	Status()
		: m_broken(false), m_id(s_id++)
	{}

	void print()
	{
		std::cout << m_id << ": " << m_broken << std::endl;
	}

	void breakIt()
	{
		m_broken = true;
	}
	
	bool isBroken() const
	{
		return m_broken;
	}

private:
	static unsigned int s_id;
	bool m_broken;
	unsigned int m_id;
};

unsigned int Status::s_id = 0;

bool operator==(const Status& s1, const Status& s2)
{
	return s1.isBroken() == s2.isBroken();
}

class StatusReporter
{
public:
	void report(Status s) const
	{
		s.print();
	}
};

void printStatus(Status& status)
{
	status.print();
}

void printInt(int i)
{
	std::cout << i << std::endl;
}

void printStatusWithReporter(Status s, StatusReporter sr)
{
	sr.report(s);
}

int _tmain(int argc, _TCHAR* argv[])
{
	typedef std::vector<Status> StatusContainer;

	StatusContainer stati;
	Status stat1, stat2, stat3;

	stati.push_back(stat1);
	stati.push_back(stat2);
	stati.push_back(stat3);

	stati.at(2).breakIt();

	std::cout << "bind to member-function:" << std::endl;
	std::for_each(
		stati.begin(),
		stati.end(),
		std::mem_fun_ref(&Status::print));

	std::cout << "bind to free-function:" << std::endl;
	std::for_each(
		stati.begin(),
		stati.end(),
		std::ptr_fun(&printStatus));

	Status stat;
	stat.breakIt();
	std::cout << "bind1st for equality-test:" << std::endl;
	StatusContainer::iterator match = (std::find_if(
		stati.begin(),
		stati.end(),
		std::bind1st(std::equal_to<Status>(), stat)));
	if(match != stati.end())
	{
		(*match).print();
	}
	std::cout << "bind2nd for equality-test:" << std::endl;
	match = (std::find_if(
		stati.begin(),
		stati.end(),
		std::bind2nd(std::equal_to<Status>(), stat)));
	if(match != stati.end())
	{
		(*match).print();
	}

	std::cout << "bind1st to static-member-function:" << std::endl;
	std::for_each(
		stati.begin(),
		stati.end(),
		std::bind1st(
			std::ptr_fun(&Status::printTwo), stat));

	std::cout << "bind2nd to static-member-function:" << std::endl;
	std::for_each(
		stati.begin(),
		stati.end(),
		std::bind2nd(
			std::ptr_fun(&Status::printTwo), stat));

	StatusReporter sr;
	std::cout << "bind1st to member-function from other class:" << std::endl;
	std::for_each(
		stati.begin(),
		stati.end(),
		std::bind1st(
			std::mem_fun_ref(&StatusReporter::report), sr));

	std::cout << "bind2nd to free-function:" << std::endl;
	std::for_each(
		stati.begin(),
		stati.end(),
		std::bind2nd(
			std::ptr_fun(&printStatusWithReporter), sr));

	std::cout << "transform container of ints:" << std::endl;
	std::vector<int> ints;
	ints.push_back(1);
	ints.push_back(2);
	ints.push_back(3);
	std::transform(
		ints.begin(),
		ints.end(),
		ints.begin(),
		std::bind1st(std::plus<int>(), 4));
	std::for_each(
		ints.begin(),
		ints.end(),
		std::ptr_fun(&printInt));

	return 0;
}

