#include <stdio.h>
#include <string.h>

void swappedNumber(char num[], int n){
    char tmp = num[0];
    num[0] = num[n - 1];
    num[n - 1] = tmp;
}

int main(){
    printf("Please enter an integer: ");
    char num[100];
    scanf("%s", num);
    int length = strlen(num);
    swappedNumber(num, length);
    printf("An integer after swapped: %s\n", num);
}
