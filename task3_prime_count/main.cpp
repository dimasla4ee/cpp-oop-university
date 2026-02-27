#include <iostream>

// Напишите программу, которая принимает на вход число N, а затем N целых чисел.
// Задача — определить и вывести количество простых чисел среди введённой
// последовательности.
bool isPrime(int number) {
    if (number == 2) {
        return true;
    }
    if (number % 2 == 0 || number <= 1) {
        return false;
    }

    for (size_t i = 3; i <= sqrt(number); i += 2) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;

    std::cout << "Enter amount of numbers: ";
    std::cin >> n;

    int primeCounter = 0;
    for (size_t i = 0; i < n; i++) {
        int number;

        std::cout << "Enter a number: ";
        std::cin >> number;

        if (isPrime(number)) {
            primeCounter++;
        }
    }
    std::cout << "There are " << primeCounter << " prime numbers" << std::endl;

    return 0;
}