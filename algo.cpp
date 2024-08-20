#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
typedef struct Node{
    int data;
    struct Node *next;
} Node;

// Function to create a new node
Node* makeNode(int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void printList(Node *head){
    Node *temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to find the position to insert a new node
Node* findPosition(Node *head, int value){
    Node *current = head;
    Node *prev = NULL;
    while(current != NULL && current->data < value){
        prev = current;
        current = current->next;
    }
    return prev;
}

// Function to perform insertion sort on the linked list
void insertionSort(Node **head){
    Node *sorted = NULL;
    Node *current = *head;
    while(current != NULL){
        Node *next = current->next;
        Node *pos = findPosition(sorted, current->data);
        if (pos == NULL){
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
    int n, value;

    printf("Enter the size of the list: ");
    scanf("%d", &n);

    printf("Enter the values: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &value);
        Node *newNode = makeNode(value);
        newNode->next = head;
        head = newNode;
    }

    printf("The sorted list: ");
    printList(head);
}
