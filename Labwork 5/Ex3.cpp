#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;

Node* makeNode(int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(Node *head){
    Node *temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

Node* findPosition(Node *head, int value){
    Node *current = head;
    Node *prev = NULL;
    while(current != NULL && current->data < value){
        prev = current;
        current = current->next;
    }
    return prev;
}

void insertionSort(Node **head){
    Node *sorted = NULL;
    Node *current = *head;
    while(current != NULL){
        Node *next = current->next;
        Node *pos = findPosition(sorted, current->data);
        if(pos == NULL){
            current->next = sorted;
            sorted = current;
        } 
        else{
            current->next = pos->next;
            pos->next = current;
        }
        current = next;
    }
    *head = sorted;
}

int main(){
    Node *head = NULL;
    printf("Enter the size of the list: ");
    int n; scanf("%d", &n);

    printf("Enter the values: ");
    for(int i = 0; i < n; i++){
        int value; scanf("%d", &value);
        Node *newNode = makeNode(value);
        newNode->next = head;
        head = newNode;
    }

    printf("The sorted list: ");
    printList(head);
}
