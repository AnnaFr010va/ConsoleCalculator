
#pragma once
#include <iostream>
#include <cmath>
	//#include "Constants.h"


	template<class T>
	class Engineering
	{
	public:
		static T powerXY(const T& x, const T& y)
		{
			return pow(x, y);
		}
		static T sqrtX(const T& x)
		{
			if (x < 0)
			{
				return NAN;
			}
			return sqrt(x);
		}
		static T logXY(const T& x, const T& y)
		{
			if (x <= 0 || y <= 0 || y == 1)
			{
				return NAN;
			}
			return log(x) / log(y);
		}
		static T lnX(const T& x)
		{
			if (x <= 0)
			{
				return NAN;
			}
			return log(x);
		}
		static T logDecX(const T& x)
		{
			if (x <= 0)
			{
				return NAN;
			}
			else
			{
				return log10(x);
			}
		}
		static T absX(const T& x)
		{
			return fabs(x);
		}
		static unsigned int factorialX(const unsigned int& x)
		{
			if (x == 0)
			{
				return 1;
			}
			return x * factorialX(x - 1);
		}
	};


