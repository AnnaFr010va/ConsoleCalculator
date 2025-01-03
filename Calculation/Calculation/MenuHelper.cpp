#include "MenuHelper.h"
#include "Standard.cpp"
#include "Engineering.h"
#include "Trigonometry.h"
#include "StringMode.h"
#include "Programmer.h"
#include "ConsoleHelper.h"
#include "LargeNumbers.h"
#include <string>
#include <limits>
#include <tuple>
using namespace Constants;

double getInputValue()
{
    while (true)
    {
        std::cout << "Введите число: ";
        double a;
        std::cin >> a;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Неверный формат ввода.  Попробуйте ещё.\n";
        }
        else
        {
            std::cin.ignore(32767, '\n');
            std::cout << a << "\n";
            return a;
        }
    }
}
char getOperator()
{
    while (true)
    {
        std::cout << "Введите арифметический оператор: +, -, *, / or =: ";
        char sm;
        std::cin >> sm;
        std::cin.ignore(32767, '\n');
        if (sm == '+' || sm == '-' || sm == '*' || sm == '/' || sm == '=') {
            std::cout << sm << "\n";
            return sm;
        }
        else
            std::cout << "Неверный формат ввода.  Попробуйте ещё.\n";
    }
}

void MenuHelper::mainMenu()
{
    while (true)
    {
        system("cls");
        ConsoleHelper::printLine("Выберите режим работы: ");
        ConsoleHelper::printLine("1 - стандартный: ");
        ConsoleHelper::printLine("2 - инженерный: ");
        ConsoleHelper::printLine("3 - тригонометрический: ");
        ConsoleHelper::printLine("4 - программист: ");
        ConsoleHelper::printLine("5 - строковый: ");
        ConsoleHelper::printLine("6 - работа с большими числами: ");
        ConsoleHelper::printLine("0 - выход: ");
        int choice{};
        std::cin >> choice;
        switch (choice)
        {
        case 1: {
            ConsoleHelper::printLine("Вы выбрали 1 - стандартный: ");
            MenuHelper::calculateStandard();
            system("pause");
        }break;
        case 2: {
            ConsoleHelper::printLine("Вы выбрали 2 - инженерный: ");
            MenuHelper::engineeringMenu();
            system("pause");
        }break;
        case 3: {
            ConsoleHelper::printLine("Вы выбрали 3 - тригонометрический: ");
            MenuHelper::trigonometryMenu();
            system("pause");
        }break;
        case 4: {
            ConsoleHelper::printLine("Вы выбрали 4 - программист: ");
            MenuHelper::programmerMenu();
            system("pause");
        }break;
        case 5: {
            ConsoleHelper::printLine("Вы выбрали 5 - строковый: ");
            MenuHelper::stringMenu();
            system("pause");
        }break;
        case 6: {
            ConsoleHelper::printLine("Вы выбрали 6 - работа с большими числами: ");
            MenuHelper::largeNumbersMenu();
            system("pause");
        }break;
        case 0: {
            return;
        }break;
        default: {
            ConsoleHelper::printLine("Ошибка: ");
            system("pause");
        };

        }

    }
}
void MenuHelper::calculateStandard() {
    double first{};
    char oper;
    double second{};
    std::cout << "Введите выражение, которое желаете посчитать: " << std::endl;
    first = getInputValue();
    Standard<double> calc(first);

    while (true) {
        oper = getOperator();
        if (oper == '=') {
            break;
        }
        second = getInputValue();
        switch (oper)
        {
        case '+':
            std::cout << "Результат: " << (calc + second).getValue() << std::endl;
            break;
        case '-':
            std::cout << "Результат: " << (calc - second).getValue() << std::endl;;
            break;
        case '*':
            std::cout << "Результат: " << (calc * second).getValue() << std::endl;;
            break;
        case '/':
            try
            {
                std::cout << "Результат: " << (calc / second).getValue() << std::endl;;
                break;
            }
            catch (const char* error_message)
            {
                std::cout << error_message << std::endl;
            }
        default:
            return;
        }
    }

    std::cout << "Итоговый результат: " << calc.getValue() << std::endl;
}

