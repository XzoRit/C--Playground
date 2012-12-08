#ifndef MIN_MAX_H
#define MIN_MAX_H

#define COMPILE_TIME_CHECK(expr, msg) \
{ char COMPILE_TIME_ERROR_##msg[(expr) ? 1 : 0]; }

class MinMax
{
public:

	typedef struct
	{
		float Min;
		float Max;
	} InnerType;

	struct Min
	{
		explicit Min(float v)
		: Value(v)
		{
		}

		float Value;
	};
	
	struct Max
	{
		explicit Max(float v)
		: Value(v)
		{
		}

		float Value;
	};

	MinMax()
	: m_min(0.0f)
	, m_max(0.0f)
	{
	}

	MinMax(float min, float max)
	: m_min(min)
	, m_max(max)
	{
	}

	MinMax(const Min& min, const Max& max)
	: m_min(min.Value)
	, m_max(max.Value)
	{
	}

	MinMax(const InnerType& type)
	: m_min(type.Min)
	, m_max(type.Max)
	{
	}

	float getMin() const
	{
		return m_min;
	}

	float getMax() const
	{
		return m_max;
	}

private:
	const float m_min;
	const float m_max;
};

template<int min, int max>
MinMax::InnerType createMinMax()
{
	COMPILE_TIME_CHECK(min < max, MinIsNotSmallerThanMax);
	MinMax::InnerType i = {};
	i.Min = min;
	i.Max = max;

	return i;
}

#endif