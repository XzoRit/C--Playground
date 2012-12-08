// genric_callback.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

template <int i>
struct Int2Type
{
	enum { i } Value;
};

struct TimerEvent
{
public:
	TimerEvent()
		: m_type(MinTimerEvent)
	{}

	virtual ~TimerEvent()
	{};

	typedef enum EventType_e
	{
		MinTimerEvent = 0,
		MyMinTimerEvent1,
		MyMinTimerEvent2
	} EventType;

	enum { Type = MinTimerEvent };

	EventType getType() const
	{
		return m_type;
	}

protected:
	TimerEvent(EventType e)
		: m_type(e)
	{}

	EventType m_type;
};

struct MyTimerEvent1 : public TimerEvent
{
public:
	MyTimerEvent1()
		: TimerEvent(TimerEvent::MyMinTimerEvent1)
	{}

	virtual ~MyTimerEvent1()
	{};

	enum { Type = TimerEvent::MyMinTimerEvent1 };
	int m_data;
};

struct MyTimerEvent2 : public TimerEvent
{
public:
	MyTimerEvent2()
		: TimerEvent(TimerEvent::MyMinTimerEvent2)
	{}

	virtual ~MyTimerEvent2()
	{};

	enum { Type = TimerEvent::MyMinTimerEvent2 };
	char m_char;
};

template <typename TARGET>
const TARGET* timer_event_cast(const TimerEvent& e)
{
	if(TARGET::Type == e.getType())
	{
		return static_cast<const TARGET*>(&e);
	}
	else
	{
		return NULL;
	}
}

class TimerCallbackBase
{
public:

	virtual ~TimerCallbackBase() {};

	virtual void operator()(const TimerEvent&) const {};
};

template<typename T>
class TimerCallback : public TimerCallbackBase
{
public:
  typedef void (T::*F)(const TimerEvent&);

  TimerCallback( T& t, F f )
	  : m_t(t), m_f(f)
  {}

  virtual ~TimerCallback() {};

  virtual void operator()(const TimerEvent& e) const
  {
	  (m_t.*m_f)(e);
  }

private:
  T& m_t;
  F  m_f;
};

class Timer
{
public:
	Timer(TimerCallbackBase& callback)
		: m_callback(callback)
	{}

	void timeout(const TimerEvent& e)
	{
		m_callback(e);
	}

private:
	TimerCallbackBase& m_callback;
};

class App1
{
public:
	App1()
		: m_timerCallback(*this, &App1::handleTimeout1)
		, m_timer(m_timerCallback)
	{}

	void timeout(const TimerEvent& e)
	{
		m_timer.timeout(e);
	}

private:

	void handleTimeout1(const TimerEvent& e)
	{
		std::cout << "App1::handleTimeout1: " << e.getType() << std::endl;
		if(const MyTimerEvent1* mte = timer_event_cast<MyTimerEvent1>(e))
		{
			std::cout << "App1::handleTimeout1: " << mte->m_data << std::endl;
		}

		else if(const MyTimerEvent2* mte = timer_event_cast<MyTimerEvent2>(e))
		{
			std::cout << "App1::handleTimeout1: " << mte->m_char << std::endl;
		}
	}

	TimerCallback<App1> m_timerCallback;
	Timer m_timer;
};

int _tmain(int argc, _TCHAR* argv[])
{
	App1 a1;
	MyTimerEvent1 e;
	MyTimerEvent2 a;
	
	e.m_data = 17;
	a1.timeout(e);

	a.m_char = 'a';
	a1.timeout(a);

	return 0;
}

