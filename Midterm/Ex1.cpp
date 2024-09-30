/*
    AUTHOR: Do Nguyen Gia Nhu
    ID: 22BA13248
*/

#include <iostream>
#include <cmath>

using namespace std;

// Pseudocode:

// def bubbleSort(a, n):
//     for i <- 0 to n - 2 do:
//         for j <- i + 1 to n - 1 do:
//             if a[i] > a[j]:
//                 tmp = a[i]
//                 a[i] = a[j]
//                 a[j] = tmp
//         endfor
//     endfor

// def pythagoreanTriples(a, b, n):
//     for i <- 0 to n - 1 do:
//         l = 0, r = i - 1
//         while l < r do:
//             if b[l] + b[r] == b[i]:
//                 print a[l], a[r], a[i]
//                 l++
//                 r--
//             elif b[l] + b[r] < b[i]:
//                 l++
//             else r--
//         endwhile
//     endfor

// main:
//     Create array a[] = {3, 4, 5, 6, 10, 2, 8, 9, 7}
//     n = size(a)
//     Create b[n]
//     for i <- 0 to n - 1 do:
//         b[i] = a[i] * a[i]
//     endfor
//     bubbleSort(a, n)
//     bubbleSort(b, n)
//     pythagoreanTriples(a, b, n)

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

void pythagoreanTriples(int a[], int b[], int n){
    for(int i = 0; i < n; i++){ //O(n)
        int l = 0, r = i - 1; //O(2)
        while(l < r){ //O(logn)
            if(b[l] + b[r] == b[i]){ //O(1)
                cout << "(" << a[l] << ", " << a[r] << ", " << a[i] << ")" << endl; //O(1)
                l++; r--; //O(2)
            }
            else if(b[l] + b[r] < b[i]) //O(1)
                l++; //O(1)
            else 
                r--; //O(1)
        }
    }
}
// Complexity of pythagoreanTriples:
// T(n) = n * (2 + logn (1 + 1 + 2 + 1 + 1 + 1)) 
// T(n) = O(nlogn)

int main(){
    int a[] = {3, 4, 5, 6, 10, 2, 8, 9, 1, 7}; //O(1)
    int n = sizeof(a) / sizeof(a[0]); //O(1)
    int b[n]; //O(1)
    for(int i = 0; i < n; i++){ //O(n)
        b[i] = a[i] * a[i]; //O(2)
    }
    bubbleSort(b, n); //O(n^2)
    bubbleSort(a, n); //O(n^2)
    pythagoreanTriples(a, b, n); //O(nlogn);
}

// Total complexity:
// T(n) = 1 + 1 + 1 + n * 2 + n^2 + n^2 + nlogn
// T(n) = O(n^2)