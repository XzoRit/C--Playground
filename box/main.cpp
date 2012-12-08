// box.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "Any.h"
#include "Box.h"
#include "Packet.h"
#include "Thing.h"
#include "TypeIdBase.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <map>

#include <boost/mpl/set.hpp>
#include <boost/fusion/container/map.hpp>
#include <boost/fusion/sequence/intrinsic/at_key.hpp>

struct MyStruct
{
	char c;
	float f;
	std::string s;
};

struct TypeDefinerBase
{
    enum
	{
		TypeNotFound,
		UserTypeId
	};

	template<typename T>
	int getTypeId(const T& val) const
	{
		Vergessen für den Typen
		eine getTypeId-Funktion zu definieren?
	}
};

struct MyTypeDefiner : public TypeDefinerBase
{
	typedef enum TypeIdEnum
	{
		MyIntTypeId = TypeDefinerBase::UserTypeId,
		MyStringTypeId,
		MyMyStructTypeId
	} TypeId;

	typedef boost::fusion::map<
		boost::fusion::pair<int, TypeId>,
		boost::fusion::pair<std::string, TypeId>,
		boost::fusion::pair<MyStruct, TypeId> >
	map_type;

	map_type m_map;

	//using TypeDefinerBase::getTypeId;

	MyTypeDefiner()
		: TypeDefinerBase()
		, m_map(
			boost::fusion::make_pair<int>(MyIntTypeId),
			boost::fusion::make_pair<std::string>(MyStringTypeId),
			boost::fusion::make_pair<MyStruct>(MyMyStructTypeId))
	{
	}

	template<typename T>
	int getTypeId(const T& val) const
	{
		return boost::fusion::at_key<T>(m_map);
	}

	//int getTypeId(const int&) const
	//{
	//	return MyIntTypeId;
	//}

	//int getTypeId(const std::string&) const
	//{
	//	return MyStringTypeId;
	//}

	//int getTypeId(const MyStruct&) const
	//{
	//	return MyMyStructTypeId;
	//}
};

struct MyTypeId : public TypeIdBase<MyTypeId>
{
	typedef enum TypeIdEnum
	{
		MyIntTypeId = TypeDefinerBase::UserTypeId,
		MyStringTypeId,
		MyMyStructTypeId
	} TypeId;

	typedef
		boost::mpl::set<int, std::string, MyStruct>
		SupportedTypes;

	static int typeId(const int&)
	{
		return MyIntTypeId;
	}

	static int typeId(const std::string&)
	{
		return MyStringTypeId;
	}

	static int typeId(const MyStruct&)
	{
		return MyMyStructTypeId;
	}
};

struct print
{
	template<typename T>
	void operator() (const T& value)
	{
		if(const int* pi = any_cast<int>(&value))
		{
			std::cout << (*pi) << std::endl;
		}

		if(const std::string* ps = any_cast<std::string>(&value))
		{
			std::cout << (*ps) << std::endl;
		}
	}
};

struct print_packet
{
	template<typename T>
	void operator() (const T& value) const
	{
		if(const int* const pi = value.get<int>())
		{
			std::cout << (*pi) << std::endl;
		}

		else if(const std::string* const ps = value.get<std::string>())
		{
			std::cout << (*ps) << std::endl;
		}

		else if(const MyStruct* const ps = value.get<MyStruct>())
		{
			std::cout << (*ps).c << std::endl;
			std::cout << (*ps).f << std::endl;
			std::cout << (*ps).s << std::endl;
		}
		else
		{
			std::cout << '?' << std::endl;
		}
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Any a = 32;
	Any b = std::string("ashjd");

	if(int* pi = any_cast<int>(&a))
	{
		std::cout << (*pi) << std::endl;
	}

	if(std::string* ps = any_cast<std::string>(&b))
	{
		std::cout << (*ps) << std::endl;
	}

	Box box;

	box.push_back(234);
	box.push_back(std::string("hsdfhs"));

	std::for_each(box.begin(), box.end(), print());

	for(Box::Iterator it(box.begin());
		it != box.end();
		++it)
	{
		if(int* pi = box.get<int>(0))
		{
			std::cout << (*pi) << std::endl;
		}
		if(std::string* ps = box.get<std::string>(1))
		{
			std::cout << (*ps) << std::endl;
		}
	}


	Thing<MyTypeDefiner> t1 = 171177;
	Thing<MyTypeDefiner> t2 = std::string("hsahafsh");
	MyStruct myStruct = {};
	myStruct.c = 'J';
	myStruct.f = 748.948f;
	myStruct.s = "ztwp";
	Thing<MyTypeDefiner> t3 = myStruct;


	if(int* i = t1.get<int>())
	{
		std::cout << (*i) << std::endl;
	}
	if(std::string* i = t2.get<std::string>())
	{
		std::cout << (*i) << std::endl;
	}
	if(std::string* i = t1.get<std::string>())
	{
		std::cout << (*i) << std::endl;
	}
	else
	{
		std::cout << '?' << std::endl;
	}
	if(int* i = t2.get<int>())
	{
		std::cout << (*i) << std::endl;
	}
	else
	{
		std::cout << '?' << std::endl;
	}

	typedef Packet<MyTypeDefiner> PacketType;
	PacketType packet;

	packet.push_back(2938);
	packet.push_back(std::string("shagshzzeue"));
	packet.push_back(9889.98f);
	packet.push_back(myStruct);

	std::for_each(packet.begin(), packet.end(), print_packet());

	for(PacketType::iterator it(packet.begin());
		it != packet.end();
		++it)
	{
		if(int* pi = it->get<int>())
		{
			std::cout << (*pi) << std::endl;
		}
		if(std::string* ps = it->get<std::string>())
		{
			std::cout << (*ps) << std::endl;
		}
	}

	//packet_worker(packet);

	typedef std::map<std::string, Thing<MyTypeDefiner> > PropertyType;
	PropertyType properties;

	properties.insert(std::make_pair("int", 28789));
	properties.insert(std::make_pair("string", std::string("izzjdfgv")));

	if(int * i = properties["int"].get<int>())
	{
		std::cout << "property: " << (*i) << std::endl;
	}

	//Packet<MyTypeId> pac;

	//pac.push_back(879789);
	//pac.push_back(std::string("rsfdjdfg"));
	//MyStruct myStruct = {};
	//myStruct.c = 'J';
	//myStruct.f = 748.948f;
	//myStruct.s = "ztwp";
	//pac.push_back(myStruct);
	////pac.push_back(432.789f);
	//
	//std::for_each(pac.begin(), pac.end(), print_packet());

	return 0;
}

