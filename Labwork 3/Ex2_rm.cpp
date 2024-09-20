/*
    AUTHOR: Do Nguyen Gia Nhu
    ID: 22BA13248
*/

#include <iostream>

using namespace std;
using ll = long long;

const int MAX_SIZE = 100;

struct Website {
    string url;
    string title;
};

struct Stack {
    Website web[MAX_SIZE];
    int top;
};

Website makeWebsite(string url, string title){
    Website newWebsite;
    newWebsite.url = url;
    newWebsite.title = title;

    return newWebsite;
}

Stack* init(Stack *st){
    st = new Stack;
    st->top = -1;
    return st;
}

int isEmpty(Stack st){
    return st.top < 0; 
}

int size(Stack st){
    return st.top + 1;
}

void push(Stack *st, Website newWeb){
    if(st->top == MAX_SIZE - 1){
        cout << "Stack is full!!!" << endl;
    }
    else{
        st->top++;
        st->web[st->top] = newWeb;
    }
}

void pop(Stack *st){
    if(isEmpty(*st)){
        cout << "Stack empty!!!" << endl;
    }
    else{
        st->top--;
    }
}

void clearStack(Stack *st){
    while(!isEmpty(*st)){
        pop(st);
    }
}

void visitWebsite(Stack *back){

}

int main(){
    
}