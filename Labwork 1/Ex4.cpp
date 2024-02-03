#include <stdio.h>
#include <math.h>

int isSphenic(int n){
    int cnt_prime = 0;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            int pow = 0;
            while(n % i == 0){
                pow++;
                cnt_prime++;
                n /= i;
            }
            if(pow > 1) return 0;
        }
    }
    if(n != 1) cnt_prime++;
    
    if(cnt_prime == 3) return 1;
    return 0;
}

int main(){
    printf("Please enter a natural number: ");
    int n; scanf("%d", &n);
    if(isSphenic(n)) printf("%d is an Sphenic number", n);
    else printf("%d is not an Sphenic number", n);
}