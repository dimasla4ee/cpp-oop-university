#include <iostream>

// Напишите программу, которая запрашивает у пользователя два целых числа.
// После ввода программа должна вычислить и вывести на экран их сумму, разность,
// произведение и частное.
int main() {
    int a;
    int b;

    std::cout << "Enter the first integer: ";
    std::cin >> a;

    std::cout << "Enter the second integer: ";
    std::cin >> b;

    char operators[] = {'+', '-', '*', '/'};

    for (char op : operators) {
        float result;

        switch (op) {
            case '+':
                result = a + b;
                break;
            case '-':
                result = a - b;
                break;
            case '*':
                result = a * b;
                break;
            case '/':
                result = a / (float)b;
                break;
            default:
                break;
        }

        std::cout << a << " " << op << " " << b << " = " << result << std::endl;
    }

    return 0;
}
