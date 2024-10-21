/*
    AUTHOR: Do Nguyen Gia Nhu
    ID: 22BA13248
*/

#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

void bubbleSort(int a[], int n){
    int left = 0, right = n - 1;
    while(left < right){
        for(int j = left; j < right; j++){
            if(a[j] > a[j + 1]){
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
        right--;
        cout << "1. ";
        for(int j = 0; j < n; j++){
            cout << a[j] << " ";
        }
        cout << endl;

        for(int j = right; j > left; j--){
            if(a[j] < a[j - 1]){
                int tmp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = tmp;
            }
        }
        left++;

        cout << "2. ";
        for(int j = 0; j < n; j++){
            cout << a[j] << " ";
        }
        cout << endl;
    }
}


int main(){
    int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(a) / sizeof(a[0]);
    bubbleSort(a, n);
}