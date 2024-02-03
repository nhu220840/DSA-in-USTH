#include <stdio.h>

void findMax(int *max, int a){
    if(a > *max)
        *max = a; 
}

int main(){
    printf("Please enter the size of the array: ");
    int size; scanf("%d", &size);
    printf("Enter all numbers in the array: ");
    int a[size];
    for(int i = 0; i < size; i++){
        scanf("%d", &a[i]);
    }
    
    int max = a[0];
    for(int i = 1; i < size; i++){
        findMax(&max, a[i]);
    }
    printf("The maximum number is: %d", max);
}