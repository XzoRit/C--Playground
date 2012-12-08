// structs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

typedef struct Widget_s
{
	Widget_s()
	{}

	Widget_s(int, float, bool, void*)
	{}

	int i;
	float f;
	bool b;
	void* pv;
} Widget_t;

class Widget
{
public:
	~Widget() {}
	Widget() : m_widget() {}
	Widget_t m_widget;
private:
	Widget(const Widget&);
	Widget& operator=(const Widget&);
};
	

void printWidget(Widget_t w)
{
	std::cout << "int " << w.i << std::endl;
	std::cout << "float " << w.f << std::endl;
	std::cout << "bool " << w.b << std::endl;
	std::cout << "void* "<< w.pv << std::endl;
	std::cout << std::endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	std::cout << "===== Constructing structs =====\n\n";
	
	std::cout << "The struct-definition:\n";
	std::cout << "typedef struct Widget_s\n";
	std::cout << "{\n";
	std::cout << "\tint i;\n";
	std::cout << "\tfloat f;\n";
	std::cout << "\tbool b;\n";
	std::cout << "\tvoid* pv;\n";
	std::cout << "} Widget_t;\n\n";

	std::cout << "Default ctor (not overrideable by user)\n";
	std::cout << "Widget_t w1;\n";
	Widget_t w1;
	printWidget(w1);
	std::cout << "\tREMARK:\n";
	std::cout << "\tIn VS2008 referencing a default constructed struct throws an exception in debug-mode\n";
	std::cout << "\n";

	// dieser Block kompitiert nur wenn die Kosnstruktoren aus dem struct entfernt werden
	/*std::cout << "Braket Initializer\n";
	std::cout << "Widget_t w2 = {};\n";
	Widget_t w2 = {};
	printWidget(w2);
	std::cout << "\n";

	std::cout << "Braket Initializer with one value\n";
	std::cout << "Widget_t w3 = {1};\n";
	Widget_t w3 = {1};
	printWidget(w3);
	std::cout << "\n";

	std::cout << "Braket Initializer with two value\n";
	std::cout << "Widget_t w4 = {1,2.0f};\n";
	Widget_t w4 = {1,2.0f};
	printWidget(w4);
	std::cout << "\n";*/

	std::cout << "NOW: What about a default constructed struct as member of a default constructed class???\n";
	std::cout << "Here is the class definition\n";
	std::cout << "class Widget\n";
	std::cout << "{\n";
	std::cout << "public:\n";
	std::cout << "\t~Widget() {}\n";
	std::cout << "\tWidget() : m_widget() {}\n";
	std::cout << "\tWidget_t m_widget;\n";
	std::cout << "private:\n";
	std::cout << "\tWidget(const Widget&);\n";
	std::cout << "\tWidget& operator=(const Widget&);\n";
	std::cout << "};\n";
	std::cout << "Widget w5;\n";
	Widget w5;
	printWidget(w5.m_widget);
	std::cout << "\n";

	std::cout << "And here a little bonus question:\n";
	std::cout << "Why is it impossible to print the conten of w6?\n";
	std::cout << "Widget_t w6();\n";
	Widget_t w6();

	return 0;
}

