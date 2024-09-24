/*
    AUTHOR: Do Nguyen Gia Nhu
    ID: 22BA13248
*/

#include <iostream>
#include <cmath>

using namespace std;

// Complexity of sieve of Eratosthenes: O(n*log(logn))

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

//Complexity of isSphenic: T(n) = 1 + 1 + 2 + 1 + logn + 1 + logn + logn = 6 + 3logn = O(logn)

bool isSphenic(int n, int cnt, int i){
    if(cnt == 3 && n == 1) return true; //O(1)
    if(cnt > 3 || i > MAX_SIZE || n == 1) return false; //O(1)

    if(isPrime[i] && n % i == 0){ //O(2)
        int power = 0; //O(1)
        while(n % i == 0){ //O(logn)
            n /= i; 
            power++;
        }
        if(power > 1) return false; //O(1)
        return isSphenic(n, cnt + 1, i + 1); //T(n) = T(n / i)
    }
    else return isSphenic(n, cnt, i + 1); //T(n) = T(n / i)
}

// Complexity: T(n) = O(n*log(logn)) + O(logn) = O(n*log(logn))

int main(){
    sieveOfEratosthenes();
    int n = 100;
    for(int i = 1; i <= n; i++){
        if(isSphenic(i, 0, 2)){
            cout << i << " is a Sphenic number" << endl;
        }
    }
}