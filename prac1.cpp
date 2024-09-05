#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct unboundedInt{
    int *digit;
    int size;
    int sign;
};

unboundedInt* createUnboundedInt(int sign){
    unboundedInt *num = new unboundedInt;
    num->size = 0;
    num->digit = NULL;
    num->sign = sign;

    return num;
}



int main(){
    unboundedInt *num = NULL;
        
}