void MenuHelper::engineeringMenu()
{
    while (true)
    {
        system("cls");
        ConsoleHelper::printLine("Выберите операцию: ");
        ConsoleHelper::printLine("1 - x^y: ");
        ConsoleHelper::printLine("2 - корень квадратный из x: ");
        ConsoleHelper::printLine("3 - логарифм x по основанию y: ");
        ConsoleHelper::printLine("4 - натуральный логарифм от x: ");
        ConsoleHelper::printLine("5 - десятичный логарифм от x: ");
        ConsoleHelper::printLine("6 - модуль x: ");
        ConsoleHelper::printLine("7 - факториал x: ");
        ConsoleHelper::printLine("0 - выход: ");
        int choice{};
        std::cin >> choice;
        switch (choice)
        {
        case 1: {
            ConsoleHelper::printLine("Вы выбрали 1 - x^y: ");
            double x = ConsoleHelper::inputDouble("Введите x: ");
            double y = ConsoleHelper::inputDouble("Введите y: ");
            std::cout << Engineering<double>::powerXY(x, y) << std::endl;
            system("pause");
        }break;
        case 2: {
            ConsoleHelper::printLine("Вы выбрали 2 - корень квадратный из x: ");
            double x = ConsoleHelper::inputDouble("Введите x: ");
            if (isnan(Engineering<double>::sqrtX(x)))
            {
                std::cout << "Корень не определён" << std::endl;
            }
            else
            {
                std::cout << Engineering<double>::sqrtX(x) << std::endl;
            }
            system("pause");
        }break;
        case 3: {
            ConsoleHelper::printLine("Вы выбрали 3 - логарифм x по основанию y: ");
            double x = ConsoleHelper::inputDouble("Введите x: ");
            double y = ConsoleHelper::inputDouble("Введите y: ");
            if (isnan(Engineering<double>::logXY(x, y)))
            {
                std::cout << "Логарифм не определён" << std::endl;
            }
            else
            {
                std::cout << Engineering<double>::logXY(x, y) << std::endl;
            }

            system("pause");
        }break;
        case 4: {
            ConsoleHelper::printLine("Вы выбрали 4 - натуральный логарифм от x: ");
            double x = ConsoleHelper::inputDouble("Введите x: ");
            if (isnan(Engineering<double>::lnX(x)))
            {
                std::cout << "Логарифм не определён" << std::endl;
            }
            else
            {
                std::cout << Engineering<double>::lnX(x) << std::endl;
            }
            system("pause");
        }break;
        case 5: {
            ConsoleHelper::printLine("Вы выбрали 5 - десятичный логарифм от x: ");
            double x = ConsoleHelper::inputDouble("Введите x: ");
            if (isnan(Engineering<double>::logDecX(x)))
            {
                std::cout << "Логарифм не определён" << std::endl;
            }
            else
            {
                std::cout << Engineering<double>::logDecX(x) << std::endl;
            }
            system("pause");
        }break;
        case 6: {
            ConsoleHelper::printLine("Вы выбрали 6 - модуль x: ");
            double x = ConsoleHelper::inputDouble("Введите x: ");
            std::cout << Engineering<double>::absX(x) << std::endl;
            system("pause");
        }break;
        case 7: {
            ConsoleHelper::printLine("Вы выбрали 7 - факториал x: ");
            int x = ConsoleHelper::inputInt("Введите x: ");
            std::cout << Engineering<int>::factorialX(x) << std::endl;
            system("pause");
        }break;
        case 0: {
            return;
        }break;
        default: {
            ConsoleHelper::printLine("Ошибка: ");
            system("pause");
        };

        }
    }


}

