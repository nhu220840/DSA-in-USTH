/*
    AUTHOR: Do Nguyen Gia Nhu
    ID: 22BA13248
*/

#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

bool isCenteredCube(int x, int i){
    int centeredCubeValue = pow(i, 3) + pow(i + 1, 3);

    if(centeredCubeValue > x) return false;
    if(centeredCubeValue == x) return true;

    return isCenteredCube(x, i + 1);
}

int main(){
    int a[] = {1, 91, 3, 9, 5, 6, 8, 35, 12};
    int n = sizeof(a) / sizeof(a[0]);

    for(int i = 0; i < n; i++){
        if(isCenteredCube(a[i], 1)){
            cout << a[i] << " is centered cube" << endl;
        }
        else cout << a[i] << " is NOT centerd cube" << endl;
    }
}