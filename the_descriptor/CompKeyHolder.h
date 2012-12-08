#pragma once

#include "Identifier.h"

template<unsigned KindValue, unsigned InstanceValue>
struct CompKeyHolder
{
	enum
	{
		Kind = KindValue,
		Instance = InstanceValue
	};

	static Core::Identifier::ComponentKey getKey()
	{
		return Core::Identifier::ComponentKey(
			Kind,
			Instance);
	}
};
