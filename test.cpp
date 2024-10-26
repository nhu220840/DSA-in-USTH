#include <stdio.h>
#include <stdbool.h>
#include <math.h>

//function use recursive
int reverseNumber(int n){
    int reversed = 0;
    while (n > 0){
        reversed = reversed * 10 + n % 10; 
        n /= 10;
    }
    return reversed;
}

int numDigits(int num){
    if (num == 0)
    return 0;
    return 1 + numDigits(num / 10);
    
}
    int firstDigit(int num, int digits) { // checking first digits
    return num / (int)pow(10, digits - 1);
}
int lastDigits(int num){  //checking last digits
    return num % 10;
}
bool isPalindromic(int n){
    if (n < 10)     
        return true;
    
    int digits = numDigits(n);
    int first = firstDigit(n, digits);
    int last = lastDigits(n);

    if (first != last) 
    return false;

    int remaining = (n % (int)pow(10, digits - 1)) / 10; 
    return isPalindromic(remaining);
}

int main(){
    int n;
    printf("Enter a natural number:");
    scanf("%d", &n);

    int reversed = reverseNumber(n);
    int product = n * reversed;
    if (isPalindromic(product)) {
        printf("The product of %d and its reverse %d is palindromic.\n", n, reversed);
    } else {
        printf("The product of %d and its reverse %d is not palindromic.\n", n, reversed);
    }

    return 0;
}