/*
    AUTHOR: Do Nguyen Gia Nhu
    ID: 22BA13248
*/

#include <iostream>

using namespace std;

void convertIntegralPartToBinary(float number){
    int tmp = (int)number;

    int remainder[100];
    int cnt = 0;
    while(tmp){
        remainder[cnt] = (int)tmp % 2;
        cnt++;
        tmp /= 2;
    }
    for(int i = cnt - 1; i >= 0; i--){
        cout << remainder[i];
    }
}

void convertFractionalPartToBinary(float number, int k){
    float fractional = number - (int)number;
    
    int remainder[100];
    int cnt = 0;
    while(fractional){
        fractional *= 2;
        remainder[cnt] = (int)fractional;
        fractional -= (int)fractional;
        cnt++;
    }
    for(int i = 0; i < k; i++){
        cout << remainder[i];
    }
}

void convertRealNumberToBinary(float number, int k){
    convertIntegralPartToBinary(number);
    cout << ".";
    convertFractionalPartToBinary(number, k);
}

int main(){
    float input = 4.47;
    convertRealNumberToBinary(input, 4);
}