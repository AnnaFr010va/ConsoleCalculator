#include "ConsoleHelper.h"


void ConsoleHelper::printLine(const std::string& message)
{
    std::cout << message << std::endl;
    std::cout << std::endl;
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