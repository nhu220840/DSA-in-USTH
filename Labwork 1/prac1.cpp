#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cout << "Enter a positive interger: ";
    string s; cin >> s;
    swap(s[0], s[s.length() - 1]);
    cout << "An integer after swapped: " << s;
}