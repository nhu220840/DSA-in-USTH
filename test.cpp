/*
    AUTHOR: Do Nguyen Gia Nhu
    ID: 22BA13248
*/

#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

bool isCenteredCube(int target, int i){
    long long checkValue = pow(i, 3) + pow(i + 1, 3);
    // cout << checkValue << endl;
    if(target < checkValue) return false;
    if(target == checkValue) return true;

    return isCenteredCube(target, i + 1);

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a[] = {1, 2, 9, 3, 5, 25, 35, 60, 91};
    int n = sizeof(a) / sizeof(a[0]);
    for(int i = 0; i < n; i++){
        if(isCenteredCube(a[i], 0)){
            cout << a[i] << " is centered cube" << endl;
        }
        else cout << a[i] << " is NOT centered cube" << endl;
    }
    // cout << isCenteredCube(9, 0);
}