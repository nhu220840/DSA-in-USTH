/*
    AUTHOR: Do Nguyen Gia Nhu
    ID: 22BA13248
*/

#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

void insertionSortOptimize(int a[], int n){
    int swapped = 1;
    int start = 0, end = n - 1;
    while(swapped){
        swapped = 0;
        for(int i = start + 1; i <= end; i++){
            int pos = i - 1, value = a[i];
            while(pos >= 0 && a[pos] > value){
                a[pos + 1] = a[pos];
                pos--;
                swapped = 1;
            }
            a[pos + 1] = value;
        }

        if(!swapped) break;

        end--;

        for(int i = end - 1; i >= start; i--){
            int pos = i + 1, value = a[i];
            while(pos >= 0 && a[pos] < value){
                
            }
        }
    }
}

int main(){
    int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = sizeof(a) / sizeof(a[0]);
    insertionSortOptimize(a, size);
    for(int i = 0; i < size; i++){
        cout << a[i] << " ";
    }
}