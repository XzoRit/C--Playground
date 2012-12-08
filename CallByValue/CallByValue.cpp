// CallByValue.cpp: Hauptprojektdatei.

#include "stdafx.h"
#include <iostream>

class Car
{
public:
	Car(int numOfTires)
		: m_numOfTires(numOfTires)
	{}

	void setNumOfTires(int numOfTires)
	{
		m_numOfTires = numOfTires;
	}

	int getNumOfTires()
	{
		return m_numOfTires;
	}

private:
	int m_numOfTires;
};

void changeCar1(Car* car)
{
	car = new Car(6);
}

void changeCar1(Car& car)
{
	car.setNumOfTires(7);
}

void changeCar2(Car*& car)
{
	car = new Car(8);
}

int main()
{
	Car* car = new Car(4);
	changeCar1(car);

	std::cout << car->getNumOfTires() << std::endl;

	changeCar1(*car);

	std::cout << car->getNumOfTires() << std::endl;

	changeCar2(car);

	std::cout << car->getNumOfTires() << std::endl;

    return 0;
}
