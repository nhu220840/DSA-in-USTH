#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void findMax(int *max, int a){
    if(a > *max) *max = a;
}

int main(){
    cout << "Enter the size of an array: ";
    int n; cin >> n;
    cout << "Enter the value of each element in array: ";
    int a[n];
    for(int &x : a) cin >> x;
    int max_ele = INT_MIN;
    for(int i = 0; i < n; i++){
        findMax(&max_ele, a[i]);
    }
    cout << "Max element of array is: " << max_ele;
}