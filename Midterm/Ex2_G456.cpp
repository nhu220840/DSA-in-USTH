/*
    AUTHOR: Do Nguyen Gia Nhu
    ID: 22BA13248
*/

#include <iostream>
#include <cmath>

using namespace std;

void bubbleSort(int a[], int n){
    for(int i = 0; i < n - 1; i++){ //O(n)
        for(int j = i + 1; j < n; j++){ //O(n)
            if(a[i] > a[j]){ //O(1)
                int tmp = a[i]; //O(1)
                a[i] = a[j]; //O(1)
                a[j] = tmp; //O(1)
            }
        }
    }
}
//Complexity of bubbleSort: 
//T(n) = n * n * (1 + 1 + 1 + 1) = 4n^2
//T(n) = O(n^2)

void pythagoreanTriples_recursive(int a[], int b[], int l, int r, int i){
    if(l >= r) return; //O(1)
    if(b[l] + b[r] == b[i]){ //O(1)
        cout << "(" << a[l] << ", " << a[r] << ", " << a[i] << ")" << endl;
        pythagoreanTriples_recursive(a, b, l + 1, r - 1, i); //T(n) = T(n - 1)
    }
    else if(b[l] + b[r] < b[i]) //O(1)
        pythagoreanTriples_recursive(a, b, l + 1, r, i); //T(n) = T(n - 1)
    else
        pythagoreanTriples_recursive(a, b, l, r - 1, i); //T(n) = T(n - 1)
}
// Complexity of pythagoreanTriples_recursive: 
// T(n) = 1 + 1 + T(n - 1)
// T(n) = O(logn)

int main(){
    int a[] = {3, 4, 5, 6, 10, 2, 8, 9, 1, 7}; //O(1)
    int n = sizeof(a) / sizeof(a[0]); //O(1)
    int b[n]; //O(1)
    for(int i = 0; i < n; i++){ //O(n)
        b[i] = a[i] * a[i]; //O(1)
    }
    bubbleSort(b, n); //O(n^2)
    bubbleSort(a, n); //O(n^2)

    for(int i = 0; i < n; i++){ //O(n)
        int l = 0, r = i - 1; //O(2)
        pythagoreanTriples_recursive(a, b, l, r, i); //O(logn)
    }
}
// Total complexity:
// T(n) = 1 + 1 + n * 1 + n^2 + n^2 + n * (2 + logn)
// T(n) = O(n^2)