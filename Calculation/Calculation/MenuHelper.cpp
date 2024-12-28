#include "MenuHelper.h"
#include "Standard.cpp"
//#include "Engineering.h"



void MenuHelper::mainMenu()
{
    while (true)
    {
        system("cls");
        ConsoleHelper::printLine("Выберите режим работы: ");
        ConsoleHelper::printLine("1-стандартный: ");
        ConsoleHelper::printLine("2-инженерный: ");
        ConsoleHelper::printLine("3-программист: ");
        ConsoleHelper::printLine("4-строковый: ");
        ConsoleHelper::printLine("0-выход: ");
        int choice{};
        std::cin >> choice;
        switch (choice)
        {
        case 1: {
            ConsoleHelper::printLine("Вы выбрали 1-стандартный: ");
            MenuHelper::calculateStandard();
            system("pause");
        }break;
        case 2: {
            ConsoleHelper::printLine("Вы выбрали 2-инженерный: ");
            MenuHelper::engineeringMenu();
            system("pause");
        }break;
        case 3: {
            ConsoleHelper::printLine("Вы выбрали 3-программист: ");
            system("pause");
        }break;
        case 4: {
            ConsoleHelper::printLine("Вы выбрали 4-строковый: ");
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
    double num{};
    char oper;
    std::cout << "Enter first number: " << std::endl;
    std::cin >> num;
    Standard<double> calc(num);

    while (true) {
        std::cin >> oper;
        if (oper == '=') {
            break;
        }
        std::cin >> num;
        switch (oper)
        {
        case '+':
            calc + num; break;
        case '-':
            calc - num; break;
        case '*':
            calc * num; break;
        case '/':
            calc / num; break;
        default:
            return;
        }
    }

    std::cout << "Result is: " << calc.getValue() << std::endl;
}

void MenuHelper::engineeringMenu()
{
    while (true)
    {
        system("cls");
        ConsoleHelper::printLine("Выберите операцию: ");
        ConsoleHelper::printLine("1- x^y: ");
        ConsoleHelper::printLine("2- корень квадратный из x: ");
        ConsoleHelper::printLine("3- логарифм x по основанию y: ");
        ConsoleHelper::printLine("4- модуль x: ");
        ConsoleHelper::printLine("0-выход: ");
        int choice{};
        std::cin >> choice;
        switch (choice)
        {
        case 1: {
            ConsoleHelper::printLine("Вы выбрали 1- x^y: ");
            double x = ConsoleHelper::inputDouble("Введите x");
            double y = ConsoleHelper::inputDouble("Введите y");
            /*std::cout << Engineering<double>::powerXY(x, y);*/
            system("pause");
        }break;
        case 2: {
            ConsoleHelper::printLine("Вы выбрали 2- корень квадратный из x: ");
            system("pause");
        }break;
        case 3: {
            ConsoleHelper::printLine("Вы выбрали 3- логарифм x по основанию y: ");
            system("pause");
        }break;
        case 4: {
            ConsoleHelper::printLine("Вы выбрали 4- модуль x: ");
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
