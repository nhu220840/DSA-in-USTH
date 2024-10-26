/*
    AUTHOR: Do Nguyen Gia Nhu
    ID: 22BA13248
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* makeNode(int value){
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    
    return newNode;
}

Node* insertNumberToList(int n) {
    Node* head = nullptr;
    Node* tail = nullptr;
    while (n > 0) {
        int digit = n % 10;
        Node* newNode = makeNode(digit);
        if (!head) {
            head = newNode;
            tail = head;
        } 
        else {
            tail->next = newNode;
            tail = newNode;
        }
        n /= 10;
    }
    return head;
}

void addNumber(Node *&head, int x){
    Node *newNode = makeNode(x);
    if(head == nullptr){
        head = newNode; return;
    }

    Node *tmp = head;
    while(tmp->next != nullptr){
        tmp = tmp->next;
    }
    tmp->next = newNode;
}

void insertNumToList(Node *&head, int n){
    while(n){
        int r = n % 10;
        addNumber(head, r);
    }
}

int countOdd_rec(Node* head) {
    if (!head) return 0;
    return (head->data % 2 != 0) + countOdd_rec(head->next);
}

int countEven_rec(Node* head) {
    if (!head) return 0;
    return (head->data % 2 == 0) + countEven_rec(head->next);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = 3450;
    // Node* head = insertNumberToList(n);
    // cout << countOdd_rec(head) << " " << countEven_rec(head) << endl;
    
}
