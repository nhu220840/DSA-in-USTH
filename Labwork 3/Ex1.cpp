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

void addProduct(Product *&head, char *name, int quantity, int price){
    Product *newProduct = (Product *)malloc(sizeof(Product));

    if(head == NULL){
        head = newProduct;
        return;
    }

    Product *tmp = head;
    while(tmp->next == NULL){
        tmp = tmp->next;
    }
    tmp->next = newProduct;
    newProduct->prev = tmp;
}

// void removeProduct(Product *&head, char *name){

// }

// int validProductName(Product *head, char *name){
//     Product *tmp = head;
//     while(tmp != NULL){
//         if(tmp->name == name){
//             return 1;
//         }
//         tmp = tmp->next;
//     }
//     return 0;
// }

int validProductQuantity(Product *head, char *name, int quantity){
    Product *tmp = head;
    
    while(tmp != NULL){
        if(tmp->name){
            if(tmp->quantity >= quantity) return 1;
            else return 0;
        }
        tmp = tmp->next;
    }
    return 0;
}

int getProductQuantity(Product *head, char *name){
    Product *tmp = head;

    while(tmp != NULL){
        if(tmp->name == name){
            return tmp->quantity;
        }
        tmp = tmp->next;
    }
    return 0;
}

void reStock(Product *&head, char *name, int quantity, int price){
    //The product is already in the stock, add more quantity
    if(getProductQuantity(head, name) != 0){
        Product *tmp = head;
        while(tmp != NULL){
            if(tmp->name == name){
                tmp->quantity += quantity;
                break;
            }
            tmp = tmp->next;
        }
    }
    else{
        //Add new product if it is not in the stock
        addProduct(head, name, quantity, price);
    }
}

int main(){
    Product *head = NULL;
}