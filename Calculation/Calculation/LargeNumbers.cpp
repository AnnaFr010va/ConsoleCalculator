#include "LargeNumbers.h"
#include "ConsoleHelper.h"
#include <cmath>


std::string LargeNumbers::addLargeNumbers(std::string num1, std::string num2) {

    if (num1.length() < num2.length())
        swap(num1, num2);

    std::string result = "";
    int carry = 0;

    int i = num1.length() - 1, j = num2.length() - 1;
    while (i >= 0)
    {
        int sum = (i >= 0 ? num1[i] - '0' : 0) + (j >= 0 ? num2[j] - '0' : 0) + carry;
        result += std::to_string(sum % 10);
        carry = sum / 10;
        i--; j--;
    }

    if (carry)
        result += std::to_string(carry);

    reverse(result.begin(), result.end());

    return result;
}

std::string LargeNumbers::subtractLargeNumbers(std::string num1, std::string num2) {

    if (num1.length() < num2.length() || (num1.length() == num2.length() && num1 < num2)) {
        return "-" + subtractLargeNumbers(num2, num1);
    }

    std::string result = "";
    int borrow = 0;

    int i = num1.length() - 1, j = num2.length() - 1;
    while (i >= 0)
    {
        int diff = (i >= 0 ? num1[i] - '0' : 0) - (j >= 0 ? num2[j] - '0' : 0) - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        }
        else {
            borrow = 0;
        }
        result += std::to_string(diff);
        i--; j--;
    }
    result.erase(0, std::min(result.find_first_not_of('0'), result.size() - 1));

    reverse(result.begin(), result.end());

    return result.empty() ? "0" : result;
}

std::string LargeNumbers::multiplyLargeNumbers(std::string num1, std::string num2) {

    std::string result = "0";

    for (int i = num2.length() - 1; i >= 0; i--) {
        std::string tempResult;
        int carry = 0;

        for (int j = num1.length() - 1; j >= 0; j--) {
            int product = (num1[j] - '0') * (num2[i] - '0') + carry;
            tempResult = std::to_string(product % 10) + tempResult;
            carry = product / 10;
        }

        if (carry > 0) {
            tempResult = std::to_string(carry) + tempResult;
        }

        for (int k = 0; k < num2.length() - 1 - i; k++) {
            tempResult += '0';
        }

        result = addLargeNumbers(result, tempResult);
    }

    return result;
}

std::string LargeNumbers::divideLargeNumbers(std::string dividend, std::string divisor) {

    if (divisor == "0") {
        return "Ошибка: деление на ноль!";
    }

    std::string quotient = "";
    std::string remainder = "";
    int idx = 0;
    std::string temp = std::string(1, dividend[idx]);

    while (idx < dividend.size()) {
        while (temp.compare("0") == 0 && idx < dividend.size() - 1) {
            temp = temp + dividend[++idx];
        }

        if (temp.compare("0") == 0) {
            break;
        }

        if (temp.compare(divisor) < 0) {
            quotient += "0";
        }
        else {
            int count = 0;
            while (temp.compare(divisor) >= 0) {
                temp = subtractLargeNumbers(temp, divisor);
                count++;
            }
            quotient += std::to_string(count);
        }

        if (idx < dividend.size()) {
            temp = temp + dividend[++idx];
        }
    }

    remainder = temp;

    return quotient;
}

/* void LargeNumbers::initCalculateBigNumbers() {
     int choice;
     std::string num1, num2;

     do {
         std::cout << "Выберите операцию:\n";
         std::cout << "1. Сложение\n";
         std::cout << "2. Вычитание\n";
         std::cout << "3. Умножение\n";
         std::cout << "4. Деление нацело\n";
         std::cout << "0. Выход\n";
         std::cout << "Ваш выбор: ";
         std::cin >> choice;

         switch (choice)
         {
         case 1:
             std::cout << "Введите первое число: ";
             std::cin >> num1;
             std::cout << "Введите второе число: ";
             std::cin >> num2;
             std::cout << "Результат сложения: " << addLargeNumbers(num1, num2) << std::endl;
             break;
         case 2:
             std::cout << "Введите уменьшаемое: ";
             std::cin >> num1;
             std::cout << "Введите вычитаемое: ";
             std::cin >> num2;
             std::cout << "Результат вычитания: " << subtractLargeNumbers(num1, num2) << std::endl;
             break;
         case 3:
             std::cout << "Введите первое число: ";
             std::cin >> num1;
             std::cout << "Введите второе число: ";
             std::cin >> num2;
             std::cout << "Результат умножения: " << multiplyLargeNumbers(num1, num2) << std::endl;
             break;
         case 4:
             std::cout << "Введите делимое: ";
             std::cin >> num1;
             std::cout << "Введите делитель: ";
             std::cin >> num2;
             std::cout << "Результат деления нацело: " << divideLargeNumbers(num1, num2) << std::endl;
             break;
         case 0:
             std::cout << "Выход из программы.\n";
             break;
         default:
             std::cout << "Некорректный выбор. Попробуйте снова.\n";
         }
     } while (choice != 4);
 }*/
