#include <stdio.h>

void bubbleSort(int a[], int n){
    int isSorted = 0;
    
    while(!isSorted){
        isSorted = 1;
        for(int i = 0; i < n - 1; i++){
            if(a[i] > a[i + 1]){
                int tmp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = tmp;

                isSorted = 0;
            }
        }
    }
}

int main(){
    int n; scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    bubbleSort(a, n);
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
}