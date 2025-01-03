#pragma once
#include <iostream>
#include <string>
#include <map>

class ConsoleHelper
{
public:
	static void printLine(const std::string&);
	static double inputDouble(const std::string&);
	static int inputInt(const std::string&);
	static double inputBool(const std::string&);
	static std::string inputSingleString();
	static std::tuple<std::string, std::string> inputTwoStrings();
	static std::tuple<std::string, char, char> inputStringAndChars();
	static std::tuple<std::string, std::string, std::string> inputThreeStrings();
	static void setColor(int textColor);
	static void resetColor();
	static std::string getColorString(std::string str, std::string color);
	static void printTitle(std::string str, int color);
	static bool IsNumber(const std::string& s);
	static std::tuple<std::string, std::string> inputTwoNumbers();

	template<typename T>
	static void printResult(T message) {
		ConsoleHelper::setColor(32);
		std::cout << "Результат: " << message << std::endl;
		ConsoleHelper::resetColor();
	}

	template<typename K, typename V>
	static void print_map(std::map<K, V> c_map) {
		std::cout << "______________________" << std::endl;
		for (auto const& x : c_map)
		{
			std::cout << x.first
				<< ':'
				<< x.second
				<< std::endl;
		}
	}
};

