/*
    AUTHOR: Do Nguyen Gia Nhu
    ID: 22BA13248
*/

#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;
using ll = long long;

int reverseNum(int n){
    int rev = 0;
    while(n){
        int r = n % 10;
        rev = rev * 10 + r;
        n /= 10;
    }
    return rev;
}
// Complexity: O(logn)

int isPalindrome(string a, int start, int end){
    if(start >= end) return 1; //T(n) = 1
    if(a[start] != a[end]) return 0; //T(n) = 1
    return isPalindrome(a, start + 1, end - 1); //T(n) = 3 + T(n / 2)
}
//Complexity:
//T(n) = 1 + 1 + 3 + T(n / 2) 
//T(n) = O(n)

int main(){
    int n = 1011;

    string tmp = "";
    int product = n * reverseNum(n);
    while(product){
        int r = product % 10;
        tmp += to_string(r);
        product /= 10;
    }
    
    if(isPalindrome(tmp, 0, tmp.size() - 1)){
        cout << "A product is palindromic" << endl;
    }
    else cout << "A product is NOT palindromic" << endl;
}
// Total complexity: O(logn + n) = O(n)



//Opimize process: We use 1 function to check palindrome is similarly to the function of reverse number
//Like this:

// bool checkPalindromeProduct(int product){
//     int tmp = product;
//     int rev_product = 0;
//     while(product){
//         rev_product = rev_product * 10 + product % 10;
//         product /= 10;
//     }

//     return tmp == rev_product;
// }

// Complexity: O(logn)


