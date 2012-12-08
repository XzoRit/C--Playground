// the_descriptor.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

//#include <iostream>

#include "descriptor_01.h"
#include "descriptor_01_ComIds.h"
#include "descriptor_01_MeasIds.h"

int _tmain(int argc, _TCHAR* argv[])
{
    Core::CommunicationIdentifier c1 = Descr_01::ComId<MyComId>::get(MyComId::Cone);
    Core::CommunicationIdentifier c2 = Descr_01::ComId<MyComId>::get(MyComId::Ctwo);
	Core::CommunicationIdentifier c3 = Descr_01::ComId<MyComId>::get(MyComId::Cthree);
    //Core::CommunicationIdentifier c4 = Descr_01::ComId<MyComId>::get(1);

    Core::NumericalMeasureIdentifier nm1 = Descr_01::NumMeasId<MyNumMeasId>::get(MyNumMeasId::NMone);
    //Core::NumericalMeasureIdentifier nm2 = Descr_01::NumMeasId<MyNumMeasId>::get(MyComId::Cone);
    //Core::NumericalMeasureIdentifier nm3 = Descr_01::NumMeasId<MyNumMeasId>::get(1);

    //std::cout << c1.toString() << "\n";
    //std::cout << c2.toString() << "\n";
    //std::cout << nm1.toString() << "\n";

    return 0;
}