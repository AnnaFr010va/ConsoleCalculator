#include "MenuHelper.h"
#include "Standard.cpp"
//#include "Engineering.h"



void MenuHelper::mainMenu()
{
    while (true)
    {
        system("cls");
        ConsoleHelper::printLine("�������� ����� ������: ");
        ConsoleHelper::printLine("1-�����������: ");
        ConsoleHelper::printLine("2-����������: ");
        ConsoleHelper::printLine("3-�����������: ");
        ConsoleHelper::printLine("4-���������: ");
        ConsoleHelper::printLine("0-�����: ");
        int choice{};
        std::cin >> choice;
        switch (choice)
        {
        case 1: {
            ConsoleHelper::printLine("�� ������� 1-�����������: ");
            MenuHelper::calculateStandard();
            system("pause");
        }break;
        case 2: {
            ConsoleHelper::printLine("�� ������� 2-����������: ");
            MenuHelper::engineeringMenu();
            system("pause");
        }break;
        case 3: {
            ConsoleHelper::printLine("�� ������� 3-�����������: ");
            system("pause");
        }break;
        case 4: {
            ConsoleHelper::printLine("�� ������� 4-���������: ");
            system("pause");
        }break;
        case 0: {
            return;
        }break;
        default: {
            ConsoleHelper::printLine("������: ");
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
        ConsoleHelper::printLine("�������� ��������: ");
        ConsoleHelper::printLine("1- x^y: ");
        ConsoleHelper::printLine("2- ������ ���������� �� x: ");
        ConsoleHelper::printLine("3- �������� x �� ��������� y: ");
        ConsoleHelper::printLine("4- ������ x: ");
        ConsoleHelper::printLine("0-�����: ");
        int choice{};
        std::cin >> choice;
        switch (choice)
        {
        case 1: {
            ConsoleHelper::printLine("�� ������� 1- x^y: ");
            double x = ConsoleHelper::inputDouble("������� x");
            double y = ConsoleHelper::inputDouble("������� y");
            /*std::cout << Engineering<double>::powerXY(x, y);*/
            system("pause");
        }break;
        case 2: {
            ConsoleHelper::printLine("�� ������� 2- ������ ���������� �� x: ");
            system("pause");
        }break;
        case 3: {
            ConsoleHelper::printLine("�� ������� 3- �������� x �� ��������� y: ");
            system("pause");
        }break;
        case 4: {
            ConsoleHelper::printLine("�� ������� 4- ������ x: ");
            system("pause");
        }break;
        case 0: {
            return;
        }break;
        default: {
            ConsoleHelper::printLine("������: ");
            system("pause");
        };

        }
    }


}
