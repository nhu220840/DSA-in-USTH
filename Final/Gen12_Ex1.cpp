/*
    AUTHOR: Do Nguyen Gia Nhu
    ID: 22BA13248
*/

#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

double calculate(int n){
    if(n == 0) return 1.0 / 2;
    if(n == 1) return 1.0;

    double term1 = pow(-1, n) / ((n - 1) * n);
    double term2 = pow(1, n + 1) / (n * (n + 1));

    return 1.0 / 2 + term1 + term2 + calculate(n - 1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << calculate(100);
    
}