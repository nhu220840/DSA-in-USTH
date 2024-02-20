#include <stdio.h>
#include <stdlib.h>

typedef struct Product{
    char *name;
    int quantity;
    int price;
    Product *next;
    Product *prev;
} Product;

Product *makeProduct(char *name, int quantity, int price){
    Product *newProduct = (Product *)malloc(sizeof(Product));
    newProduct->name = name;
    newProduct->quantity = quantity;
    newProduct->price = price;
    newProduct->next = newProduct->prev = NULL;

    return newProduct;
}

void addProduct(Product *head, char *name, int quantity, int price){
    Product *newProduct = (Product *)malloc(sizeof(Product));

    if(head == NULL){
        head = newProduct;
        return;
    }
    
}

int main(){
    Product *head = NULL;
}