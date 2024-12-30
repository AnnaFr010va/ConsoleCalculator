#pragma once
#include<iostream>
#include<cmath>
#include<valarray>
#include "Constants.h"

using namespace Constants;

//#define pi 3.14159


template<class T>
class Trigonometry
{
public:
	static T sinX(const T& x) {
		double temp = sin(x);
		if (fabs(temp) < 0.0000001) {
			return 0.0;
		}
		else {
			return temp;
		}
	}
	static T cosX(const T& x) {
		double temp = cos(x);
		if (fabs(temp) < 0.0000001) {
			return 0.0;
		}
		else {
			return temp;
		}
	}
	static T tgX(const T& x)
	{
		if (cosX(x) == 0.0)
		{
			return INFINITY;
		}
		return sinX(x) / cosX(x);
	}
	static T ctgX(const T& x)
	{
		return 1 / tgX(x);
	}
	static T arcsinX(const T& x)
	{
		return asin(x);
	}
	static T arccosX(const T& x)
	{
		return acos(x);
	}
	static T arctgX(const T& x)
	{
		return atan(x);
	}
	static T arcctgX(const T& x)
	{
		return Constants::pi / 2 - atan(x);
	}

	static T convertToRadian(T& x, bool isRadian)
	{
		if (!isRadian)
		{
			x = x * Constants::pi / 180;
		}
		return x;
	}

	static T convertToDegrees(T& x)
	{
		x = x * 180 / Constants::pi;
		return x;
	}
};

