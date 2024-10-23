/*
    AUTHOR: Do Nguyen Gia Nhu
    ID: 22BA13248
*/

#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

void fac(int n){
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            while(n % i == 0){
                cout << i << " ";
                n /= i;
            }
        }
    }
    if(n != 1) cout << n << endl;
}

void primeFactorization(int n){
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            cout << i << " ";
            primeFactorization(n / i);
            return;
        }
    }
    if(n != 1) cout << n << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = 110;
    fac(n);
    primeFactorization(n);
}