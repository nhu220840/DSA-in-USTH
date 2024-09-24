/*
    AUTHOR: Do Nguyen Gia Nhu
    ID: 22BA13248
*/

#include <iostream>
#include <cmath>

using namespace std;

// Pseudocode:
// Input: A natural number
// Output: The digit sum of a given natural number
// Process:
// BEGIN
//     Get n
//     Set sum <- 0
//     while n != 0 do:
//         sum = sum + (n % 10)
//         n = n / 10
//     endwhile
//     print sum
// END

// Complexity:
// T(n) = 1 + 1 + 1 + logn*2 + 1 = 4 + 2logn
// T(n) = O(logn)

int main(){
    int n = 103509; //O(1)
    int tmp = n; //O(1)
    int sum = 0; //O(1)
    while(tmp){ //O(logn)
        sum += tmp % 10; //O(1)
        tmp /= 10; //O(1)
    }
    cout << "Sum of all digits of natural number " << n <<  " is: " << sum << endl; //O(1)
}