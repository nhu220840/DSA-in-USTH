/*
    AUTHOR: Do Nguyen Gia Nhu
    ID: 22BA13248
*/

#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

bool isPentagonal(int target, int n){
    int checkValue = (3 * pow(n, 2) - n) / 2;

    if(checkValue > target) return false;
    if(checkValue == target) return true;

    return isPentagonal(target, n + 1);
}

int main(){
    int a[] = {1, 2, 5, 6, 12, 3, 4, 9};
    int size = sizeof(a) / sizeof(a[0]);
    for(int i = 0; i < size; i++){
        if(isPentagonal(a[i], 1)){
            cout << a[i] << " is Pentagonal" << endl;
        }
        else{
            cout << a[i] << " is NOT Pentagonal" << endl;
        }
    }
}