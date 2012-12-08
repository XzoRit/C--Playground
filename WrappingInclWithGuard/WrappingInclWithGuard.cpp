// WrappingInclWithGuard.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iterator>
#include <string>
#include <vector>
#include <ostream>

//BOOST_FILESYSTEM_VERSION=3
//BOOST_FILESYSTEM_NO_DEPRECATED
#include <boost/filesystem.hpp>

#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/qi_action.hpp>
#include <boost/spirit/include/phoenix.hpp>
#include <boost/spirit/include/support_multi_pass.hpp>

#include <boost/wave/cpplexer/cpp_lex_iterator.hpp>
#include <boost/wave/cpplexer/cpp_lex_token.hpp>
#include <boost/wave/cpp_context.hpp>

using namespace boost;

void printChar(const char& t)
{
	std::cout << t << std::endl;
}

void printString(const std::string& t)
{
	std::cout << t << std::endl;
}

void printCharVector(std::vector<char>& t)
{
	for(std::vector<char>::iterator i(t.begin());
		i != t.end();
		++i)
	{
		std::cout << *i;
	}
	std::cout << std::endl;
}

int main(int argc, char* argv[])
{
	filesystem::path cur("d:/projects/a500/Axxx_WrappInclsWithGuard");
	std::cout << cur << std::endl;

	for(filesystem::recursive_directory_iterator f = filesystem::recursive_directory_iterator(cur);
		f != filesystem::recursive_directory_iterator();
		++f)
	{
		if(!filesystem::is_directory(*f) &&
			filesystem::is_regular_file(*f) &&
			f->path().extension() == ".h")
		{
			std::cout << *f << std::endl;

			std::ifstream in(f->path().string().c_str());
			if (!in.is_open())
			{
				std::cout << "Could not open input file: " << *f << std::endl;
				return -1;
			}

			typedef std::istreambuf_iterator<char> base_iterator_type;
			spirit::multi_pass<base_iterator_type> begin = 
				spirit::make_default_multi_pass(base_iterator_type(in));
			spirit::multi_pass<base_iterator_type> end =
				spirit::make_default_multi_pass(base_iterator_type());

			bool result = spirit::qi::parse(
				begin,
				end,
				(+(!spirit::qi::char_('#'))) >>
					spirit::qi::string("#define")[&printString] >>
					(+(spirit::qi::alpha|spirit::qi::alnum|spirit::qi::char_('_')))[&printCharVector]);
		}

	}

	filesystem::path inPath("D:/Projects/A500/Axxx_WrappInclsWithGuard/Axxx_EcUnitCore/AlarmAutosetTab.hpp");
	std::ifstream instream(inPath.string().c_str());
	std::string input(std::istreambuf_iterator<char>(instream.rdbuf()),
    std::istreambuf_iterator<char>());

    typedef boost::wave::cpplexer::lex_iterator<
            boost::wave::cpplexer::lex_token<> >
        lex_iterator_type;
    typedef boost::wave::context<
            std::string::iterator, lex_iterator_type>
        context_type;

    context_type ctx(input.begin(), input.end(), "AlarmAutosetTag.hpp");

    ctx.add_include_path("D:/Projects/A500/Axxx_WrappInclsWithGuard/Axxx_EcUnitCore");
    //ctx.add_macro_definition("...");

    context_type::iterator_type first = ctx.begin();
    context_type::iterator_type last = ctx.end();

    //while(first != last)
	//{
        std::cout << first->get_value();
        ++first;
    //}

	return 0;
}
