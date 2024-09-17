/*
    AUTHOR: Do Nguyen Gia Nhu
    ID: 22BA13248
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct railroad{
    int maximumCapacity;
    int numberOfPassengers;
    char *id;
    railroad *next;
    railroad *prev;
} railroad;

railroad* makeNewCar(int maximumCapacity, int passenger, char *id){
    railroad *newCar = (railroad *)malloc(sizeof(railroad));
    newCar->maximumCapacity = maximumCapacity;
    newCar->numberOfPassengers = passenger;
    newCar->id = id;
    newCar->next = NULL;
    newCar->prev = NULL;
    
    return newCar;
}

int getRailroadLength(railroad *head){
    int length = 0;
    while(head != NULL){
        length++;
        head = head->next;
    }
    return length;
}

void addCar(railroad *&head, int maximumCapacity, int passenger, char *id /*, int pos*/){
    // if(pos < 1 || pos > railroadLength(head) + 1){
    //     printf("ERROR: Invalid position!!!");
    //     return;
    // }
    
    railroad *newCar = makeNewCar(maximumCapacity ,passenger, id);
    if(newCar->maximumCapacity < newCar->numberOfPassengers){
        printf("The car is overloaded!!!\n");
        printf("Cannot add to the railroad!!!\n");
        return;
    }
    if(head == NULL){
        head = newCar;
        return;
    }
    // if(pos == 1){
    //     newCar->next = head;
    //     head = newCar;
    //     return;
    // }

    // for(int i = 1; i < pos - 1; i++){
    //     tmp = tmp->next;
    // }
    // newCar->next = tmp->next;
    // tmp->next = newCar;

    railroad *tmp = head;

    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = newCar;
    newCar->prev = tmp;
}

void removeEmptyCars(railroad *&head){
    if(head == NULL){
        printf("The railroad train is empty!!!\n");
        return;
    }

    railroad *tmp = head;

    while(tmp != NULL){
        if(tmp->numberOfPassengers == 0){
            // Xac dinh node tiep theo truoc khi xoa
            railroad *nextNode = tmp->next;

            // Xoa tmp 
            if(tmp->prev == NULL){
                // tmp la node dau tien
                head = nextNode;
                if(nextNode != NULL)
                    nextNode->prev = NULL;
                free(tmp);
            } 
            else{
                // tmp ko phai la node dau tien
                tmp->prev->next = nextNode;
                if(nextNode != NULL)
                    nextNode->prev = tmp->prev;
                free(tmp);
            }

            // di chuyen tmp den node tiep theo
            tmp = nextNode; //tmp = tmp->next;
        }
        else
            tmp = tmp->next; // di chuyen tmp den node tiep theo
    }

    printf("Removed successfully!!!\n");
}

void displayCars(railroad *head){
    railroad *tmp = head;
    if(getRailroadLength(head) == 0){
        printf("The railroad train is empty!!!\n");
    }
    else{
        printf("The length of the railroad train is %d\n", getRailroadLength(head));
        while(tmp != NULL){
            printf("Maximum capacity: %d, Passenger(s): %d, Car's ID: %s\n",tmp->maximumCapacity, tmp->numberOfPassengers, tmp->id);
            tmp = tmp->next;
        }
    }
}

int main(){
    railroad *head = NULL;
    printf("Enter the number of cars of railroad train: ");
    int cars; scanf("%d", &cars);
    if(cars != 0){
        printf("Enter the passenger(s) and ID of each cars:\n");
        for(int i = 1; i <= cars; i++){
            printf("Information of car %d:\n", i);
            printf("The maximum capacity of car %d is: ", i);
            int maximumCapacity; scanf("%d", &maximumCapacity);
            printf("The number of passenger(s): ");
            int passenger; scanf("%d", &passenger);
            char *id =(char *)malloc(sizeof(char) * 100);
            printf("ID of car: ");
            scanf("%s", id);
            addCar(head, maximumCapacity, passenger, id);
        }
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
            printf("The maximum capacity of car is: ");
            int maximumCapacity; scanf("%d", &maximumCapacity);
            printf("The number of passenger(s): ");
            int passenger; scanf("%d", &passenger);
            printf("ID of car: ");
            char *id = (char *)malloc(sizeof(char));
            scanf("%s", id);
            addCar(head, maximumCapacity, passenger, id);
        }
        else if(choice == 2){
            removeEmptyCars(head);
        }
        else if(choice == 3){
            displayCars(head);
        }
        else if(choice == 0){
            printf("Exit!!!");
            return 0;
        }
        else{
            printf("Your choice is not invalid!!!\n");
            printf("Please enter again\n");
        }
    }
    return 0;
}
    