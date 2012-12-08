#pragma once

#include "EnumEntries.h"


namespace Number
{
	NAMED_ENUM(Cypher)
		ENTRY(Zero),
		ENTRY(One),
		ENTRY(Two),
		ENTRY_NAME(Three, "Drei"),
		ENTRY_NAME_VALUE(Five, "Fünf", 5),
		ENTRY(Six);
}

/*
namespace Number
{
	class Cypher_enum_impl
	{
	};
	typedef enum_entry<Cypher_enum_impl> Cypher;
	Cypher One("One"), Two("Two"), Three("Drei"), Five("Fünf", 5);
}
*/