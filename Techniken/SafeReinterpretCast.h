#ifndef SafeReinterpretCast_h
#define SafeReinterpretCast_h 1

#include "CompileTimeChecker.h"

template<class To, class From>
To safe_reinterpret_cast(From from)
{
	{
		class Error_Destination_Type_Too_Narrow
		{};

		CompileTimeChecker<(sizeof(From) <= sizeof(To))>(Error_Destination_Type_Too_Narrow());
	}

	return reinterpret_cast<To>(from);
}

#endif