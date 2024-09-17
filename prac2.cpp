#include <bits/stdc++.h>
using namespace std;

int primeCheck(int x)
{
    if (x <= 1)
    {
        return 0;
    }
    else if (x <= 3)
    {
        return 1;
    }
    for (int i = 2; i <= x / 2; i++)
    {
        if (x % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
void getTwoLargestDivisors(int x, int result[2])
{
    for (int i = sqrt(x); i <= x / 2; i++)
    {
        if (x % i == 0)
        {
            result[0] = i;
            result[1] = x / i;
            return;
        }
    }
}
void conquerFactorize(int n)
{
    if (primeCheck(n))
    {
        cout << n;
        return;
    }

    int divisors[2];
    getTwoLargestDivisors(n, divisors);
    int A, B;
    A = divisors[0];
    B = divisors[1];

    // Recursively factorize each divisor
    conquerFactorize(A);
    cout << " * ";
    conquerFactorize(B);
}
int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << n << " = ";
    conquerFactorize(n);
    cout << endl;
    return 0;
}
