#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct unboundedInt{
    int sign, digit;
    unboundedInt *next;
} unboundedInt;

unboundedInt* makeDigit(int num){
    unboundedInt *newNode = (unboundedInt *)malloc(sizeof(unboundedInt));
    newNode->digit = num;
    newNode->next = NULL;
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

void removemDigit(unboundedInt *&head, int num, int pos){
    if(pos < 1 || pos > countDigit(head) || head == NULL) return;
    unboundedInt *tmp = head;
    if(pos == 1){
        unboundedInt *del = head;
        head = head->next;
        delete del;
        return;
    }
    for(int i = 1; i <= pos - 2; i++){
        tmp = tmp->next;
    }
    unboundedInt *del = tmp->next;
    tmp->next = del->next;
    delete del;
}



int main(){
    unboundedInt *head = NULL;
    
}