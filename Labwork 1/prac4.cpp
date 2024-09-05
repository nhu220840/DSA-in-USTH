#include <bits/stdc++.h>

using namespace std;
using ll = long long;

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