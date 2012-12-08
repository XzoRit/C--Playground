// template_template_parameter.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

#include <vector>
#include <list>
#include <map>
#include <set>

template<
	template<typename, typename> typename T1,
	template<typename, typename> typename T2,
	template<typename, typename, typename> typename T3,
	template<typename, typename, typename, typename> typename T4>
struct Relation
{
	T1<int> m_cont1;
	T2<int> m_cont2;
	T3<int> m_cont3;
	T4<int, double> m_cont4;
};

int _tmain(int argc, _TCHAR* argv[])
{
	Relation<std::vector, std::list, std::set, std::map> r;
	return 0;
}

