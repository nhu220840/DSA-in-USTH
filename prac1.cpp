#include <iostream>
#include <cmath>

// Helper function to count digits (moved outside isPalindromic)
int numDigits(int num) {
    if (num == 0)
        return 0;
    return 1 + numDigits(num / 10);
}

// Helper function to get first digit (moved outside isPalindromic)
int firstDigit(int num, int digits) {
    return num / static_cast<int>(pow(10, digits - 1));
}

// Helper function to get last digit (moved outside isPalindromic)
int lastDigits(int num) {
    return num % 10;
}

// Function using iteration
int reverseNumber(int n) {
    int reversed = 0;
    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return reversed;
}

bool isPalindromic(int n) {
    if (n < 10)
        return true;
    
    int digits = numDigits(n);
    int first = firstDigit(n, digits);
    int last = lastDigits(n);

    if (first != last)
        return false;

    int remaining = (n % static_cast<int>(pow(10, digits - 1))) / 10;
    return isPalindromic(remaining);
}

int main() {
    int n;
    std::cout << "Enter a natural number: ";
    std::cin >> n;

    int reversed = reverseNumber(n);
    int product = n * reversed;
    
    if (isPalindromic(product)) {
        std::cout << "The product of " << n << " and its reverse " << reversed << " is palindromic.\n";
    } else {
        std::cout << "The product of " << n << " and its reverse " << reversed << " is not palindromic.\n";
    }

    return 0;
}
