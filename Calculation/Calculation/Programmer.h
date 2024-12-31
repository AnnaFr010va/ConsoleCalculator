#include <iostream>
#include <Windows.h>
#include <string>
#include <map>
#include <limits>
#include "ConsoleHelper.h"




class Programmer {
public:
    std::string convertationResult;
    int bitwiseResult;
    int task;
    Programmer() {
        this->convertationResult = "";
        this->bitwiseResult = 0;
        this->task = 0;
    }
    const std::map< std::string, std::string > convert_choice{
        {"10", "decimal"},
        {"2", "binary"},
        {"16", "hex"},
        {"8", "octa"}
    };
    const std::map< std::string, std::string > bitwise_choice{
       {"1", "& - AND"},
       {"2", "| - OR"},
       {"3", "^ - XOR"},
       {"4", "~ - NOT"},
       {"5", "<< - Left Shift"},
       {"6", ">> - Right Shift"}
    };
    const std::map< std::string, std::string > menu_choice{
       {"1", "Перевод систем счисления"},
       {"2", "Бинарные операции"},
       {"3", "Выход из меню"},
    };
    template<typename K, typename V>
    void print_choice_list(std::map<K, V> c_map) {
        for (auto const& x : c_map)
        {
            std::cout << x.first
                << ':'
                << x.second
                << std::endl;
        }
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
    bool IsNumber(const std::string& s)
    {
        return !s.empty() && s.find_first_not_of("-.0123456789") == std::string::npos;
    }
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
            this->task = 3;
            break;
        case 10:
            if (IsNumber(number))
                status = true;
            this->task = 3;
            break;
        case 16:
            if (IsHexDigit(number))
                status = true;
            this->task = 3;
            break;
        case 8:
            if (IsOctDigit(number))
                status = true;
            this->task = 3;
            break;
        default:
            this->task = 3;
            status = false;
        }
        return status;
    }
    auto initConvertation() {
        showTitle("Перевод системы счисления", 32);
        this->print_choice_list(this->convert_choice);

        try {
            std::string sistema_start;
            std::cout << "Из какой системы счисления? Введите числовое значение согласно списку: \n";
            std::cin >> sistema_start;
            if (!this->validate_convert_choice(sistema_start)) {
                this->task = 3;
                throw "Некорректный выбор системы счисления";
            }
            std::string number;
            std::cout << "Введите число согласно выбранной вами системы счисления (без префиксов): ";
            std::cin >> number;
            if (!this->validate_convert_number(sistema_start, number)) {
                this->task = 3;
                throw "Введенное число не соответсвует выбранной системе счисления";
            }
            this->print_choice_list(this->convert_choice);
            std::string sistema_finish;
            std::cout << "В какую систему счисления? Введите числовое значение согласно списку: \n";
            std::cin >> sistema_finish;
            if (!this->validate_convert_choice(sistema_finish)) {
                this->task = 3;
                throw "Некорректный выбор системы счисления";
            }
            int nstart = stoi(sistema_start);
            int nfinish = stoi(sistema_finish);
            int i = stoi(number, nullptr, nstart);
            return convertation(i, nstart, nfinish);
        }
        catch (const char* error_message) {
            std::cout << error_message << std::endl;
        }
    }

    bool validate_bitwise_choice(std::string bitwiseStatus) {
        if (!this->IsNumber(bitwiseStatus))
            return false;
        switch (std::stoi(bitwiseStatus)) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            return true;
        default:
            this->task = 3;
            return false;
        }
    }
    bool validate_menu_choice(std::string menuStatus) {
        if (!this->IsNumber(menuStatus))
            return false;

        switch (std::stoi(menuStatus)) {
        case 1:
            try {
                this->convertationResult = this->initConvertation();
                ConsoleHelper::setColor(36);
                std::cout << "Результат операции перевода систем счисления: " << convertationResult << std::endl;
                ConsoleHelper::resetColor();
                this->task = 1;
                break;
            }
            catch (const char* error_message) {
                std::cout << error_message << std::endl;
            }
        case 2:
            try {
                int bitwiseResult = this->initBitwise();
                ConsoleHelper::setColor(36);
                std::cout << "Результат побитовой операции: " << bitwiseResult << std::endl;
                ConsoleHelper::resetColor();
                this->task = 2;
                break;
            }
            catch (const char* error_message) {
                std::cout << error_message << std::endl;
            }
        case 3:
            this->task = 3;
            return true;
        default:
            return false;
        }
    }
    void showTitle(std::string str, int color) {
        ConsoleHelper::setColor(color);
        std::cout << str << std::endl;
        ConsoleHelper::resetColor();
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
    int initBitwise() {
        showTitle("Побитовые операции", 32);
        std::string num_first;
        std::cout << "Введите первое число: ";
        std::cin >> num_first;
        if (!this->IsNumber(num_first)) {
            throw "Введенное значение не является числом";
        }
        this->print_choice_list(this->bitwise_choice);
        std::string bitwise_operator;
        std::cout << "Введите число согласно выбранной вами побитовой операции согласно списку: \n";
        std::cin >> bitwise_operator;
        if (!this->validate_bitwise_choice(bitwise_operator)) {
            throw "Некорректный выбор побитового оператора";
        }

        if (std::stoi(bitwise_operator) != 4) {
            std::string num_second;
            std::cout << "Введите второе число: ";
            std::cin >> num_second;
            if (!this->IsNumber(num_second)) {
                throw "Введенное значение не является числом";
            }
            return getBitwiseResult(bitwise_operator, std::stoi(num_first), std::stoi(num_second));
        }
        return getBitwiseResult(bitwise_operator, std::stoi(num_first));
    }
    void getMenu() {
        this->showTitle("Режим программирования", 31);
        while (true) {
            this->print_choice_list(this->menu_choice);
            std::string menu_choice;
            std::cout << "Введите число согласно выбранному вами пункта меню: \n";
            std::cin >> menu_choice;
            if (!this->validate_menu_choice(menu_choice)) {
                throw "Некорректный выбор операции";
            }
            if (this->task == 3) {
                return;
            }
        }

    }
};