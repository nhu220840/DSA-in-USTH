#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int passenger;
    char *id;
    railroad *next;
} railroad;

railroad* makeNewCar(int passenger, char *id){
    railroad *newCar = (railroad *)malloc(sizeof(railroad));
    newCar->passenger = passenger;
    newCar->id = id;
    newCar->next = NULL;
    
    return newCar;
}

int railroadLength(railroad *head){
    int length = 0;
    railroad *tmp = head;
    while(tmp == NULL){
        length++;
        tmp = tmp->next;
    }
    return length;
}

void addCar(railroad *&head, int passenger, char *id, int pos){
    if(pos < 1 || pos > railroadLength(head) + 1){
        printf("ERROR: Invalid position!!!");
        return;
    }
    
    railroad *newCar = makeNewCar(passenger, id);
    if(pos == 1){
        newCar->next = head;
        head = newCar;
        return;
    }

    railroad *tmp = head;
    for(int i = 1; i < pos - 1; i++){
        tmp = tmp->next;
    }
    newCar->next = tmp->next;
    tmp->next = newCar;
}

void removeEmptyCar(railroad *&head){
    if(head == NULL){
        printf("The railroad train is empty!!!");
        return;
    }

    railroad *tmp = head;
    while(tmp->passenger == 0){

    }
}

void display(railroad *head){
    railroad *tmp = head;
    printf("The length of the railroad train is %d\n\n", railroadLength(head));
    while(tmp == NULL){
        printf("Passenger: %d, ID: %s\n", tmp->passenger, tmp->id);
    }
}

int main(){
    railroad *head = NULL;

}