/*
    AUTHOR: Do Nguyen Gia Nhu
    ID: 22BA13248
*/

#include <iostream>

using namespace std;
using ll = long long;

struct railroad{
    int maxCapacity;
    int passengers;
    char *id;
    railroad *next;
};

railroad* makeNewCar(int maxCapacity, int passengers, char *id){
    railroad *newCar = new railroad();

    newCar->maxCapacity = maxCapacity;
    newCar->passengers = passengers;
    newCar->id = id;
    newCar->next = NULL;

    return newCar;
}

int getRailroadLength(railroad *head){
    int cnt = 0;

    railroad *tmp = head;
    while(tmp != NULL){
        cnt++;
        tmp = tmp->next;
    }

    return cnt;
}

void addNewCars(railroad *head, int maxCapacity, int passengers, char *id){
    railroad *newCar = makeNewCar(maxCapacity, passengers, id);

    if(newCar->maxCapacity < newCar->passengers){
        cout << "The car is overloaded!!!" << endl;
        cout << "Cannot add to the railroad!!!" << endl;
    }

    if(head == NULL){
        head = newCar;
        return;
    }
    
}

int main(){
    railroad *head = NULL;
}