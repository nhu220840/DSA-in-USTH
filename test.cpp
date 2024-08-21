#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Product {
    char *name;
    int quantity;
    int price;
    struct Product *next;
    struct Product *prev;
} Product;

typedef struct Customer {
    char *name;
    char *productName;
    int productQuantity;
    struct Customer *next;
} Customer;

typedef struct queue {
    Customer *front;
    Customer *back;
    int size;
} queue;

Product *makeProduct(char *name, int quantity, int price) {
    Product *newProduct = (Product *)malloc(sizeof(Product));
    newProduct->name = strdup(name);
    newProduct->quantity = quantity;
    newProduct->price = price;
    newProduct->next = newProduct->prev = NULL;

    return newProduct;
}

// Add product to the end of the list
void addProduct(Product *&head, char *name, int quantity, int price) {
    Product *newProduct = makeProduct(name, quantity, price);

    if (head == NULL) {
        head = newProduct;
        return;
    }

    Product *tmp = head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = newProduct;
    newProduct->prev = tmp;
}

void removeProduct(Product *&head, char *name) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Product *tmp = head;

    // Remove from the beginning
    if (strcmp(head->name, name) == 0) {
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

    // Traverse the list to find the product to remove
    while (tmp->next != NULL) {
        if (strcmp(tmp->next->name, name) == 0) {
            break;
        }
        tmp = tmp->next;
    }

    // Product not found
    if (tmp->next == NULL) {
        printf("Product %s is not in storage.\n", name);
        return;
    }

    // Remove from the middle or end
    Product *prod_remove = tmp->next;
    tmp->next = prod_remove->next;
    if (prod_remove->next != NULL) {
        prod_remove->next->prev = tmp;
        printf("Product %s removed from the middle.\n", name);
    } else {
        printf("Product %s removed from the end.\n", name);
    }

    free(prod_remove->name);
    free(prod_remove);
}

int getProductQuantity(Product *head, char *name) {
    Product *tmp = head;

    while (tmp != NULL) {
        if (strcmp(tmp->name, name) == 0) {
            return tmp->quantity;
        }
        tmp = tmp->next;
    }
    return 0;
}

void resizeStorage(Product *&head, char *name, int quantity, int price) {
    // If the product is already in stock, add more quantity
    Product *tmp = head;
    while (tmp != NULL) {
        if (strcmp(tmp->name, name) == 0) {
            tmp->quantity += quantity;
            return;
        }
        tmp = tmp->next;
    }

    // Add new product if it is not in stock
    addProduct(head, name, quantity, price);
}

Customer *makeCustomer(char *name, char *productName, int productQuantity) {
    Customer *newCustomer = (Customer *)malloc(sizeof(Customer));
    newCustomer->name = strdup(name);
    newCustomer->productName = strdup(productName);
    newCustomer->productQuantity = productQuantity;
    newCustomer->next = NULL;

    return newCustomer;
}

void init(queue *customerQueue) {
    customerQueue->front = customerQueue->back = NULL;
    customerQueue->size = 0;
}

void enqueue(queue *customerQueue, Product *&head, char *name, char *productName, int productQuantity) {
    // Find the product in storage
    Product *productSold = head;
    while (productSold != NULL) {
        if (strcmp(productSold->name, productName) == 0) {
            break;
        }
        productSold = productSold->next;
    }

    if (productSold == NULL) {
        printf("Product %s is not in storage.\n", productName);
        return;
    }

    // Update product quantity in storage
    if (productSold->quantity < productQuantity) {
        printf("The item is not enough products to sell.\n");
        return;
    } else {
        productSold->quantity -= productQuantity;
        if (productSold->quantity == 0) {
            removeProduct(head, productName);
            printf("%s is out of stock.\n", productName);
        }
    }

    // Create a new customer
    Customer *newCustomer = makeCustomer(name, productName, productQuantity);

    // Insert into the queue
    if (customerQueue->back == NULL) {
        customerQueue->front = customerQueue->back = newCustomer;
    } else {
        customerQueue->back->next = newCustomer;
        customerQueue->back = newCustomer;
    }
    customerQueue->size++;
}

void dequeue(queue *customerQueue) {
    if (customerQueue->front == NULL) {
        printf("The queue is empty.\n");
        return;
    }

    Customer *tmp = customerQueue->front;
    customerQueue->front = customerQueue->front->next;

    if (customerQueue->front == NULL) {
        customerQueue->back = NULL;
    }

    free(tmp->name);
    free(tmp->productName);
    free(tmp);
    customerQueue->size--;
}

void printCustomerInfo(queue *customerQueue) {
    if (customerQueue->front == NULL) {
        printf("No customers in the queue.\n");
        return;
    }

    Customer *tmp = customerQueue->front;
    while (tmp != NULL) {
        printf("Customer Name: %s\n", tmp->name);
        printf("Product Name: %s\n", tmp->productName);
        printf("Product Quantity: %d\n", tmp->productQuantity);
        printf("------------------------\n");
        tmp = tmp->next;
    }
}

void printMenu() {
    printf("1. Add product to storage\n");
    printf("2. Remove product from storage\n");
    printf("3. Sell product to customer\n");
    printf("4. Print customer information\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Product *head = NULL;
    queue customerQueue;
    init(&customerQueue);

    int choice;
    char name[50], productName[50];
    int quantity, price;

    while (1) {
        printMenu();
        scanf("%d", &choice);
        getchar(); // To consume newline character

        switch (choice) {
            case 1:
                printf("Enter product name: ");
                fgets(productName, 50, stdin);
                productName[strcspn(productName, "\n")] = '\0'; // Remove newline character
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                printf("Enter price: ");
                scanf("%d", &price);
                resizeStorage(head, productName, quantity, price);
                break;

            case 2:
                printf("Enter product name to remove: ");
                fgets(productName, 50, stdin);
                productName[strcspn(productName, "\n")] = '\0';
                removeProduct(head, productName);
                break;

            case 3:
                printf("Enter customer name: ");
                fgets(name, 50, stdin);
                name[strcspn(name, "\n")] = '\0';
                printf("Enter product name: ");
                fgets(productName, 50, stdin);
                productName[strcspn(productName, "\n")] = '\0';
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                enqueue(&customerQueue, head, name, productName, quantity);
                break;

            case 4:
                printCustomerInfo(&customerQueue);
                break;

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}
