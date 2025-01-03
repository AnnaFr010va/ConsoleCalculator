#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <limits>
#include <vector>
#include "ConsoleHelper.h"
#include <tuple>


class StringMode {
public:
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
    static bool isCharInString(const std::string& message, char symbol)
    {
        return message.find(symbol) != std::string::npos;
    }
    static int countOfLetters(std::string message, const std::string& letters)
    {
        int counter = 0;
        for (char c : message)
        {
            if (isCharInString(letters, tolower(c)))
            {
                counter++;
            }
        }
        return counter;
    }
    static std::string replaceChar(std::string& message, char target, char replacement)
    {
        for (char& c : message) {
            if (c == target) {
                c = replacement;
            }
        }
        return message;
    }
    static std::tuple<std::string, int> replaceWord(std::string& text, std::string& old_str, std::string& new_str) {
        int counter = 0;
        if (text.find(old_str) == std::string::npos)
        {
            text = "Элемент не найден";
        }
        else {
            size_t start{ text.find(old_str) };
            counter++;
            while (start != std::string::npos)
            {
                text.replace(start, old_str.length(), new_str);
                start = text.find(old_str, start + new_str.length());
                if (start != std::string::npos) {
                    counter++;
                }
            }
        }
        return std::make_tuple(text, counter);
    }
    static std::string deleteWord(std::string& text, std::string& str) {
        size_t start{ text.find(str) };
        while (start != std::string::npos)
        {
            text.erase(start, str.length());
            start = text.find(str, start + str.length());
        }
        return text;
    }
    static std::string concatenate(const std::string& message_first, const std::string& message_second) {
        std::string res = { message_first + message_second };
        return res;
    }
    static int getStringLength(std::string& str) {
        return str.size();
    }
    static std::string compareWords(const std::string& message_first, const std::string& message_second) {
        bool is_equal{ true };
        if (message_first.length() != message_second.length())
        {
            is_equal = false;
        }
        else
        {
            for (unsigned i{}; i < message_first.length(); i++)
            {
                if (message_first[i] != message_second[i])
                {
                    is_equal = false;
                    break;
                }
            }
        }
        std::string result = is_equal ? "Строки равны" : "Строки не равны";
        return result;
    }
    static  std::map< std::string, unsigned > getMapOfElem(std::string& text) {
        const std::string separators{ " ,;:.\"!?'*\n\t-\\<>" };
        std::map< std::string, unsigned > words;
        size_t start{ text.find_first_not_of(separators) };
        while (start != std::string::npos)
        {
            size_t end = text.find_first_of(separators, start + 1);
            if (end == std::string::npos)
                end = text.length();
            std::string inserted = text.substr(start, end - start);
            if (words.count(inserted) == 0) {
                words[inserted] = 1;
            }
            else {
                words[inserted]++;
            }
            start = text.find_first_not_of(separators, end + 1);
        }

        return words;
    }
};