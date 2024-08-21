#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

//them vao cuoi ds
void addProduct(Product *&head, char *name, int quantity, int price){
    Product *newProduct = makeProduct(name, quantity, price);

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
//     if(head == NULL) return;
//     else{
//         Product *tmp = head;
//         //Node dau
//         Product *prod_remove = head;
//         if(prod_remove->name == name){
//             head = head->next;
//             if(head != NULL){
//                 head->prev = NULL;
//             }
//             free(prod_remove);
//         }
//         int found = 0, cnt = 0;
//         while(tmp->next != NULL){
//             if(tmp->next->name == name){
//                 cnt++;
//                 found = 1;
//                 break;
//             }
//             else{
//                 cnt++;
//                 tmp = tmp->next;
//             }
//         }
//         if(!found) printf("Product is not in storage.\n");

//         else if(prod_remove->next == NULL){
//             head = NULL;
//             free(prod_remove);
//             return;
//         }
//     }

// }

void removeProduct(Product *&head, char *name){
    if(head == NULL){
        printf("List is empty.\n");
        return;
    }

    Product *tmp = head;

    // Xoa dau ds
    if(strcmp(head->name, name) == 0){
        Product *prod_remove = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(prod_remove->name);
        free(prod_remove);
        printf("Product %s removed from the beginning.\n", name);
        return;
    }

    // Duyệt qua danh sách để tìm sản phẩm cần xóa
    while(tmp->next != NULL){
        if (strcmp(tmp->next->name, name) == 0) {
            break;
        }
        tmp = tmp->next;
    }

    // Trường hợp 2: Không tìm thấy sản phẩm cần xóa
    if(tmp->next == NULL){
        printf("Product %s is not in storage.\n", name);
        return;
    }

    // Trường hợp 3: Xóa giữa danh sách
    Product *prod_remove = tmp->next;
    tmp->next = prod_remove->next;
    if(prod_remove->next != NULL){
        prod_remove->next->prev = tmp;
        printf("Product %s removed from the middle.\n", name);
    } 
    else{
        // Trường hợp 4: Xóa cuối danh sách
        printf("Product %s removed from the end.\n", name);
    }

    free(prod_remove->name);
    free(prod_remove);
}

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

void resizeStorage(Product *&head, char *name, int quantity, int price){
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

typedef struct Customer{
    char *name;
    char *productName;
    int productQuantity;
    Customer *next;
} Customer;

Customer *makeCustomer(char *name, char *productName, int productQuantity){
    Customer *newCustomer = makeCustomer(name, productName, productQuantity);
    newCustomer->name = name;
    newCustomer->productName = productName;
    newCustomer->productQuantity = productQuantity;
    newCustomer->next = NULL;

    return newCustomer;
}

typedef struct queue{
    Customer *front;
    Customer *back;
    int size;
} queue;

void init(queue *customerQueue){
    customerQueue->front = customerQueue->back = NULL;
    customerQueue->size = 0;
}

void enqueue(queue *customerQueue, Product *&head, char *name, char *productName, int productQuantity){
    Product *productSold = head;

    //Item is in the storage?
    while(productSold != NULL){
        if(strcmp(productSold->name, name) == 0){
            break;
        }
        productSold = productSold->next;
    }
    if(productSold->next == NULL){
        printf("Product %s is not in storage.\n", name);
        return;
    }

    //Update product sold in storage
    if(productSold->quantity > productQuantity){
        printf("The item is not enough products to sell.");
    }
    else{
        productSold->quantity -= productQuantity;
        if(productSold->quantity <= 0){
            removeProduct(productSold, name);
            printf("%s is run out of", name);
        }
    }

    //Create a new customer
    Customer *tmp = makeCustomer(name, productName, productQuantity);

    //
    if(customerQueue->front == NULL){
        customerQueue->front = customerQueue->back = tmp;
    }
    else{
        tmp->next = customerQueue->back;
        customerQueue->back = tmp;
    }
    customerQueue->size++;
}

// void dequeue(queue *customerQueue, )

int main(){
    Product *head = NULL;
    queue *customerQueue = NULL;
    init(customerQueue);
}