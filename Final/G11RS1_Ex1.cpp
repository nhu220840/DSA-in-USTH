/*
    AUTHOR: Do Nguyen Gia Nhu
    ID: 22BA13248
*/

#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

// int countOdd(int n){
//     int cnt = 0;
//     while(n){
//         int r = n % 10;
//         if(r % 2 != 0) cnt++;
//         n /= 10;
//     }
//     return cnt;
// }

int countOdd_rec(int n){
    if(n < 10){
        if(n % 2 != 0) return 1;
        else return 0;
    }
    else{
        int r = n % 10;
        if(r % 2 != 0) return 1 + countOdd_rec(n / 10);
        else return countOdd_rec(n / 10); 
    }
}

// int countEven(int n){
//     int cnt = 0;
//     while(n){
//         int r = n % 10;
//         if(r % 2 == 0) cnt++;
//         n /= 10;
//     }
//     return cnt;
// }

int countEven_rec(int n){
    if(n < 10){
        if(n % 2 == 0) return 1;
        else return 0;
    }
    else{
        int r = n % 10;
        if(r % 2 == 0) return 1 + countEven_rec(n / 10);
        else return countEven_rec(n / 10); 
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = 3450;
    // cout << countOdd(n) << " " << countEven(n) << endl;
    cout << countOdd_rec(n) << " " << countEven_rec(n) << endl;
}