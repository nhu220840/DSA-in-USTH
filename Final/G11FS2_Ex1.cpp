/*
    AUTHOR: Do Nguyen Gia Nhu
    ID: 22BA13248
*/

#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

void selectionSort(int a[], int n){
    for(int i = 0; i < n - 1; i++){
        int min_pos = i;
        for(int j = i + 1; j < n; j++){
            if(a[j] < a[min_pos]){
                min_pos = j;
            }
        }
        int tmp = a[i];
        a[i] = a[min_pos];
        a[min_pos] = tmp;
    }
}

void selectionSortOptimize(int a[], int left, int right){
    int mid = (left + right) / 2;
    int min_pos = 0;
    for(int j = 1; j < right; j++){
        if(a[j] < a[min_pos]) min_pos = j;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(a) / sizeof(a[0]);
    selectionSort(a, n);
    for(int x : a) cout << x << " ";
}