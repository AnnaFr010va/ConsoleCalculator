#include "ConsoleHelper.h"
#include <tuple>


void ConsoleHelper::printLine(const std::string& message)
{
    std::cout << message << std::endl;
    std::cout << std::endl;
}

std::string ConsoleHelper::inputSingleString()
{
    std::string message;
    std::cin.clear();
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    std::cout << "Введите строку: " << std::endl;
    std::getline(std::cin, message);
    return message;
}
std::tuple<std::string, std::string> ConsoleHelper::inputTwoStrings()
{
    std::string message1;
    std::cin.clear();
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    std::cout << "Введите исходную строку: " << std::endl;
    std::getline(std::cin, message1);
    std::string message2;
    std::cout << "Введите строку2: " << std::endl;
    std::getline(std::cin, message2);
    return std::make_tuple(message1, message2);
}
std::tuple<std::string, char, char> ConsoleHelper::inputStringAndChars()
{
    std::string text;
    std::cin.clear();
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    std::cout << "Введите строку: " << std::endl;
    std::getline(std::cin, text);
    char target;
    std::cout << "Введите удаляемый символ: " << std::endl;
    std::cin >> target;
    char replacement;
    std::cout << "Введите замещающий символ: " << std::endl;
    std::cin >> replacement;
    return std::make_tuple(text, target, replacement);
}
std::tuple<std::string, std::string, std::string> ConsoleHelper::inputThreeStrings()
{
    std::string text;
    std::cin.clear();
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    std::cout << "Введите исходную строку или текст: " << std::endl;
    std::getline(std::cin, text);
    std::string target;
    std::cout << "Введите строку 1: " << std::endl;
    std::getline(std::cin, target);
    std::string replacement;
    std::cout << "Введите строку 2: " << std::endl;
    std::getline(std::cin, replacement);
    return std::make_tuple(text, target, replacement);
}

double ConsoleHelper::inputDouble(const std::string& message)
{
    double number;
    bool validInput = false;

    do {
        std::cout << message;
        if (std::cin >> number) {
            validInput = true;
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Некорректный ввод. Пожалуйста, введите вещественное число.\n";
        }
    } while (!validInput);

    return number;
}

int ConsoleHelper::inputInt(const std::string& message)
{

    /*std::string number;
    bool validInput = false;*/


    /*do {
        std::cout << message;
        if (std::cin >> number) {
            validInput = true;
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Некорректный ввод. Пожалуйста, введите целое число.\n";
        }
    } while (!validInput);*/
    int number;
    std::cin >> number;

    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Введите значение повторно:";
        std::cin >> number;
    }


    return number;
}

double ConsoleHelper::inputBool(const std::string& message)
{
    bool number;
    bool validInput = false;

    do {
        std::cout << message;
        if (std::cin >> number) {
            validInput = true;
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Некорректный ввод. Пожалуйста, введите вещественное число.\n";
        }
    } while (!validInput);

    return number;
}

void ConsoleHelper::setColor(int textColor)
{
    std::cout << "\033[" << textColor << "m";
}

void ConsoleHelper::resetColor() { std::cout << "\033[0m"; }

std::string ConsoleHelper::getColorString(std::string str, std::string color) {
    std::string f{ "\x1b[" };
    std::string m{ "m" };
    std::string l{ "\x1b[0m" };
    std::string res = { f + color + m + str + l };
    return res;
}

void ConsoleHelper::printTitle(std::string str, int color) {
    ConsoleHelper::setColor(color);
    std::cout << str << std::endl;
    ConsoleHelper::resetColor();
}
bool ConsoleHelper::IsNumber(const std::string& s)
{
    return !s.empty() && s.find_first_not_of("-.0123456789") == std::string::npos;
}
std::tuple<std::string, std::string> ConsoleHelper::inputTwoNumbers()
{
    std::string num1;
    std::cin.clear();
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    std::cout << "Введите первое число: " << std::endl;
    std::getline(std::cin, num1);
    if (!ConsoleHelper::IsNumber(num1)) {
        throw "Введенное значение не является числом";
    }
    std::string num2;
    std::cout << "Введите второе число: " << std::endl;
    std::getline(std::cin, num2);
    return std::make_tuple(num1, num2);
}