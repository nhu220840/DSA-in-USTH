/*
    AUTHOR: Do Nguyen Gia Nhu
    ID: 22BA13248
*/

#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

void coPrimeNumbers(int a[], int n){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(gcd(a[i], a[j]) == 1){
                cout << "(" << a[i] << ", " << a[j] << ")";
                if(i != n - 1 && j != n - 1) cout << ", ";
            }
        }
    }
}

void coPrimeNumbers_rec(int a[], int i, int n){
    if(i >= n) return;
    for(int j = i + 1; j < n; j++){
        if(gcd(a[i], a[j]) == 1){
            cout << "(" << a[i] << ", " << a[j] << ")";
            if(i != n - 1 && j != n - 1) cout << ", ";
        }
    }
    return coPrimeNumbers_rec(a, i + 1, n);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a[] = {2, 10, 27, 13, 90, 45, 5, 26, 49, 50};
    int n = sizeof(a) / sizeof(a[0]);
    coPrimeNumbers(a, n);
    cout << endl;
    coPrimeNumbers_rec(a, 0, n);
}