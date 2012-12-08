// transform.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <iterator>
#include <iostream>
#include <ostream>
#include <boost/lambda/lambda.hpp>
#include <boost/lambda/bind.hpp>

int _tmain(int argc, _TCHAR* argv[])
{
	typedef std::map<int, std::string> AssociativeContainerType;
	typedef AssociativeContainerType::mapped_type MappedType;
	typedef std::vector<MappedType> ContainerType;

	AssociativeContainerType associativeContainer;

	associativeContainer[0] = "Null";
	associativeContainer[1] = "One";
	associativeContainer[2] = "Two";

	ContainerType container;

	std::transform(
		associativeContainer.begin(),
		associativeContainer.end(),
		std::back_inserter(container),
		boost::lambda::bind(&AssociativeContainerType::value_type::second, boost::lambda::_1));

	std::copy(
		container.begin(),
		container.end(),
		std::ostream_iterator<std::string>(std::cout, "\n"));

	return 0;
}

