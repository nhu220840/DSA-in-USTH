/*
    AUTHOR: Do Nguyen Gia Nhu
    ID: 22BA13248
*/

#include <iostream>

using namespace std;

void convertIntegralPartToBinary_recursive(float number){
    int integral = (int)number;
    if(integral == 0) return;
    convertIntegralPartToBinary_recursive(integral / 2);
    cout << integral % 2;
}

void convertFractionalPartToBinary_recursive(float number, int skipFirstDigit, int k){
    if(skipFirstDigit != -1) 
        cout << (int)number;
    float fractional = number - (int)number;
    if(fractional == 0 || k == 0) return;
    convertFractionalPartToBinary_recursive(fractional * 2, 0, k - 1);
}

void convertRealNumberToBinary_recursive(float number, int skipFirstDigit, int k){
    convertIntegralPartToBinary_recursive(number);
    cout << ".";
    convertFractionalPartToBinary_recursive(number, -1, k);
}

int main(){
    float input = 4.47;
    convertRealNumberToBinary_recursive(input, -1, 4);
}