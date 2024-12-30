#pragma once
#include <iostream>
#include <sstream>
#include <string>


class String
{
public:
	static bool isCharInString(const std::string& message, char symbol)
	{
		return message.find(symbol) != std::string::npos;
	}
	static int countOfElem(std::string message)
	{
		std::stringstream strm;
		strm << message;
		int counter = 0;
		std::string temp;
		while (!strm.eof()) {
			strm >> temp;
			counter += 1;
		}
		return counter;
	}
	static int countOfVowels(std::string message)
	{
		std::string vowels = "aeuioóåûàîýÿèþ¸";
		int counter = 0;
		for (char c : message)
		{
			if (isCharInString(vowels, tolower(c)))
			{
				counter++;
			}
		}
		return counter;
	}
	static int countOfConsonants(std::string message)
	{

	}
};


//string convenrtation(int i, int nstart, int nfinish)
//{
//	string letters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//	if (i < nfinish)
//		return string(1, letters[i]);
//	else
//		return convenrtation(i / nfinish, nstart, nfinish) + letters[i % nfinish];
//}