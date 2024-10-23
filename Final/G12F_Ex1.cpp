/*
    AUTHOR: Do Nguyen Gia Nhu
    ID: 22BA13248
*/

#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

bool isPrime (int n){
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return n > 1;
}

void twinPrimes(int a[], int i, int j, int n){
    if(i >= n - 1) return;
    if(j >= n) return twinPrimes(a, i + 1, i + 2, n);

    if(isPrime(a[i]) && isPrime(a[j]) && abs(a[i] - a[j]) == 2){
        cout << "{" << a[i] << ", " << a[j] << "}" << endl;
    }
    return twinPrimes(a, i, j + 1, n);
}

void twinPrimes_2(int a[], int i, int n){
    if(i >= n - 1) return;

    for(int j = i + 1; j < n; j++){
        if(isPrime(a[i]) && isPrime(a[j]) && abs(a[i] - a[j]) == 2){
            cout << "{" << a[i] << ", " << a[j]  << "}" << endl;
        }
    }
    return twinPrimes_2(a, i + 1, n);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a[] = {3, 101, 96, 47, 41, 7, 65, 9, 13, 5, 79, 45, 30, 11, 43};
    int size = sizeof(a) / sizeof(a[0]);
    // twinPrimes(a, 0, 1, size);
    twinPrimes_2(a, 0, size);
}