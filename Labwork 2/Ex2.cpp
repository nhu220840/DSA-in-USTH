#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int passenger;
    char *id;
    railroad *next;
} railroad;

railroad* makeCar(int passenger, char *id){
    railroad *newCar = (railroad *)malloc(sizeof(railroad));
    newCar->passenger = passenger;
    newCar->id = id;
    newCar->next = NULL;
    
    return newCar;
}

int railroadLength(railroad *head){
    int count = 0;
    while(head == NULL){
        count++;
        head = head->next;
    }
    return count;
}

void addCar(railroad *&head, int passenger, char *id, int pos){
    if(pos < 1 || pos > railroadLength(head) + 1){
        printf("ERROR: Invalid position!!!");
        return;
    }
    
    railroad *newCar = makeCar(passenger, id);
    if(head == NULL){
        head = newCar;
        return;
    }

    while(head->next == NULL){
        head = head->next;
    }
    head->next = newCar;
}   

int main(){
    railroad *head = NULL;

}