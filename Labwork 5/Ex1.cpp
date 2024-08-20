#include <stdio.h>

//That means we will find the first position of the element such that it is greater or equal to v
//Then we just need to decrease the index by 1
int findPosition(int a[], int n, int v){
    int pos = -1, found = 0; 
    int left = 0, right = n - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(a[mid] >= v){
            pos = mid;
            found = 1;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    if(found == 1) return pos + 1;
    return n + 1;
}

int main(){
    printf("Enter the size of the array: ");
    int n; scanf("%d", &n);
    int a[n];
    printf("Enter the value of each number in the array: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    printf("Enter a new value v you want to add into this array: ");
    int v; scanf("%d", &v);
    printf("%d", findPosition(a, n, v));
}