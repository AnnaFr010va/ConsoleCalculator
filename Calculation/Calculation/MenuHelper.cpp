#include "MenuHelper.h"
#include "Standard.cpp"
#include "Engineering.h"
#include "Trigonometry.h"
#include "String.h"
#include "Programmer.h"
#include <string>
#include <limits>

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
            Programmer programmer;
            try {
                programmer.getMenu();
            }
            catch (...) {
                std::cout << "Выход из режима разработчика" << std::endl;
            }
            system("pause");
        }break;
        case 5: {
            ConsoleHelper::printLine("Вы выбрали 5 - строковый: ");
            MenuHelper::stringMenu();
            system("pause");
        }break;
        case 6: {
            ConsoleHelper::printLine("Вы выбрали 6 - работа с большими числами: ");
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


//void MenuHelper::programmerMenu()
//{
//    while (true)
//    {
//        system("cls");
//        ConsoleHelper::printLine("Выберите операцию: ");
//        ConsoleHelper::printLine("1 - битовый сдвиг вправо>>: ");
//        ConsoleHelper::printLine("2 - битовый сдвиг вдево<<: ");
//        ConsoleHelper::printLine("3 - перевод из одной системы счисления в другую: ");
//        /*ConsoleHelper::printLine("4 - натуральный логарифм по основанию x: ");
//        ConsoleHelper::printLine("5 - десятичный логарифм по основанию x: ");
//        ConsoleHelper::printLine("6 - модуль x: ");*/
//        ConsoleHelper::printLine("0 - выход: ");
//        int choice{};
//        std::cin >> choice;
//        switch (choice)
//        {
//        case 1: {
//            ConsoleHelper::printLine("Вы выбрали 1 - x^y: ");
//            double x = ConsoleHelper::inputDouble("Введите x: ");
//            double y = ConsoleHelper::inputDouble("Введите y: ");
//            std::cout << Engineering<double>::powerXY(x, y) << std::endl;
//            system("pause");
//        }break;
//        case 2: {
//            ConsoleHelper::printLine("Вы выбрали 2 - корень квадратный из x: ");
//            double x = ConsoleHelper::inputDouble("Введите x: ");
//            std::cout << Engineering<double>::sqrtX(x) << std::endl;
//            system("pause");
//        }break;
//        case 3: {
//            ConsoleHelper::printLine("Вы выбрали 3 - логарифм x по основанию y: ");
//            double x = ConsoleHelper::inputDouble("Введите x: ");
//            double y = ConsoleHelper::inputDouble("Введите y: ");
//            std::cout << Engineering<double>::logXY(x, y) << std::endl;
//            system("pause");
//        }break;
//        /*case 4: {
//            ConsoleHelper::printLine("Вы выбрали 4 - логарифм x по основанию y: ");
//            double x = ConsoleHelper::inputDouble("Введите x: ");
//            std::cout << Engineering<double>::lnX(x) << std::endl;
//            system("pause");
//        }break;
//        case 5: {
//            ConsoleHelper::printLine("Вы выбрали 5 - логарифм x по основанию y: ");
//            double x = ConsoleHelper::inputDouble("Введите x: ");
//            std::cout << Engineering<double>::logDecX(x) << std::endl;
//            system("pause");
//        }break;
//        case 6: {
//            ConsoleHelper::printLine("Вы выбрали 6 - модуль x: ");
//            double x = ConsoleHelper::inputDouble("Введите x: ");
//            std::cout << Engineering<double>::absX(x) << std::endl;
//            system("pause");
//        }break;*/
//        case 0: {
//            return;
//        }break;
//        default: {
//            ConsoleHelper::printLine("Ошибка: ");
//            system("pause");
//        };
//
//        }
//    }
//
//
//}

void MenuHelper::largeNumbersMenu()
{
    while (true)
    {
        system("cls");
        ConsoleHelper::printLine("Выберите операцию: ");
        ConsoleHelper::printLine("1 - сложение: ");
        ConsoleHelper::printLine("2 - вычитание: ");
        ConsoleHelper::printLine("3 - умножение: ");
        ConsoleHelper::printLine("4 - целочисленное деление: ");
        ConsoleHelper::printLine("0 - выход: ");
        int choice{};
        std::cin >> choice;
        switch (choice)
        {
        case 1: {
            ConsoleHelper::printLine("Вы выбрали 1 - сложение: ");

            system("pause");
        }break;
        case 2: {
            ConsoleHelper::printLine("Вы выбрали 2 - вычитание: ");

            system("pause");
        }break;
        case 3: {
            ConsoleHelper::printLine("Вы выбрали 3 - умножение: ");

            system("pause");
        }break;
        case 4: {
            ConsoleHelper::printLine("Вы выбрали 4 - целочисленное деление: ");

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

void MenuHelper::stringMenu()
{
    while (true)
    {
        system("cls");
        ConsoleHelper::printLine("Выберите операцию: ");
        ConsoleHelper::printLine("1 - подсчёт слов: ");
        ConsoleHelper::printLine("2 - подсчёт гласных: ");
        ConsoleHelper::printLine("3 - подсчёт согласных: ");
        ConsoleHelper::printLine("4 - конкатенация: ");
        ConsoleHelper::printLine("5 - замена символа: ");
        ConsoleHelper::printLine("0 - выход: ");
        int choice{};
        std::cin >> choice;
        switch (choice)
        {
        case 1: {
            ConsoleHelper::printLine("Вы выбрали 1 - подсчёт слов: ");
            std::string message;
            std::cin.clear();
            /*std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');*/
            std::cout << "Введите строку: " << std::endl;
            std::getline(std::cin, message);
            std::cout << String::countOfElem(message) << std::endl;
            system("pause");
        }break;
        case 2: {
            ConsoleHelper::printLine("Вы выбрали 2 - подсчёт гласных: ");
            std::string message;
            std::cin.clear();
            /*std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');*/
            std::cout << "Введите строку: " << std::endl;
            std::getline(std::cin, message);
            std::cout << String::countOfVowels(message) << std::endl;
            system("pause");
        }break;
        case 3: {
            ConsoleHelper::printLine("Вы выбрали 3 - подсчёт согласных: ");

            system("pause");
        }break;
        case 4: {
            ConsoleHelper::printLine("Вы выбрали 4 - конкатенация: ");

            system("pause");
        }break;
        case 5: {
            ConsoleHelper::printLine("Вы выбрали 5 - замена символа: ");

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