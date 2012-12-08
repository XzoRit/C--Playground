// IdentifierToString.cpp : Defines the entry boost::program_optionsint for the console application.
//

#include "stdafx.h"
#include "Core/Interface/Base/Identifier.h"
#include "TestsBabylogC/TestUtilities/Mock/BridgeDefinitions.h"
#include <boost/lambda/lambda.hpp>
#include <boost/lambda/bind.hpp>
#include <boost/lambda/construct.hpp>
#include <boost/program_options.hpp>
#include <boost/bind.hpp>
#include <boost/ref.hpp>
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/range.hpp>
#include <boost/regex.hpp>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <iterator>
#include <ios>
#include <fstream>

typedef std::vector<int> DecIdContainer;
typedef std::vector<std::string> StringIdContainer;
typedef std::vector<Core::Identifier> CoreIdContainer;
typedef std::map<int, std::string> GroupKeyToStringContainer;
typedef boost::iterator_range<char*> IteratorRangeCharPointer;

GroupKeyToStringContainer::value_type::second_type piGroupKeyToString(Core::Identifier identifier, GroupKeyToStringContainer container)
{
	GroupKeyToStringContainer::iterator it = container.find(identifier.getGroupKey().getInternal());
	if(it != container.end())
	{
		return it->second;
	}
	else
	{
		return "Unknown";
	}
}

const char* getComponentName(const Core::Identifier::ComponentKey compKey)
{
	unsigned short compNum = compKey.getInternal() >> 2;
	switch(compNum)
	{
		case 1:
            return "S16_Core";
		case 0x0a:   
			return "S16_LungCommon";
		case Bridge::BridgeDefinitions::BRIDGE_ID:
			return "S16_BRG";
		case 0x06:
			return "S16_MIB";       
		case 0x0f:
			return "S30_Module"; 
		case 0x09:
			return "S16_Test";
		case 0x02:
			return "S16_ExtendedCore";
		case 0x170:
			return "S17onM16";
		case 0x171:
			return "S17onM16";
		case 0x172:
			return "S17onM16";
		case 0x190:
			return "S19onM16";
		case 0x013:
			return "M1V3";
		case 0x041:
			return "M4V1";
		case 0x121:
			 return "M12.1";
		case 0x124:
			return "M12.4";
		case 0x301:
		case 0x300:
			 return "PrsOnM16";
		case 0x151:
			return "M15V1";
		case 0x152:
			return "M15V2";
		case 0x210:
			return "M21";
		case 0x220:
			return "S22";
		default:
			return "Unknown";
	}
}

void printDecIdContainerAsCoreId(DecIdContainer& decIds, GroupKeyToStringContainer& piGroupKeyToStringEntries)
{
	try
	{
		CoreIdContainer coreIds;
		std::transform
			(
				decIds.begin(),
				decIds.end(),
				coreIds.begin(),
				std::back_inserter(coreIds),
				boost::lambda::bind
				(
					boost::lambda::constructor<Core::Identifier>(),
					boost::lambda::_1
				)
			);

		char buf[1024];
		std::for_each
			(
				coreIds.begin(),
				coreIds.end(),
				(
					std::cout
					<< boost::lambda::constant("Component: ")
					<< boost::lambda::var(std::dec)
					<< boost::lambda::bind
					(
						&getComponentName,
						boost::lambda::bind
						(
							&Core::Identifier::getComponentKey,
							boost::lambda::_1
						)						
					)
					<< boost::lambda::constant(" Pi GroupKey: ")
					<< boost::lambda::bind
					(
						&piGroupKeyToString,
						boost::lambda::_1,
						boost::lambda::constant(piGroupKeyToStringEntries)
					)
					<< '\n'
					<< boost::lambda::constant("dec: ")
					<< boost::lambda::var(std::dec)
					<< boost::lambda::bind
					(
						&Core::Identifier::getInternal,
						boost::lambda::_1
					)
					<< "\thex: "
					<< std::hex
					<< boost::lambda::bind
					(
						&Core::Identifier::getInternal,
						boost::lambda::_1
					)
					<< "\tstring: "
					<< boost::lambda::bind
					(
						&Core::Identifier::toString,
						boost::lambda::_1,
						static_cast<char*>(buf),
						sizeof(buf)
					)
					<< '\n'
				)
			);
	}
	catch(...)
	{
		std::cout << "Unknow Identifier" << std::endl;
	}
}

void fillGroupKeyToStringContainer(GroupKeyToStringContainer& container)
{
	boost::filesystem::path piBlackBoardGroupKeyEnumPath =
		boost::filesystem::complete(
			boost::filesystem::path(
				"Z:\\perseus\\BabylogC_sw\\BabylogC\\base\\Descriptors\\BabylogTherapyUnitProperties.h",
				boost::filesystem::native));
	boost::filesystem::ifstream in(piBlackBoardGroupKeyEnumPath);
	char text[128];
	IteratorRangeCharPointer endOfEnumFinder;
	int enumCounter = 1;

	do
	{
		in.getline(text, sizeof(text));
		if(!(boost::algorithm::find_first(text, ",").empty()))
		{
			std::string str(text);
			boost::algorithm::trim(str);
			
			boost::regex re("(\\w+)");
			boost::smatch m;
			if(boost::regex_search(str, m, re))
			{
				str.assign(m[1].first, m[1].second);
				container.insert(std::make_pair(enumCounter++, str));
			}
		}
		endOfEnumFinder = boost::algorithm::find_first(text, "BabylogGroupKeys;");
	} while(endOfEnumFinder.empty());
}

int _tmain(int argc, _TCHAR* argv[])
{
	const char optionHelp[] = "help";
	const char optionIdString[] = "id";

	boost::program_options::options_description desc("Optional options");
	desc.add_options()
		(	
			optionHelp,
			"Produces this help message.\n"
			"Will also be displayed if started without any options.\n"
		)
		(
			"id,i",
			boost::program_options::value<StringIdContainer>(),
			"Identifier as hex with 0x and as dec without 0x at the beginning which will be converted to string.\n"
			"Example: \tIdentifierToString.exe --id 0x12345678\n\n"
			"Multiple identifiers are possible, too.\n"
			"Example: \tIdentifierToString.exe --id 0x12345678 --id 87654321\n\n"
			"As this option is optional the following will work, too.\n"
			"Example: \tIdentifierToString.exe 12345678 0x12345678\n"
		);
	
	boost::program_options::positional_options_description pd;
	pd.add(optionIdString, -1);

	boost::program_options::variables_map vm;
	boost::program_options::store(
		boost::program_options::command_line_parser(argc, argv).options(desc).positional(pd).run(), vm);
	boost::program_options::notify(vm);    

	if(vm.count(optionIdString))
	{
		GroupKeyToStringContainer container;
		fillGroupKeyToStringContainer(container);

		StringIdContainer stringIds = vm[optionIdString].as<StringIdContainer>();
		DecIdContainer decIds;
		std::transform
			(
				stringIds.begin(),
				stringIds.end(),
				decIds.begin(),
				std::back_inserter(decIds),
				boost::bind
				(
					&strtol,
					boost::bind
					(
						&std::string::c_str,
						_1
					),
					static_cast<char**>(NULL),
					0
				)
			);
		printDecIdContainerAsCoreId(decIds, container);

		return 0;
	}

	if(vm.count(optionHelp))
	{
		std::cout << desc << "\n";
	}
	else
	{
		std::cout << desc << "\n";
	}

	return 0;
}
