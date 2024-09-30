/*
    AUTHOR: Do Nguyen Gia Nhu
    ID: 22BA13248
*/

#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

const int MAX_SIZE = 1000000;
int isPrime[MAX_SIZE + 1];

void sieveOfEratosthenes(){
    for(int i = 0; i < MAX_SIZE; i++){
        isPrime[i] = 1;
    }
    isPrime[0] = isPrime[1] = 0;
    for(int i = 2; i <= sqrt(MAX_SIZE); i++){
        if(isPrime[i]){
            for(int j = i * i; j <= MAX_SIZE; j += i){
                isPrime[j] = 0;
            }
        }
    }
}

void recursive(int n, int i){
    if(n == 1 || i > MAX_SIZE) return;

    if(isPrime[i] && (n % i == 0)){
        while(n % i == 0){
            cout << i;
            if(n / i != 1) cout << " * ";
            n /= i;
        }
    }
    recursive(n, i + 1);
}

void rec(int n){
    bool isPrime = true;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            isPrime = false;
            cout << i << " * ";
            rec(n / i);
            return;
        }
    }
    if(n != 1) cout << n; return;
}

// BEGIN
//     Get n
//     for i in range(2, sqrt(n)):
//         while n % i == 0 do:
//             print i 
//             n = n / i
//         endwhile
//     endfor
//     if n != 1: print n
// END

int main(){
    sieveOfEratosthenes();
    int n = 84;
    // for(int i = 2; i <= sqrt(n); i++){
    //     if(n % i == 0){
    //         while(n % i == 0){
    //             cout << i << " * ";
    //             n /= i;
    //         }
    //     }
    // }
    // if(n != 1) cout << n;
    // recursive(n, 2);
    rec(n);
}