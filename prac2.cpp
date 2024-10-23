#include <iostream>
#include <cmath>
using namespace std;

double ln2_rec(int n, int maxTerms) {
    if (n >= maxTerms) return 0.0;

    double term;
    if (n == 1) {
        term = 1.0 / 2.0;
    } else {
        term = (n % 2 == 0 ? -1.0 : 1.0) / ((n - 1) * n);
    }

    return term + ln2_rec(n + 1, maxTerms);
}

double calculate(int n){
    if(n == 0) return 0.5;
    int sum;
    if(n % 2 == 0){
        sum = pow(-1, n) / ((n - 1) * n) + calculate(n - 1);
    }
    else sum = pow(1, n + 1) / (n * (n + 1)) + calculate(n - 1);
    sum += 0.5;
    return sum;
}

double ln2_iteration(int n){
    double sum = 0.5;
    for(int i = 1; i <= n; i++){
        sum += pow(-1, n) / (n * (n + 1));
    }
    return sum;
}

int main() {
    double ln2_approx = calculate(100);
    cout << ln2_iteration(10);

    // Output the result
    // cout << "Approximation of ln(2) with n = 10 terms: " << ln2_approx << endl;

}