void MenuHelper::trigonometryMenu()
{
    while (true)
    {
        system("cls");
        ConsoleHelper::printLine("Выберите операцию: ");
        ConsoleHelper::printLine("1 - sin(x): ");
        ConsoleHelper::printLine("2 - cos(x): ");
        ConsoleHelper::printLine("3 - tg(x): ");
        ConsoleHelper::printLine("4 - ctg(x): ");
        ConsoleHelper::printLine("5 - arcsin(x): ");
        ConsoleHelper::printLine("6 - arccos(x): ");
        ConsoleHelper::printLine("7 - arctg(x): ");
        ConsoleHelper::printLine("8 - arcctg(x): ");
        ConsoleHelper::printLine("0 - выход: ");
        int choice{};
        std::cin >> choice;
        switch (choice)
        {
        case 1: {
            ConsoleHelper::printLine("Вы выбрали 1 - sin(x): ");
            double x = ConsoleHelper::inputDouble("Введите x: ");
            bool isRadian = ConsoleHelper::inputBool("0 - градусы; 1 - радианы: ");
            x = Trigonometry<double>::convertToRadian(x, isRadian);
            std::cout << Trigonometry<double>::sinX(x) << std::endl;
            system("pause");
        }break;
        case 2: {
            ConsoleHelper::printLine("Вы выбрали 2 - cos(x): ");
            double x = ConsoleHelper::inputDouble("Введите x: ");
            bool isRadian = ConsoleHelper::inputBool("0 - градусы; 1 - радианы: ");
            x = Trigonometry<double>::convertToRadian(x, isRadian);
            std::cout << Trigonometry<double>::cosX(x) << std::endl;
            system("pause");
        }break;
        case 3: {
            ConsoleHelper::printLine("Вы выбрали 3 - tg(x): ");
            double x = ConsoleHelper::inputDouble("Введите x: ");
            bool isRadian = ConsoleHelper::inputBool("0 - градусы; 1 - радианы: ");
            x = Trigonometry<double>::convertToRadian(x, isRadian);
            if (isinf(Trigonometry<double>::tgX(x)))
            {
                std::cout << "Тангенс не определён" << std::endl;
            }
            else
            {
                std::cout << Trigonometry<double>::tgX(x) << std::endl;
            }
            system("pause");
        }break;
        case 4: {
            ConsoleHelper::printLine("Вы выбрали 4 - ctg(x): ");
            double x = ConsoleHelper::inputDouble("Введите x: ");
            bool isRadian = ConsoleHelper::inputBool("0 - градусы; 1 - радианы: ");
            x = Trigonometry<double>::convertToRadian(x, isRadian);
            std::cout << Trigonometry<double>::ctgX(x) << std::endl;
            system("pause");
        }break;
        case 5: {
            ConsoleHelper::printLine("Вы выбрали 5 - arcsin(x): ");
            double x = ConsoleHelper::inputDouble("Введите x: ");
            std::cout << Trigonometry<double>::arcsinX(x) << std::endl;
            system("pause");
        }break;
        case 6: {
            ConsoleHelper::printLine("Вы выбрали 6 - arccos(x): ");
            double x = ConsoleHelper::inputDouble("Введите x: ");
            std::cout << Trigonometry<double>::arccosX(x) << std::endl;
            system("pause");
        }break;
        case 7: {
            ConsoleHelper::printLine("Вы выбрали 7 - arctg(x): ");
            double x = ConsoleHelper::inputDouble("Введите x: ");
            std::cout << Trigonometry<double>::arctgX(x) << std::endl;
            system("pause");
        }break;
        case 8: {
            ConsoleHelper::printLine("Вы выбрали 8 - arcctg(x): ");
            double x = ConsoleHelper::inputDouble("Введите x: ");
            std::cout << Trigonometry<double>::arcctgX(x) << std::endl;
            system("pause");
        }break;
        case 0: {
            return;
        }break;
        default: {
            ConsoleHelper::printLine("Ошибка: ");
            system("pause");
        };

        }
    }

}


void MenuHelper::programmerMenu()
{
    while (true)
    {
        system("cls");
        ConsoleHelper::printTitle("Режим программирования", 35);
        ConsoleHelper::printLine("Выберите операцию: ");
        ConsoleHelper::printLine("1 - перевод из одной системы счисления в другую: ");
        ConsoleHelper::printLine("2 - бинарные операции: ");
        ConsoleHelper::printLine("0 - выход: ");
        int choice{};
        std::cin >> choice;
        switch (choice)
        {
        case 1: {
            ConsoleHelper::printLine("Вы выбрали 1 - перевод из одной системы счисления в другую: ");
            try {
                ConsoleHelper::printResult(Programmer::initConvertation());
            }
            catch (const char* error_message) {
                std::cout << error_message << std::endl;
            }
            system("pause");
        }break;
        case 2: {
            ConsoleHelper::printLine("Вы выбрали 2 - бинарные операции: ");
            try {
                ConsoleHelper::printResult(Programmer::initBitwise());
            }
            catch (const char* error_message) {
                std::cout << error_message << std::endl;
            }
            system("pause");
        }break;
        case 0: {
            return;
        }break;
        default: {
            ConsoleHelper::printLine("Ошибка: ");
            system("pause");
        };

        }
    }


}

void MenuHelper::largeNumbersMenu()
{
    /*while (true)
    {
        system("cls");
        ConsoleHelper::printTitle("Арифметика больших чисел", 35);
        ConsoleHelper::printLine("Выберите операцию: ");
        ConsoleHelper::printLine("1 - сложение: ");
        ConsoleHelper::printLine("2 - вычитание: ");
        ConsoleHelper::printLine("3 - умножение: ");
        ConsoleHelper::printLine("4 - целочисленное деление: ");
        ConsoleHelper::printLine("0 - выход: ");
        int choice{};
        std::cin >> choice;
       
    }*/


}

