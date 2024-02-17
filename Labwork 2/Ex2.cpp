#include <stdio.h>
#include <stdlib.h>

typedef struct railroad{
    int passenger;
    char *id;
    railroad *next;
    railroad *prev;
} railroad;

railroad* makeNewCar(int passenger, char *id){
    railroad *newCar = (railroad *)malloc(sizeof(railroad));
    newCar->passenger = passenger;
    newCar->id = id;
    newCar->next = NULL;
    newCar->prev = NULL;
    
    return newCar;
}

int railroadLength(railroad *head){
    int length = 0;
    railroad *tmp = head;
    while(tmp != NULL){
        length++;
        tmp = tmp->next;
    }
    return length;
}

void addCar(railroad *&head, int passenger, char *id /*, int pos*/){
    // if(pos < 1 || pos > railroadLength(head) + 1){
    //     printf("ERROR: Invalid position!!!");
    //     return;
    // }
    
    railroad *newCar = makeNewCar(passenger, id);
    if(head == NULL){
        head = newCar;
        return;
    }
    // if(pos == 1){
    //     newCar->next = head;
    //     head = newCar;
    //     return;
    // }

    railroad *tmp = head;
    // for(int i = 1; i < pos - 1; i++){
    //     tmp = tmp->next;
    // }
    // newCar->next = tmp->next;
    // tmp->next = newCar;

    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = newCar;
    newCar->prev = tmp;
}

void removeEmptyCars(railroad *&head){
    if(head == NULL){
        printf("The railroad train is empty!!!");
        return;
    }

    railroad *tmp = head;
    while(tmp != NULL){
        if(tmp->passenger == 0){
            if(tmp->prev == NULL){
                head = head->next;
                free(tmp);
                head->prev = NULL;
                tmp = head;
            }
            else{
                railroad *del = tmp;
                del->prev->next = tmp->next;
                free(del);
                tmp = tmp->next;
            }
        }
        else{
            tmp->prev = tmp;
            tmp = tmp->next;
        }
    }
}

void displayCars(railroad *head){
    railroad *tmp = head;
    printf("The length of the railroad train is %d\n", railroadLength(head));
    while(tmp != NULL){
        printf("Passenger: %d, ID: %s\n", tmp->passenger, tmp->id);
        tmp = tmp->next;
    }
}

int main(){
    railroad *head = NULL;
    printf("Enter the number of cars of railroad train: ");
    int cars; scanf("%d", &cars);
    printf("Enter the passenger(s) and ID of each cars:\n");
    for(int i = 1; i <= cars; i++){
        printf("Information of car %d: ", i);
        int passenger;
        char *id =(char *)malloc(sizeof(char) * 100);
        scanf("%d %s", &passenger, id);
        addCar(head, passenger, id);
    }
    
    while(1){
        printf("-----------------------------------------------\n");
        printf("1. Add more car to the railroad train\n");
        printf("2. Remove all empty cars in the railroad train\n");
        printf("3. Display all cars of the railroad train\n");
        printf("0. Exit\n");
        printf("-----------------------------------------------\n");

        printf("Enter your choice: ");
        int choice; scanf("%d", &choice);

        if(choice == 1){
            printf("Enter the information of car:\n");
            printf("The number of passenger(s): ");
            int passenger; scanf("%d", &passenger);
            printf("ID of car: ");
            char *id =(char *)malloc(sizeof(char));
            scanf("%s", id);
            addCar(head, passenger, id);
        }
        else if(choice == 2){
            removeEmptyCars(head);
            printf("Removed successfully!!!\n");
        }
        else if(choice == 3){
            displayCars(head);
        }
        else{
            printf("Exit!!!");
            return 0;
        }
    }
    return 0;
    // printf("Do you want to remove all empty cars? (Y/N)\n");
    // char choice; scanf("%c", &choice);
    // if(choice == 'Y'){
        
    // }
    // printf("The state of railroad train is:\n");
    // displayCars(head);
    // printf("Do you want to add more car to the railroad train? (Y/N)\n");
    // scanf("%c", &choice);
    // if(choice == 'Y'){
        
    // }
}
    