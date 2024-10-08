#include <stdio.h>

int isPalindrome(int a[], int start, int end){
    if(start >= end) return 1; //T(n) = 1
    if(a[start] != a[end]) return 0; //T(n) = 1
    return isPalindrome(a, start + 1, end - 1); //T(n) = 3 + T(n / 2)
}

//Complexity:
//T(n) = 1 + 1 + 3 + T(n / 2) 
//T(n) = O(n)

int main(){
    printf("Enter the size of the array: ");
    int n; scanf("%d", &n);
    int a[n];
    printf("Enter the value of each number in the array: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    if(isPalindrome(a, 0, n - 1))
        printf("The array is a palindrome array\n");
    else printf("The array is NOT a palindrome array\n");
}