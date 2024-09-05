#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct complexNumber{
    int real, imaginary;

    void enter(){
        cin >> this->real >> this->imaginary;
    }

    void print(){
        cout << this->real << " + " << this->imaginary << "i" << endl;
    }
};

complexNumber add(complexNumber a, complexNumber b){
    complexNumber res;
    res.real = a.real + b.real;
    res.imaginary = a.imaginary + b.imaginary;
    
    return res;
}

complexNumber multiply(complexNumber a, complexNumber b){
    complexNumber res;
    res.real = a.real * b.real - a.imaginary * b.imaginary;
    res.imaginary = (a.real * b.imaginary + a.imaginary * b.real);

    return res;
}


int main(){
    complexNumber a, b;
    cout << "Please enter components (real and virtual) of first complex number: ";
    a.enter();
    cout << "Please enter components (real and virtual) of second complex number: ";
    b.enter();

    complexNumber sum = add(a, b);
    complexNumber product = multiply(a, b);

    cout << "Sum of a and b is: ";
    sum.print();
    cout << "Product of a and b is: ";
    product.print();

}