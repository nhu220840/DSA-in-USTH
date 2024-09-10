/*
    AUTHOR: Do Nguyen Gia Nhu
    ID: 22BA13248
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// Pseudocode:
// Input: a positive integer
// Output: an integer after swapping the first and last digits

// Process:
// BEGIN
//     Get num (char array)
//     Set n <- length of num
//     swap(num[0], num[n - 1])
//     print num
// END

int main(){
    cout << "Enter a positive integer: ";
    string s; cin >> s;
    swap(s[0], s[s.length() - 1]);
    cout << "An integer after swapped: " << s;
}