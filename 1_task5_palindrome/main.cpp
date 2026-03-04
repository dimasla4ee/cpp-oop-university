#include <algorithm>
#include <iostream>
#include <sstream>

// Найти все целые числа в заданном диапазоне [A, B],
// которые являются палиндромами одновременно в десятичной и двоичной системах
// счисления. Числа, которые в десятичной или двоичной системе счисления
// начинаются с нуля, не считаются палиндромами.
std::string toBinary(int num) {
    if (num == 0) {
        return "0";
    }

    std::string result = "";
    while (num > 0) {
        result += std::to_string(num % 2);
        num /= 2;
    }

    std::reverse(result.begin(), result.end());
    return result;
}

bool isPalindrome(std::string str) {
    int leftIndex = 0;
    int rightIndex = str.length() - 1;

    while (leftIndex < rightIndex) {
        char leftChar = std::tolower(str[leftIndex]);
        char rightChar = std::tolower(str[rightIndex]);

        if (leftChar != rightChar) {
            return false;
        }

        leftIndex++;
        rightIndex--;
    }

    return true;
}

int main() {
    int a;
    int b;

    std::cout << "Enter lower limit: ";
    std::cin >> a;
    std::cout << "Enter upper limit: ";
    std::cin >> b;

    for (; a <= b; a++) {
        std::string num = std::to_string(a);

        if (!isPalindrome(num)) {
            continue;
        }

        std::string binaryNum = toBinary(a);
        if (!isPalindrome(binaryNum)) {
            continue;
        }

        std::cout << num << " (" << binaryNum << ") is palindrome" << std::endl;
    }

    return 0;
}
