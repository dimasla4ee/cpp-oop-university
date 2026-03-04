#include <iostream>

// Напишите программу, которая находит N-ое по счёту простое число.
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

    std::cout << "Enter a number: ";
    std::cin >> n;

    if (n == 1) {
        std::cout << "The 1st prime is 2" << std::endl;
        return 0;
    }
    
    int number = 1;
    int primeCounter = 1;
    while (primeCounter != n) {
        number += 2;
        if (isPrime(number)) {
            primeCounter++;
        }
    }
    
    std::cout << "The " << n << "th prime is " << number << std::endl;

    return 0;
}