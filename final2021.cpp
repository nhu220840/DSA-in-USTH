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

void recursive(int a[], int n, int i, int j){
    if(i >= n - 1) return;

    if(j >= n){
        recursive(a, n, i + 1, i + 2);
        return;
    }

    if(gcd(a[i], a[j]) == 1)
        cout << "(" << a[i] << ", " << a[j] << ")" << endl;

    recursive(a, n, i, j + 1);
}

int main(){
    int a[] = {2, 10, 27, 13, 90, 45, 5, 26, 49, 50};
    int n = sizeof(a) / sizeof(a[0]);
    // for(int i = 0; i < n - 1; i++){
    //     for(int j = i + 1; j < n; j++){
    //         if(gcd(a[i], a[j]) == 1){
    //             cout << "(" << a[i] << ", " << a[j] << ")" << endl;
    //         }
    //     }
    // }

    recursive(a, n, 0, 1);
}