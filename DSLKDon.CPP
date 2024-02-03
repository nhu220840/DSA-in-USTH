#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

struct node{
	int data;
	node *next;// 1 con tro kieu node duoc su dung de luu dia chi cua node tiep theo trong DSLK
};
//ham tra ve 1 con tro kieu node
node* makeNode(int x){
	node *newNode = new node;
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

//ham duyet DSLK
void duyet(node *head){
	while(head != NULL){
		cout << head->data << ' ';
		head = head->next;
	}
	cout << endl;
}

int dem(node *head){
	int ans = 0;
	while(head != NULL){
		++ans;
		head = head->next;
	}
	return ans;
}

void themcuoi(node *&head, int x){
	//tao ra 1 node moi co data la x
	node *newNode = makeNode(x);
	if(head == NULL){
		head = newNode; return;
	}
	//Di den node cuoi cung trong DSLK
	node *tmp = head;
	while(tmp->next != NULL){
		tmp = tmp->next;
	}
	//tmp : node cuoi
	tmp->next = newNode;
}

void themdau(node *&head, int x){
	node *newNode = makeNode(x);
	newNode->next = head;
	head = newNode;
}
//them node vao vi tri thu k trong DSLK
void themgiua(node *&head, int x, int k){
	if(k < 1 || k > dem(head) + 1) return;
	node *newNode = makeNode(x);
	if(k == 1){
		themdau(head, x); return;
	}
	//muon chen vao vi tri k phai den node k - 1
	node *tmp = head; // duyet
	for(int i = 1; i <= k - 2; i++){
		tmp = tmp->next;
	}
	newNode->next = tmp->next;
	tmp->next = newNode;
}

void xoadau(node *&head){
	if(head == NULL) return;
	node *xoa = head;
	head = head->next;
	delete xoa;
}

void xoacuoi(node *&head){
	if(head == NULL) return;
	node *tmp = head;
	if(tmp->next == NULL){
		head = NULL;
		delete tmp; return;
	}
	while(tmp->next->next != NULL){
		tmp = tmp->next;
	}
	node *xoa = tmp->next;
	tmp->next = NULL;
	delete xoa;
}

void xoagiua(node *&head, int k){
	if(k < 1 || k > dem(head)) return;
	node *tmp = head;
	if(k == 1){
		xoadau(head); return;
	}
	for(int i = 1; i <= k - 2; i++){
		tmp = tmp->next;
	}
	node *xoa = tmp->next;
	tmp->next = xoa->next;
	delete xoa;
}

int main(){
	node *head = NULL; 
	for(int i = 1; i <= 5; i++){
		themcuoi(head, i);
	}
	xoagiua(head, 3);
	duyet(head);
	cout << dem(head) << endl;
	return 0;
}

