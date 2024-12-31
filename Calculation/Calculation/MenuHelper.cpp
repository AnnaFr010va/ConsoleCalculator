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
        std::cout << "������� �����: ";
        double a;
        std::cin >> a;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "�������� ������ �����.  ���������� ���.\n";
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
        std::cout << "������� �������������� ��������: +, -, *, / or =: ";
        char sm;
        std::cin >> sm;
        std::cin.ignore(32767, '\n');
        if (sm == '+' || sm == '-' || sm == '*' || sm == '/' || sm == '=') {
            std::cout << sm << "\n";
            return sm;
        }
        else
            std::cout << "�������� ������ �����.  ���������� ���.\n";
    }
}

void MenuHelper::mainMenu()
{
    while (true)
    {
        system("cls");
        ConsoleHelper::printLine("�������� ����� ������: ");
        ConsoleHelper::printLine("1 - �����������: ");
        ConsoleHelper::printLine("2 - ����������: ");
        ConsoleHelper::printLine("3 - ������������������: ");
        ConsoleHelper::printLine("4 - �����������: ");
        ConsoleHelper::printLine("5 - ���������: ");
        ConsoleHelper::printLine("6 - ������ � �������� �������: ");
        ConsoleHelper::printLine("0 - �����: ");
        int choice{};
        std::cin >> choice;
        switch (choice)
        {
        case 1: {
            ConsoleHelper::printLine("�� ������� 1 - �����������: ");
            MenuHelper::calculateStandard();
            system("pause");
        }break;
        case 2: {
            ConsoleHelper::printLine("�� ������� 2 - ����������: ");
            MenuHelper::engineeringMenu();
            system("pause");
        }break;
        case 3: {
            ConsoleHelper::printLine("�� ������� 3 - ������������������: ");
            MenuHelper::trigonometryMenu();
            system("pause");
        }break;
        case 4: {
            ConsoleHelper::printLine("�� ������� 4 - �����������: ");
            Programmer programmer;
            try {
                programmer.getMenu();
            }
            catch (...) {
                std::cout << "����� �� ������ ������������" << std::endl;
            }
            system("pause");
        }break;
        case 5: {
            ConsoleHelper::printLine("�� ������� 5 - ���������: ");
            MenuHelper::stringMenu();
            system("pause");
        }break;
        case 6: {
            ConsoleHelper::printLine("�� ������� 6 - ������ � �������� �������: ");
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
    double first{};
    char oper;
    double second{};
    std::cout << "������� ���������, ������� ������� ���������: " << std::endl;
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
            std::cout << "���������: " << (calc + second).getValue() << std::endl;
            break;
        case '-':
            std::cout << "���������: " << (calc - second).getValue() << std::endl;;
            break;
        case '*':
            std::cout << "���������: " << (calc * second).getValue() << std::endl;;
            break;
        case '/':
            try
            {
                std::cout << "���������: " << (calc / second).getValue() << std::endl;;
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

    std::cout << "�������� ���������: " << calc.getValue() << std::endl;
}

void MenuHelper::engineeringMenu()
{
    while (true)
    {
        system("cls");
        ConsoleHelper::printLine("�������� ��������: ");
        ConsoleHelper::printLine("1 - x^y: ");
        ConsoleHelper::printLine("2 - ������ ���������� �� x: ");
        ConsoleHelper::printLine("3 - �������� x �� ��������� y: ");
        ConsoleHelper::printLine("4 - ����������� �������� �� x: ");
        ConsoleHelper::printLine("5 - ���������� �������� �� x: ");
        ConsoleHelper::printLine("6 - ������ x: ");
        ConsoleHelper::printLine("7 - ��������� x: ");
        ConsoleHelper::printLine("0 - �����: ");
        int choice{};
        std::cin >> choice;
        switch (choice)
        {
        case 1: {
            ConsoleHelper::printLine("�� ������� 1 - x^y: ");
            double x = ConsoleHelper::inputDouble("������� x: ");
            double y = ConsoleHelper::inputDouble("������� y: ");
            std::cout << Engineering<double>::powerXY(x, y) << std::endl;
            system("pause");
        }break;
        case 2: {
            ConsoleHelper::printLine("�� ������� 2 - ������ ���������� �� x: ");
            double x = ConsoleHelper::inputDouble("������� x: ");
            if (isnan(Engineering<double>::sqrtX(x)))
            {
                std::cout << "������ �� ��������" << std::endl;
            }
            else
            {
                std::cout << Engineering<double>::sqrtX(x) << std::endl;
            }
            system("pause");
        }break;
        case 3: {
            ConsoleHelper::printLine("�� ������� 3 - �������� x �� ��������� y: ");
            double x = ConsoleHelper::inputDouble("������� x: ");
            double y = ConsoleHelper::inputDouble("������� y: ");
            if (isnan(Engineering<double>::logXY(x, y)))
            {
                std::cout << "�������� �� ��������" << std::endl;
            }
            else
            {
                std::cout << Engineering<double>::logXY(x, y) << std::endl;
            }

            system("pause");
        }break;
        case 4: {
            ConsoleHelper::printLine("�� ������� 4 - ����������� �������� �� x: ");
            double x = ConsoleHelper::inputDouble("������� x: ");
            if (isnan(Engineering<double>::lnX(x)))
            {
                std::cout << "�������� �� ��������" << std::endl;
            }
            else
            {
                std::cout << Engineering<double>::lnX(x) << std::endl;
            }
            system("pause");
        }break;
        case 5: {
            ConsoleHelper::printLine("�� ������� 5 - ���������� �������� �� x: ");
            double x = ConsoleHelper::inputDouble("������� x: ");
            if (isnan(Engineering<double>::logDecX(x)))
            {
                std::cout << "�������� �� ��������" << std::endl;
            }
            else
            {
                std::cout << Engineering<double>::logDecX(x) << std::endl;
            }
            system("pause");
        }break;
        case 6: {
            ConsoleHelper::printLine("�� ������� 6 - ������ x: ");
            double x = ConsoleHelper::inputDouble("������� x: ");
            std::cout << Engineering<double>::absX(x) << std::endl;
            system("pause");
        }break;
        case 7: {
            ConsoleHelper::printLine("�� ������� 7 - ��������� x: ");
            int x = ConsoleHelper::inputInt("������� x: ");
            std::cout << Engineering<int>::factorialX(x) << std::endl;
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

void MenuHelper::trigonometryMenu()
{
    while (true)
    {
        system("cls");
        ConsoleHelper::printLine("�������� ��������: ");
        ConsoleHelper::printLine("1 - sin(x): ");
        ConsoleHelper::printLine("2 - cos(x): ");
        ConsoleHelper::printLine("3 - tg(x): ");
        ConsoleHelper::printLine("4 - ctg(x): ");
        ConsoleHelper::printLine("5 - arcsin(x): ");
        ConsoleHelper::printLine("6 - arccos(x): ");
        ConsoleHelper::printLine("7 - arctg(x): ");
        ConsoleHelper::printLine("8 - arcctg(x): ");
        ConsoleHelper::printLine("0 - �����: ");
        int choice{};
        std::cin >> choice;
        switch (choice)
        {
        case 1: {
            ConsoleHelper::printLine("�� ������� 1 - sin(x): ");
            double x = ConsoleHelper::inputDouble("������� x: ");
            bool isRadian = ConsoleHelper::inputBool("0 - �������; 1 - �������: ");
            x = Trigonometry<double>::convertToRadian(x, isRadian);
            std::cout << Trigonometry<double>::sinX(x) << std::endl;
            system("pause");
        }break;
        case 2: {
            ConsoleHelper::printLine("�� ������� 2 - cos(x): ");
            double x = ConsoleHelper::inputDouble("������� x: ");
            bool isRadian = ConsoleHelper::inputBool("0 - �������; 1 - �������: ");
            x = Trigonometry<double>::convertToRadian(x, isRadian);
            std::cout << Trigonometry<double>::cosX(x) << std::endl;
            system("pause");
        }break;
        case 3: {
            ConsoleHelper::printLine("�� ������� 3 - tg(x): ");
            double x = ConsoleHelper::inputDouble("������� x: ");
            bool isRadian = ConsoleHelper::inputBool("0 - �������; 1 - �������: ");
            x = Trigonometry<double>::convertToRadian(x, isRadian);
            if (isinf(Trigonometry<double>::tgX(x)))
            {
                std::cout << "������� �� ��������" << std::endl;
            }
            else
            {
                std::cout << Trigonometry<double>::tgX(x) << std::endl;
            }
            system("pause");
        }break;
        case 4: {
            ConsoleHelper::printLine("�� ������� 4 - ctg(x): ");
            double x = ConsoleHelper::inputDouble("������� x: ");
            bool isRadian = ConsoleHelper::inputBool("0 - �������; 1 - �������: ");
            x = Trigonometry<double>::convertToRadian(x, isRadian);
            std::cout << Trigonometry<double>::ctgX(x) << std::endl;
            system("pause");
        }break;
        case 5: {
            ConsoleHelper::printLine("�� ������� 5 - arcsin(x): ");
            double x = ConsoleHelper::inputDouble("������� x: ");
            std::cout << Trigonometry<double>::arcsinX(x) << std::endl;
            system("pause");
        }break;
        case 6: {
            ConsoleHelper::printLine("�� ������� 6 - arccos(x): ");
            double x = ConsoleHelper::inputDouble("������� x: ");
            std::cout << Trigonometry<double>::arccosX(x) << std::endl;
            system("pause");
        }break;
        case 7: {
            ConsoleHelper::printLine("�� ������� 7 - arctg(x): ");
            double x = ConsoleHelper::inputDouble("������� x: ");
            std::cout << Trigonometry<double>::arctgX(x) << std::endl;
            system("pause");
        }break;
        case 8: {
            ConsoleHelper::printLine("�� ������� 8 - arcctg(x): ");
            double x = ConsoleHelper::inputDouble("������� x: ");
            std::cout << Trigonometry<double>::arcctgX(x) << std::endl;
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


//void MenuHelper::programmerMenu()
//{
//    while (true)
//    {
//        system("cls");
//        ConsoleHelper::printLine("�������� ��������: ");
//        ConsoleHelper::printLine("1 - ������� ����� ������>>: ");
//        ConsoleHelper::printLine("2 - ������� ����� �����<<: ");
//        ConsoleHelper::printLine("3 - ������� �� ����� ������� ��������� � ������: ");
//        /*ConsoleHelper::printLine("4 - ����������� �������� �� ��������� x: ");
//        ConsoleHelper::printLine("5 - ���������� �������� �� ��������� x: ");
//        ConsoleHelper::printLine("6 - ������ x: ");*/
//        ConsoleHelper::printLine("0 - �����: ");
//        int choice{};
//        std::cin >> choice;
//        switch (choice)
//        {
//        case 1: {
//            ConsoleHelper::printLine("�� ������� 1 - x^y: ");
//            double x = ConsoleHelper::inputDouble("������� x: ");
//            double y = ConsoleHelper::inputDouble("������� y: ");
//            std::cout << Engineering<double>::powerXY(x, y) << std::endl;
//            system("pause");
//        }break;
//        case 2: {
//            ConsoleHelper::printLine("�� ������� 2 - ������ ���������� �� x: ");
//            double x = ConsoleHelper::inputDouble("������� x: ");
//            std::cout << Engineering<double>::sqrtX(x) << std::endl;
//            system("pause");
//        }break;
//        case 3: {
//            ConsoleHelper::printLine("�� ������� 3 - �������� x �� ��������� y: ");
//            double x = ConsoleHelper::inputDouble("������� x: ");
//            double y = ConsoleHelper::inputDouble("������� y: ");
//            std::cout << Engineering<double>::logXY(x, y) << std::endl;
//            system("pause");
//        }break;
//        /*case 4: {
//            ConsoleHelper::printLine("�� ������� 4 - �������� x �� ��������� y: ");
//            double x = ConsoleHelper::inputDouble("������� x: ");
//            std::cout << Engineering<double>::lnX(x) << std::endl;
//            system("pause");
//        }break;
//        case 5: {
//            ConsoleHelper::printLine("�� ������� 5 - �������� x �� ��������� y: ");
//            double x = ConsoleHelper::inputDouble("������� x: ");
//            std::cout << Engineering<double>::logDecX(x) << std::endl;
//            system("pause");
//        }break;
//        case 6: {
//            ConsoleHelper::printLine("�� ������� 6 - ������ x: ");
//            double x = ConsoleHelper::inputDouble("������� x: ");
//            std::cout << Engineering<double>::absX(x) << std::endl;
//            system("pause");
//        }break;*/
//        case 0: {
//            return;
//        }break;
//        default: {
//            ConsoleHelper::printLine("������: ");
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
        ConsoleHelper::printLine("�������� ��������: ");
        ConsoleHelper::printLine("1 - ��������: ");
        ConsoleHelper::printLine("2 - ���������: ");
        ConsoleHelper::printLine("3 - ���������: ");
        ConsoleHelper::printLine("4 - ������������� �������: ");
        ConsoleHelper::printLine("0 - �����: ");
        int choice{};
        std::cin >> choice;
        switch (choice)
        {
        case 1: {
            ConsoleHelper::printLine("�� ������� 1 - ��������: ");

            system("pause");
        }break;
        case 2: {
            ConsoleHelper::printLine("�� ������� 2 - ���������: ");

            system("pause");
        }break;
        case 3: {
            ConsoleHelper::printLine("�� ������� 3 - ���������: ");

            system("pause");
        }break;
        case 4: {
            ConsoleHelper::printLine("�� ������� 4 - ������������� �������: ");

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

void MenuHelper::stringMenu()
{
    while (true)
    {
        system("cls");
        ConsoleHelper::printLine("�������� ��������: ");
        ConsoleHelper::printLine("1 - ������� ����: ");
        ConsoleHelper::printLine("2 - ������� �������: ");
        ConsoleHelper::printLine("3 - ������� ���������: ");
        ConsoleHelper::printLine("4 - ������������: ");
        ConsoleHelper::printLine("5 - ������ �������: ");
        ConsoleHelper::printLine("0 - �����: ");
        int choice{};
        std::cin >> choice;
        switch (choice)
        {
        case 1: {
            ConsoleHelper::printLine("�� ������� 1 - ������� ����: ");
            std::string message;
            std::cin.clear();
            /*std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');*/
            std::cout << "������� ������: " << std::endl;
            std::getline(std::cin, message);
            std::cout << String::countOfElem(message) << std::endl;
            system("pause");
        }break;
        case 2: {
            ConsoleHelper::printLine("�� ������� 2 - ������� �������: ");
            std::string message;
            std::cin.clear();
            /*std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');*/
            std::cout << "������� ������: " << std::endl;
            std::getline(std::cin, message);
            std::cout << String::countOfVowels(message) << std::endl;
            system("pause");
        }break;
        case 3: {
            ConsoleHelper::printLine("�� ������� 3 - ������� ���������: ");

            system("pause");
        }break;
        case 4: {
            ConsoleHelper::printLine("�� ������� 4 - ������������: ");

            system("pause");
        }break;
        case 5: {
            ConsoleHelper::printLine("�� ������� 5 - ������ �������: ");

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