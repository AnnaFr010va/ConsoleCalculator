#pragma once
#include <iostream>
#include <string>
class ConsoleHelper
{
public:
	static void printLine(const std::string&);
	static double inputDouble(const std::string&);
	static int inputInt(const std::string&);
	static double inputBool(const std::string&);
	static void setColor(int textColor)
	{
		std::cout << "\033[" << textColor << "m";
	}

	static void resetColor() { std::cout << "\033[0m"; }


};

