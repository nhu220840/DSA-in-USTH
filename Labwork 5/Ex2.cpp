#include <stdio.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void insertionSortOptimize(int a[], int n){
    int swapped = 1;
    int start = 0, end = n - 1;
    while(swapped){
        swapped = 0;
        for(int i = start + 1; i <= end; i++){
            int pos = i - 1, value = a[i];
            while(pos >= 0 && a[pos] > value){
                a[pos + 1] = a[pos];
                pos--;
                swapped = 1;
            }
            a[pos + 1] = value;
        }

        if(!swapped) break;

        end--;

        for(int i = end - 1; i >= start; i--){
            int pos = i + 1, value = a[i];
            while(pos >= 0 && a[pos] < value){
                
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
}