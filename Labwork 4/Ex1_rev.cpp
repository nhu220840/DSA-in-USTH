/*
    AUTHOR: Do Nguyen Gia Nhu
    ID: 22BA13248
*/

#include <iostream>
#include <cmath>

using namespace std;

//Complexity
// T(n) = 1 + 1 + 1 + 1 + T(n / 10) + 1
// T(n) = 5 + T(n / 10)
// T(n) = O(logn)

int recursiveSum(int n){
    if(n < 10) //O(1)
        return n; //O(1)
    return n % 10 + recursiveSum(n / 10); //T(n) = O(1) + T(n / 10)
}

int main(){   
    int n = 9512; //O(1)
    cout << "Sum of all digits of natural number " << n <<  " is: " << recursiveSum(n); //O(1)
}