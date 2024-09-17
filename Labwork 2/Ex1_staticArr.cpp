/*
    AUTHOR: Do Nguyen Gia Nhu
    ID: 22BA13248
*/

#include <iostream>

using namespace std;
using ll = long long;

const int MAX_DIGIT = 1000;

struct unboundedInt{
    int size;
    int digit[MAX_DIGIT];
};

unboundedInt* init(unboundedInt *num, int sign){
    num = new unboundedInt();
    num->digit[0] = sign;

    for(int i = 1; i < MAX_DIGIT; i++){
        num->digit[i] = -1;
    }

    num->size = 0;
    return num;
}

void addDigit(unboundedInt *num, int digit, int pos){
    if(pos <= 0 || pos > num->size + 1){
        cout << "INVALID POSITION!!! Cannot add!\n";
        return;
    }

    num->size++;
    for(int i = num->size; i > pos; i--){
        num->digit[i] = num->digit[i - 1];
    }
    num->digit[pos] = digit;
}

void removeDigit(unboundedInt *num, int pos){
    if(pos <= 0 || pos > num->size + 1){
        cout << "INVALID POSITION!!! Cannot remove!\n";
        return;
    }

    num->digit[pos] = -1;
    num->size--;
}

int sumOfDigits(unboundedInt *num){
    int sum = 0;

    for(int i = 1; i <= num->size; i++){
        sum += num->digit[i];
    } 
    
    return sum;
}

void display(unboundedInt *num){
    if(num->digit[0] == -1){
        cout << "-";
    }
    for(int i = 1; i < MAX_DIGIT; i++){
        if(num->digit[i] != -1)
            cout << num->digit[i];
    }
    cout << endl;
}


int main(){
    unboundedInt *num = init(num, 1);
    addDigit(num, 2, 1);
    addDigit(num, 3, 1);
    addDigit(num, 4, 2);
    addDigit(num, 5, 3);
    cout << num->size << endl;
    display(num);
    removeDigit(num, 4);
    display(num);
    cout << num->size << endl;
    cout << sumOfDigits(num) << endl;
}