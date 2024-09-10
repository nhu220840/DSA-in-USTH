#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//Pseudocode
// def isSphenic(n):
//     Set cnt_prime = 0
//     for i <- 2 to sqrt(n) do:
//         if n % i == 0:
//             Set pow = 0
//             while n % i == 0 do:
//                 pow = pow + 1
//                 cnt_prime = cnt_prime + 1
//                 n = n / i
//             endwhile
//             if pow > 1: return False
//     endfor
//     if n != 1: cnt_prime = cnt_prime + 1
    
//     if cnt_prime == 3: return True
//     return False

bool isSphenic(int n){
    int cnt = 0;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            cnt++;
            int power = 0;
            while(n % i == 0){
                power++;
                n /= i;
            }
            if(power > 1) return false;
        }
    }
    if(n != 1) cnt++;
    return cnt == 3;
}

int main(){
    cout << "Enter an integer: ";
    int n; cin >> n;
    if(isSphenic(n))
        cout << n << " is a Sphenic number" << endl;
    else
        cout << n << " is NOT a Sphenic number" << endl;
}