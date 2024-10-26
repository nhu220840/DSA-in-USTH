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

int isPalindrome(char* a, int start, int end){
    if(start >= end) return 1; //T(n) = 1
    if(a[start] != a[end]) return 0; //T(n) = 1
    return isPalindrome(a, start + 1, end - 1); //T(n) = 3 + T(n / 2)
}

//Complexity:
//T(n) = 1 + 1 + 3 + T(n / 2) 
//T(n) = O(n)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = 12;
    char *arr = (int *)malloc(sizeof(int) * 100);
    int cnt = 0;
    int product = n * reverseNum(n);
    while(product){
        int r = product % 10;
        arr[cnt] = r + 
    }
    string product = to_string(n * reverseNum(n));
    if(isPalindrome(product, 0, product.size() - 1)){
        cout << "A product is palindromic" << endl;
    }
    else cout << "A product is NOT palindromic" << endl;
}
// Total complexity: O(logn + n) = O(n)


