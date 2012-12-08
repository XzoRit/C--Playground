#ifndef SUB2_H
#define SUB2_H

#include <iostream>
#include "Base.h"

class Sub2 : public Base
{
public:
	Sub2(Base::Id id) : Base(id){};
	virtual ~Sub2(){};
	virtual void doSomething()
	{
		std::cout << "I am Sub2 with id: " <<  this->m_id << std::endl;
	}
};

#endif