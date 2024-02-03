#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct unboundedInt{
    int sign, digit;
    unboundedInt *next;
} unboundedInt;

unboundedInt* makeDigit(int num){
    unboundedInt *newNode = new unboundedInt;
    newNode->digit = num;
    return newNode;
}

int countDigit(unboundedInt *head){
    int res = 0;
    while(head != NULL){
        res++;
        head = head->next;
    }
    return res;
}

void addDigit(unboundedInt *&head, int num, int pos){
    if(pos < 1 || pos > countDigit(head) + 1) return;
    unboundedInt *newNode = makeDigit(num);
    if(pos == 1){
        newNode->next = head;
        head = newNode;
        return;
    }
    unboundedInt *tmp = head;
    for(int i = 1; i <= pos - 2; i++){
        tmp = tmp->next;
    }
    newNode->next = tmp->next;
    tmp->next = newNode;
}

void rmDigit(unboundedInt *&head, int num, int pos){
    if(pos < 1 || pos > countDigit(head) + 1) return;
    unboundedInt *tmp = head;
    if(pos == 1){

    }
}

int main(){
    unboundedInt *head = NULL;

}