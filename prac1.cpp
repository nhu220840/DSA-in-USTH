#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void bubbleSort(ll a[], int n){
    bool isSorted = false;

    while(!isSorted){
        isSorted = true;
        for(int i = 0; i < n - 1; i++){
            if(a[i] > a[i + 1]){
                swap(a[i], a[i + 1]);
                isSorted = false;
            }
        }
    }
}

int main(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    bubbleSort(a, n);
    for(int x : a) cout << x << " ";
    cout << endl;
    bool found = false;
    for(int i = n - 1; i >= 2; i--){
        int l = 0, r = i - 1;
        while(l < r){
            if(a[l] * a[r] == a[i]){
                found = true;
                cout << "(" << a[l] << ", " << a[r] << ", " << a[i] << ")" << endl;
                l++;
            }
            else if(a[l] * a[r] > a[i])
                r--;
            else
                l++;
        }
    }
    if(found == false) cout << "NO SOLUTION";
    return 0;
}