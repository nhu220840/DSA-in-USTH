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
            swap(a[i], a[min_pos]);
        }
        for(int j = 0; j < n; j++){
            cout << a[j] << " ";
        }
        cout << endl;
    }
    
    // for(int i = 0; i < n; i++){
    //     cout << a[i] << " ";
    // }
    // cout << endl;
}

void selectionSortOptimized(int a[], int n){
    int left = 0, right = n - 1;
    while(left < right){
        int min_pos = left, max_pos = right;
        for(int i = left; i <= right; i++){
            if(a[i] < a[min_pos]){
                min_pos = i;
            }
        }
        swap(a[left], a[min_pos]);
        left++;

        cout << "Find min: ";
        for(int i = 0; i < n; i++){
            cout << a[i] << " ";
        }
        cout << endl;

        for(int i = right; i > left; i--){
            if(a[i] > a[max_pos]){
                max_pos = i;
            }
        }
        swap(a[right], a[max_pos]);
        right--;

        cout << "Find max: ";
        for(int i = 0; i < n; i++){
            cout << a[i] << " ";
        }
        cout << endl;
        
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = sizeof(a) / sizeof(a[0]);
    selectionSortOptimized(a, size);
}