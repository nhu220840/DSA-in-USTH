/*
    AUTHOR: Do Nguyen Gia Nhu
    ID: 22BA13248
*/

#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

void bubbleSort(int a[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] > a[j]){
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

int main(){
    int a[] = {4, 15, 45, 9, 40, 27, 3, 5, 10};
    int n = sizeof(a) / sizeof(a[0]);
    bubbleSort(a, n);
    for(int x : a) cout << x << " ";
    cout << endl;
    for(int i = n - 1; i >= 2; i--){
        int l = 0, r = i - 1;
        while(l < r){
            if(a[l] * a[r] == a[i]){
                cout << "(" << a[l] << ", " << a[r] << ", " << a[i] << ")" << endl;
                l++; r--;
            }
            else if(a[l] * a[r] < a[i])
                l++;
            else
                r--;
        }
    }
}