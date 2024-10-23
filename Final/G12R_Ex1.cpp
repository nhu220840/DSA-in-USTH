/*
    AUTHOR: Do Nguyen Gia Nhu
    ID: 22BA13248
*/

#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

double calculate(int n){
    if(n == 0) return 0.5;

    if(n % 2 == 0)
        return pow(-1, n) / ((n - 1) * n) + calculate(n - 1);
    else
        return pow(1, n) / (n * (n + 1)) + calculate(n - 1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << calculate(10);
    
}