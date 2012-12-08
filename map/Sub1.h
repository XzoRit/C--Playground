#ifndef SUB1_H
#define SUB1_H

#include <iostream>
#include "Base.h"

class Sub1 : public Base
{
public:
	Sub1(Base::Id id) : Base(id){};
	virtual ~Sub1(){};
	virtual void doSomething()
	{
		std::cout << "I am Sub1 with id: " <<  this->m_id << std::endl;
	}
};

#endif