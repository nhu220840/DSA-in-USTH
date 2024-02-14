#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *digits;
    int size;
    int sign;
} UnboundedInt;

UnboundedInt* createUnboundedInt(int sign){
    UnboundedInt *num = (UnboundedInt *)malloc(sizeof(UnboundedInt));
    num->size = 0;
    num->digits = NULL;
    num->sign = sign;
    return num;
}

void addDigit(UnboundedInt *num, int digit, int pos){
    if(pos < 0 || pos > num->size + 1){
        printf("Invalid position!\n");
        return;
    }

    num->size++;
    num->digits = (int *)realloc(num->digits, num->size * sizeof(int));

    if(pos == 1){
        for(int i = num->size - 1; i > 0; i--){
            num->digits[i] = num->digits[i - 1];
        }

        num->digits[0] = digit;
    }
    else{
        for(int i = num->size - 1; i > pos - 1; i--){
            num->digits[i] = num->digits[i - 1];
        }

        num->digits[pos - 1] = digit;
    }
}

void removeDigit(UnboundedInt *num, int pos){
    if (pos < 0 || pos >= num->size){
        printf("Invalid position!\n");
        return;
    }

    for(int i = pos; i < num->size - 1; i++){
        num->digits[i] = num->digits[i + 1];
    }

    num->size--;
    num->digits = (int *)realloc(num->digits, num->size * sizeof(int));
}

int sumDigits(UnboundedInt *num){
    int sum = 0;
    for(int i = 0; i < num->size; i++){
        sum += num->digits[i];
    }
    return sum;
}

void display(UnboundedInt *num){
    if(num->sign == -1) printf("-");
    for(int i = 0; i < num->size; i++){
        printf("%d", num->digits[i]);
    }
    printf("\n");
}

int main(){
    UnboundedInt *num = NULL;
    printf("Init the sign of unbounded integer (1 is positive and -1 is negative): ");
    int sign; scanf("%d", &sign);
    num = createUnboundedInt(sign);

    while(1){
        printf("----------------------------------\n");
        printf("1. Add new digit\n");
        printf("2. Remove a digit\n");
        printf("3. Calculate the sum of all digits\n");
        printf("4. Display the whole number\n");
        printf("0. Exit\n");
        printf("----------------------------------\n");

        printf("Enter your choice: ");
        int choice; scanf("%d", &choice);

        if(choice == 1){
            printf("Enter a digit: ");
            int value; scanf("%d", &value);
            printf("Enter the position to add: ");
            int pos; scanf("%d", &pos);
            addDigit(num, value, pos);
        } 
        else if(choice == 2){
            printf("Enter the position to remove: ");
            int pos; scanf("%d", &pos);
            removeDigit(num, pos);
        } 
        else if(choice == 3){
            printf("Sum of all digits is: %d\n", sumDigits(num));
        } 
        else if(choice == 4){
            display(num);
        } 
        else{
            printf("Exit!");
            free(num->digits);
            free(num);
        }
    }
}
