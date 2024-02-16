#include <stdio.h>
#include <stdlib.h>

typedef struct unboundedInt{
    int digit;
    unboundedInt *next;
} unboundedInt;

unboundedInt* makeDigit(int num){
    unboundedInt *newNode = (unboundedInt *)malloc(sizeof(unboundedInt));
    newNode->digit = num;
    newNode->next = NULL;
    return newNode;
}

int countDigit(unboundedInt *head){
    int res = 0;
    while(head != NULL){
        res++;
        head = head->next;
    }
    return res;
}

void initSign(unboundedInt *&head, int num){
    if(head == NULL) 
        head = makeDigit(num);
    else{
        unboundedInt *newNode = makeDigit(num);
        newNode->next = head;
        head = newNode;
    }
}

void addDigit(unboundedInt *&head, int num, int pos){
    if(head == NULL){
        printf("ERROR: List is empty!\n");
        return;
    }
    if(pos < 1 || pos > countDigit(head) + 1){
        printf("ERROR: The position is out of bound!\n");
        return;
    }
    unboundedInt *newNode = makeDigit(num);
    if(pos == 1){
        newNode->next = head->next; //bo qua phan tu dau tien do phan tu dau tien bieu thi dau
        head->next = newNode;
    }
    else{
        unboundedInt *tmp = head->next;
        for(int i = 1; i <= pos - 2; i++){
            tmp = tmp->next;
        }
        newNode->next = tmp->next;
        tmp->next = newNode;
    }
    printf("Added successfully!\n");
}

void removeDigit(unboundedInt *&head, int pos){
    if(head == NULL){
        printf("ERROR: List is empty!\n");
        return;
    }
    if(pos < 1 || pos > countDigit(head)){
        printf("ERROR: The position is out of bound!\n");
        return;
    }
    if(pos == 1){
        unboundedInt *del = head; //luu lai node dau tien vao bien del
        head = head->next; //cho head = node thu 2 trong dslk
        free(del); //giai phong node dau tien
        return;
    }
    unboundedInt *tmp = head->next; //bo qua phan tu dau tien vi no luu dau 
    for(int i = 1; i <= pos - 2; i++){
        tmp = tmp->next; //duyet den vi tri truoc node can xoa 
    }
    unboundedInt *del = tmp->next; //luu lai node can xoa vao bien del
    tmp->next = del->next; //noi 2 node lai voi nhau bo qua node o giua
    
    //gia su co 3 node: 1 2 3 4, can xoa di node 3
    //vong for se duyet den node 2
    //cau lenh dong 55 bieu thi lay dia chi cua node 3 gan cho bien tmp
    //cau lenh dong 56 bieu thi cho node 2 tro vao node 4
    //tmp->next la phan can luu dia chi cua node tiep theo (node hien tai la node 2)
    //del->next la dia chi cua node 4 (node hien tai la node 3)
    free(del); //giai phong node del
    printf("Deleted successfully!\n");
}

int sumDigits(unboundedInt *head){
    int sum = 0;
    unboundedInt *tmp = head->next; //bo qua phan tu dau tien vi no la dau
    while(tmp != NULL){
        sum += tmp->digit;
        tmp = tmp->next;
    }
    return sum;
}

void display(unboundedInt *head){
    unboundedInt *tmp = head->next; //bo qua phan tu dau tien
    if(head->digit == -1) printf("-");
    while(tmp != NULL){
        printf("%d", tmp->digit);
        tmp = tmp->next;
    }
    printf("\n");
}


int main(){
    unboundedInt *head = NULL;
    printf("Init the sign of unbounded integer (1 is positive and -1 is negative): ");
    int sign; scanf("%d", &sign);
    if(sign < 0) 
        initSign(head, -1);
    else 
        initSign(head, 1);
    while(true){
        printf("---------------------------------\n");
        printf("1. Add new digit\n");
        printf("2. Remove a digit\n");
        printf("3. Calculate the sum of all digits\n");
        printf("4. Display the whole number\n");
        printf("0. Exit\n");
        printf("---------------------------------\n");
        
        printf("Enter your choice: ");
        int choice; scanf("%d", &choice);
        if(choice == 1){
            printf("Enter a digit: ");
            int value; scanf("%d", &value);
            printf("Enter the position to add: ");
            int pos; scanf("%d", &pos);
            addDigit(head, value, pos);
        }
        else if(choice == 2){
            printf("Enter the position to remove: ");
            int pos; scanf("%d", &pos);
            removeDigit(head, pos);
        }
        else if(choice == 3){
            printf("Sum of all digits is: %d\n", sumDigits(head));
        }
        else if(choice == 4){
            display(head);
        }
        else{
            printf("Exit!");
            return 0;
        }
    }
    return 0;
}