#ifndef CompileTimeChecker_h
#define CompileTimeChecker_h

template<bool> struct CompileTimeChecker
{
	CompileTimeChecker(...);
};

template<> struct CompileTimeChecker<true>
{};

#endif