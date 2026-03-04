#include <iostream>
#include <vector>
#include "QuadraticEquasion.h"

// Реализуйте программу для решения квадратного уравнения вида ax^2+bx+c=0. Коэффициенты a, b и c вводятся пользователем.
// Программа должна использовать как минимум две отдельные функции:
// - для вычисления дискриминанта
// - для нахождения корней.
// Также необходимо предусмотреть обработку случаев, когда:
// - Дискриминант больше нуля (два различных вещественных корня).
// - Дискриминант равен нулю (один вещественный корень).
// - Дискриминант меньше нуля (нет вещественных корней).
int main() {
    double a;
    double b;
    double c;

    std::cout << "Enter coefficient a: ";
    std::cin >> a;

    std::cout << "Enter coefficient b: ";
    std::cin >> b;

    std::cout << "Enter coefficient c: ";
    std::cin >> c;

    std::cout << a << "x^2 + " << b << " x + " << c << " = 0" << std::endl;

    QuadraticEquasion qe(a, b, c);
    std::vector<double> roots = qe.findRoots();
    std::string result;
    if (roots.empty()) {
        result = "No roots";
    } else if (roots.size() == 1) {
        result = "Root is ";
    } else {
        result = "Roots are ";
    }
    std::cout << result;
    for (auto& root : roots) {
        std::cout << root << " ";
    }
    std::cout << std::endl;

    return 0;
}