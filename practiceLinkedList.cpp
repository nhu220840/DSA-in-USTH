#include <stdio.h>
#include <stdlib.h>

typedef struct Ipad{
    char ID[100], name[100], manufacturer[100];
    int yearOfProduct, price; 
    Ipad *next;
} Ipad;

Ipad* makeProduct(Ipad *head, char ID[100], char name[100], char manufacturer[100], int yearOfProduct, int price){
    
}

int main(){
    Ipad *head = NULL;

    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++){
        char *ID = (char *)malloc(100 * sizeof(char));
    }
}