#include <stdio.h>
#define ll long long

// Pseudocode: 
// Input: Read a natural number
// Output: Display sum of all digits of a natural number

// Process
// BEGIN:
//     Read n
//     Set sumOfDigits <- 0
//     while(n != 0):
//         sumOfDigits += n % 10
//         n /= 10
//     endwhile
//     print sumOfDigits
// END

// Complextity:
// T(n) = 1 + 1 + n + n + 1 = 2n + 3
// T(n) = O(n)



int main(){
    printf("Enter a natural number: ");
    ll n; scanf("%lld", &n);
    ll sumOfDigits = 0;
    while(n){
        sumOfDigits += n % 10;
        n /= 10;
    }
    printf("Sum of all digits: %lld", sumOfDigits);
}