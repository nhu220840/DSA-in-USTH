#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning of the linked list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to print the linked list
void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Function to insert a new node in sorted order
void sortedInsert(struct Node** head_ref, struct Node* new_node) {
    struct Node* current;
    if (*head_ref == NULL || (*head_ref)->data >= new_node->data) {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else {
        current = *head_ref;
        while (current->next != NULL && current->next->data < new_node->data) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

// Function to sort the linked list using insertion sort
void insertionSort(struct Node **head_ref) {
    struct Node *sorted = NULL; // Initialize a sorted list
    struct Node *current = *head_ref; // Traverse the given linked list
    while (current != NULL) {
        struct Node *next = current->next; // Store next for next iteration
        sortedInsert(&sorted, current);
        current = next;
    }
    *head_ref = sorted;
}

int main() {
    struct Node* a = NULL;

    // Inserting elements into the linked list
    push(&a, 5);
    push(&a, 20);
    push(&a, 4);
    push(&a, 3);
    push(&a, 30);

    printf("Linked list before sorting:\n");
    printList(a);

    // Sorting the linked list using insertion sort
    insertionSort(&a);

    printf("Linked list after sorting:\n");
    printList(a);

    return 0;
}
