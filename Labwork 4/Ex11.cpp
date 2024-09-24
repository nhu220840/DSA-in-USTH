#include <stdio.h>
#define ll long long

//Complexity:
// T(n) = 1 + 1 + 1 + T(n / 10)
// T(n) = 3 + T(n / 10)
// => T(n) = O(logn)

ll sumOfDigits(ll n){
    if(n < 10) return n;
    return n % 10 + sumOfDigits(n / 10);
}

int main(){
    printf("Enter a natural number: ");
    ll n; scanf("%lld", &n);
    printf("Sum of all digits: %lld", sumOfDigits(n));
}