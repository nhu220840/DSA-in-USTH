#include <stdio.h>
#include <string.h>

// Pseudocode:
// Input: a positive integer
// Output: an integer after swapping the first and last digits

// Process:
// BEGIN
//     Get num (char array)
//     Set n <- length of num
//     swap(num[0], num[n - 1])
//     print num
// END

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
