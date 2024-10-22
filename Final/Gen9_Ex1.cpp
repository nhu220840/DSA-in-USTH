#include <stdio.h>
#include <math.h>
#define ll long long

// int checkSphenicNumber(ll n){
//     int cnt = 0;
//     for(int i = 2; i <= sqrt(n); i++){
//         if(n % i == 0){
//             cnt++;
//             int pow = 0;
//             while(n % i == 0){
//                 pow++;
//                 n /= i;
//             }
//             if(pow > 1 || cnt > 3) return 0;
//         }
//     }
//     if(n != 1) cnt++;
//     return cnt == 3;
// }

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
//Complexity of sieve of Eratosthenes = O(n*log(logn))

int isSphenicNumber(ll n, int i, int cnt, ll product){
    if(cnt == 3 && n == 1) return 1; //T(n) = 2
    if(cnt > 3 || i > MAX_SIZE || n == 1) return 0; //T(n) = 3
    if(isPrime[i] && n % i == 0){ //T(n) = 2
        int power = 0; // T(n) = 1
        while(n % i == 0){ //T(n) = logn
            n /= i; 
            power++;
        }

        if(power > 1) return 0; //T(n) = 1
        return isSphenicNumber(n, i + 1, cnt + 1, product * i); //T(n) = 3 + T(n / i) 
        // (15, 3, 1, 2)
        // (5, 4, 2, 6)
        // 
    }
    else return isSphenicNumber(n, i + 1, cnt, product); //T(n) = 1 + T(n / i)
}
// Complexity: O(logn)

int main(){
    sieveOfEratosthenes();
    int n = 100;

    for(int i = 1; i <= n; i++){
        if (isSphenicNumber(i, 2, 0, 1)){
            printf("%d is a Sphenic number\n", i);
        } 
        else{
            printf("%d is NOT a Sphenic number\n", i);
        }
    }
}

// Complexity: O(n*log(logn))