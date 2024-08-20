#include <stdio.h>
#include <math.h>

//Pseudocode
// def isSphenic(n):
//     Set cnt_prime = 0
//     for i <- 2 to sqrt(n) do:
//         if n % i == 0:
//             Set pow = 0
//             while n % i == 0 do:
//                 pow = pow + 1
//                 cnt_prime = cnt_prime + 1
//                 n = n / i
//             endwhile
//             if pow > 1: return False
//     endfor
//     if n != 1: cnt_prime = cnt_prime + 1
    
//     if cnt_prime == 3: return True
//     return False

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

    return cnt_prime == 3;
}

int main(){
    printf("Please enter a natural number: ");
    int n; scanf("%d", &n);
    if(isSphenic(n)) 
        printf("%d is a Sphenic number", n);
    else 
        printf("%d is not a Sphenic number", n);
}