void MenuHelper::stringMenu()
{
    while (true)
    {
        system("cls");
        ConsoleHelper::printTitle("Режим строкового калькулятора", 35);
        ConsoleHelper::printLine("Выберите операцию: ");
        ConsoleHelper::printLine("1 - подсчёт слов: ");
        ConsoleHelper::printLine("2 - подсчёт гласных: ");
        ConsoleHelper::printLine("3 - подсчёт согласных: ");
        ConsoleHelper::printLine("4 - конкатенация: ");
        ConsoleHelper::printLine("5 - замена символа: ");
        ConsoleHelper::printLine("6 - замена слова: ");
        ConsoleHelper::printLine("7 - удаление слова в тексте: ");
        ConsoleHelper::printLine("8 - подсчёт длины строки: ");
        ConsoleHelper::printLine("9 - сравнение строк: ");
        ConsoleHelper::printLine("10 - словарь встречаемости всех слов в тексте: ");
        ConsoleHelper::printLine("11 - поиск элемента в тексте: ");
        ConsoleHelper::printLine("0 - выход: ");
        int choice{};
        std::cin >> choice;
        switch (choice)
        {
        case 1: {
            ConsoleHelper::printLine("Вы выбрали 1 - подсчёт слов: ");
            std::string message = ConsoleHelper::inputSingleString();
            ConsoleHelper::printResult(StringMode::countOfElem(message));
            system("pause");
        }break;
        case 2: {
            ConsoleHelper::printLine("Вы выбрали 2 - подсчёт гласных: ");
            std::string message = ConsoleHelper::inputSingleString();
            ConsoleHelper::printResult(StringMode::countOfLetters(message, Constants::vowels));
            system("pause");
        }break;
        case 3: {
            ConsoleHelper::printLine("Вы выбрали 3 - подсчёт согласных: ");
            std::string message = ConsoleHelper::inputSingleString();
            ConsoleHelper::printResult(StringMode::countOfLetters(message, Constants::consonants));
            system("pause");
        }break;
        case 4: {
            ConsoleHelper::printLine("Вы выбрали 4 - конкатенация: ");
            std::tuple<std::string, std::string> message_tuple = ConsoleHelper::inputTwoStrings();
            ConsoleHelper::printResult(StringMode::concatenate(std::get<0>(message_tuple), std::get<1>(message_tuple)));
            system("pause");
        }break;
        case 5: {
            ConsoleHelper::printLine("Вы выбрали 5 - замена символа: ");
            std::tuple<std::string, char, char> message_tuple = ConsoleHelper::inputStringAndChars();
            ConsoleHelper::printResult(StringMode::replaceChar(std::get<0>(message_tuple), std::get<1>(message_tuple), std::get<2>(message_tuple)));
            system("pause");
        }break;
        case 6: {
            ConsoleHelper::printLine("Вы выбрали 6 - замена слова: ");
            std::tuple<std::string, std::string, std::string> message_tuple = ConsoleHelper::inputThreeStrings();
            std::tuple<std::string, int> result_tuple = StringMode::replaceWord(std::get<0>(message_tuple), std::get<1>(message_tuple), std::get<2>(message_tuple));
            std::string text = std::get<0>(result_tuple);
            ConsoleHelper::printResult(text);
            system("pause");
        }break;
        case 7: {
            ConsoleHelper::printLine("Вы выбрали 7 - удаление слова в тексте: ");
            std::tuple<std::string, std::string> message_tuple = ConsoleHelper::inputTwoStrings();
            ConsoleHelper::printResult(StringMode::deleteWord(std::get<0>(message_tuple), std::get<1>(message_tuple)));
            system("pause");
        }break;
        case 8: {
            ConsoleHelper::printLine("Вы выбрали 8 - подсчёт длины строки: ");
            std::string message = ConsoleHelper::inputSingleString();
            ConsoleHelper::printResult(StringMode::getStringLength(message));
            system("pause");
        }break;
        case 9: {
            ConsoleHelper::printLine("Вы выбрали 9 - сравнение строк: ");
            std::tuple<std::string, std::string> message_tuple = ConsoleHelper::inputTwoStrings();
            ConsoleHelper::printResult(StringMode::compareWords(std::get<0>(message_tuple), std::get<1>(message_tuple)));
            system("pause");
        }break;
        case 10: {
            ConsoleHelper::printLine("Вы выбрали 10 - словарь встречаемости всех слов в тексте: ");
            std::string message = ConsoleHelper::inputSingleString();
            std::map< std::string, unsigned > message_map = StringMode::getMapOfElem(message);
            ConsoleHelper::printResult("");
            ConsoleHelper::print_map(message_map);
            system("pause");
        }break;
        case 11: {
            ConsoleHelper::printLine("Вы выбрали 11 - поиск элемента в тексте: ");
            std::tuple<std::string, std::string> message_tuple = ConsoleHelper::inputTwoStrings();
            std::string str1 = std::get<1>(message_tuple);
            std::string str2 = ConsoleHelper::getColorString(str1, "33");
            std::tuple<std::string, int> result_tuple = StringMode::replaceWord(std::get<0>(message_tuple), str1, str2);
            std::cout << std::get<0>(result_tuple) << std::endl;
            int count = std::get<1>(result_tuple);
            ConsoleHelper::printResult(count);
            system("pause");
        }break;
        case 0: {
            return;
        }break;
        default: {
            ConsoleHelper::printLine("Ошибка: ");
            system("pause");
        };

        }
    }
}