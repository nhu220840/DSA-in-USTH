#include <stdio.h>

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
    if(found == 1) return pos;
    return n;
}

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void printArray(int a[], int n){
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}

void insertionSortOptimize(int a[], int n){
	for(int i = 1; i < n; i++){
		int value = a[i];
		int pos = findPosition(a, i, value);
		if(pos != i){  
			for(int j = i; j > pos; j--){  
				a[j] = a[j-1];
			}
			a[pos] = value;  
		}
		printArray(a, n);
	}
}

int main(){
    int n; scanf("%d", &n); 
    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
	insertionSortOptimize(a, n);
}