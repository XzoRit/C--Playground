// MeanFilter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <queue>

class MeanFilter
{
  public:
    MeanFilter(int n)
		: m_sum(0)
		, m_samples(n > 0 ? n : 1)
		, m_queue()
	{}

	~MeanFilter()
	{}
    
	float floatingAverage(float value)
	{
		m_queue.push(value);
		m_sum += value;
		if (m_queue.size() > m_samples)
		{
			m_sum -= m_queue.front();
			m_queue.pop();
		}
		return m_sum / m_queue.size();
	}

  private:
    std::queue<float> m_queue;
    int m_samples;
    float m_sum;
};

int _tmain(int argc, _TCHAR* argv[])
{
	MeanFilter f(3);

	std::cout << f.floatingAverage(1.0f) << std::endl;
	std::cout << f.floatingAverage(2.0f) << std::endl;
	std::cout << f.floatingAverage(3.0f) << std::endl;
	std::cout << f.floatingAverage(4.0f) << std::endl;

	return 0;
}

