#include <iostream>
#include <Windows.h>
#include <string>
#include <map>
#include <limits>
#include "ConsoleHelper.h"


class Programmer {
private:
    const std::map< std::string, std::string > convert_list{
      {"10", "decimal"},
      {"2", "binary"},
      {"16", "hex"},
      {"8", "octa"}
    };
    const std::map< std::string, std::string > bitwise_list{
      {"1", "& - AND"},
      {"2", "| - OR"},
      {"3", "^ - XOR"},
      {"4", "~ - NOT"},
      {"5", "<< - Left Shift"},
      {"6", ">> - Right Shift"}
    };
public:
    std::map< std::string, std::string > getConvertList() {
        return convert_list;
    }
    std::map< std::string, std::string > getBitwiseList() {
        return bitwise_list;
    }
    std::string convertation(int i, int nstart, int nfinish)
    {
        std::string letters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        if (i < nfinish)
            return std::string(1, letters[i]);
        else
            return convertation(i / nfinish, nstart, nfinish) + letters[i % nfinish];
    }
    bool IsOctDigit(std::string str)
    {
        for (auto x : str)
            if (x < '0' || x>'7')
                return false;
        return true;
    }
    bool IsBinaryDigit(std::string str) {
        if (str.empty() || str.length() > 8)
            return false;
        for (auto x : str)
            if (x < '0' || x>'1')
                return false;
        return true;
    }
    /*bool IsNumber(const std::string& s)
    {
        return !s.empty() && s.find_first_not_of("-.0123456789") == std::string::npos;
    }*/
    bool IsHexDigit(std::string const& s)
    {
        return s.compare(0, 2, "0x") == 0
            && s.size() > 2
            && s.find_first_not_of(".0123456789abcdefABCDEF", 2) == std::string::npos;
    }
    bool validate_convert_choice(std::string systemStatus) {
        switch (std::stoi(systemStatus)) {
        case 2:
        case 10:
        case 16:
        case 8:
            return true;
        default:
            return false;
        }
    }
    bool validate_convert_number(std::string systemStatus, std::string number) {
        bool status = false;

        switch (std::stoi(systemStatus)) {
        case 2:
            if (IsBinaryDigit(number))
                status = true;
            break;
        case 10:
            if (ConsoleHelper::IsNumber(number))
                status = true;
            break;
        case 16:
            if (IsHexDigit(number))
                status = true;
            break;
        case 8:
            if (IsOctDigit(number))
                status = true;
            break;
        default:
            status = false;
        }
        return status;
    }
    static auto initConvertation() {
        Programmer programmer;
        ConsoleHelper::printTitle("Перевод системы счисления", 35);
        ConsoleHelper::print_map(programmer.getConvertList());
        std::string sistema_start;
        std::cout << "Из какой системы счисления? Введите числовое значение согласно списку: \n";
        std::cin >> sistema_start;
        if (!programmer.validate_convert_choice(sistema_start)) {
            throw "Некорректный выбор системы счисления";
        }
        std::string number;
        std::cout << "Введите число согласно выбранной вами системы счисления (без префиксов): ";
        std::cin >> number;
        if (!programmer.validate_convert_number(sistema_start, number)) {
            throw "Введенное число не соответсвует выбранной системе счисления";
        }
        ConsoleHelper::print_map(programmer.getConvertList());
        std::string sistema_finish;
        std::cout << "В какую систему счисления? Введите числовое значение согласно списку: \n";
        std::cin >> sistema_finish;
        if (!programmer.validate_convert_choice(sistema_finish)) {
            throw "Некорректный выбор системы счисления";
        }
        int nstart = stoi(sistema_start);
        int nfinish = stoi(sistema_finish);
        int i = stoi(number, nullptr, nstart);
        return programmer.convertation(i, nstart, nfinish);
    }
    bool validate_bitwise_choice(std::string bitwiseStatus) {
        switch (std::stoi(bitwiseStatus)) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            return true;
        default:
            return false;
        }
    }
    auto getBitwiseResult(std::string bitwiseStatus, int a, int b = 0) {
        switch (std::stoi(bitwiseStatus)) {
        case 1:
            return a & b;
        case 2:
            return a | b;
        case 3:
            return a ^ b;
        case 4:
            return ~a;
        case 5:
            return a << b;
        case 6:
            return a >> b;
        }
    }
    static int initBitwise() {
        Programmer programmer;
        ConsoleHelper::printTitle("Побитовые операции", 35);
        std::string num_first;
        std::cout << "Введите первое число: ";
        std::cin >> num_first;
        if (!ConsoleHelper::IsNumber(num_first)) {
            throw "Введенное значение не является числом";
        }
        ConsoleHelper::print_map(programmer.getBitwiseList());
        std::string bitwise_operator;
        std::cout << "Выберите вариант побитовой операции согласно списку (число): \n";
        std::cin >> bitwise_operator;
        if (!programmer.validate_bitwise_choice(bitwise_operator)) {
            throw "Некорректный выбор побитового оператора";
        }
        if (std::stoi(bitwise_operator) != 4) {
            std::string num_second;
            std::cout << "Введите второе число: ";
            std::cin >> num_second;
            if (!ConsoleHelper::IsNumber(num_second)) {
                throw "Введенное значение не является числом";
            }
            return programmer.getBitwiseResult(bitwise_operator, std::stoi(num_first), std::stoi(num_second));
        }
        return programmer.getBitwiseResult(bitwise_operator, std::stoi(num_first));
    }
};