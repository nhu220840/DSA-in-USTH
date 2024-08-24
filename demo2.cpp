#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Website {
    char *url;
    char *title;
    struct Website *next;
} Website;

typedef struct Stack {
    int size;
    Website *top;
} Stack;

Website *makeWebsite(char *url, char *title) {
    Website *newWebsite = (Website *)malloc(sizeof(Website));
    if (newWebsite == NULL) {
        printf("Memory allocation failed for newWebsite.\n");
        exit(1);
    }
    newWebsite->url = strdup(url);
    newWebsite->title = strdup(title);
    if (newWebsite->url == NULL || newWebsite->title == NULL) {
        printf("Memory allocation failed for url or title.\n");
        exit(1);
    }
    newWebsite->next = NULL;
    return newWebsite;
}

Stack *makeStack() {
    Stack *newStack = (Stack *)malloc(sizeof(Stack));
    if (newStack == NULL) {
        printf("Memory allocation failed for newStack.\n");
        exit(1);
    }
    newStack->size = 0;
    newStack->top = NULL;
    return newStack;
}

int isEmpty(Stack *st) {
    return st->size == 0;
}

void push(Stack *st, char *url, char *title) {
    Website *newWeb = makeWebsite(url, title);
    newWeb->next = st->top;
    st->top = newWeb;
    st->size++;
}

void pop(Stack *st) {
    if (isEmpty(st)) {
        printf("Stack is empty, cannot pop.\n");
        return;
    }

    Website *tmp = st->top;
    st->top = st->top->next;
    st->size--;

    free(tmp->url);
    free(tmp->title);
    free(tmp);
}

Website* peek(Stack *st) {
    if (isEmpty(st)) {
        return NULL;
    }
    return st->top;
}

void visitWebsite(Stack *backwardStack, Stack *forwardStack, char *url, char *title) {
    // Clear the forward stack
    while (!isEmpty(forwardStack)) {
        pop(forwardStack);
    }
    // Push the new website to the backward stack
    push(backwardStack, url, title);
    printf("Visited: %s - %s\n", url, title);
}

void goBack(Stack *backwardStack, Stack *forwardStack) {
    if (isEmpty(backwardStack)) {
        printf("No previous website to go back to.\n");
        return;
    }
    Website *current = peek(backwardStack);
    pop(backwardStack);
    push(forwardStack, current->url, current->title);
}

void goForward(Stack *backwardStack, Stack *forwardStack) {
    if (isEmpty(forwardStack)) {
        printf("No forward website to go to.\n");
        return;
    }
    Website *current = peek(forwardStack);
    pop(forwardStack);
    push(backwardStack, current->url, current->title);
}

void displayStacks(Stack *backwardStack, Stack *forwardStack) {
    Website *current;

    printf("Backward Stack:\n");
    current = backwardStack->top;
    while (current != NULL) {
        if (current == peek(backwardStack)) {
            printf("%s - %s (You are here)\n", current->url, current->title);
        } else {
            printf("%s - %s\n", current->url, current->title);
        }
        current = current->next;
    }

    printf("\nForward Stack:\n");
    current = forwardStack->top;
    while (current != NULL) {
        printf("%s - %s\n", current->url, current->title);
        current = current->next;
    }

    printf("\n");
}

int main() {
    Stack *backwardStack = makeStack();
    Stack *forwardStack = makeStack();

    // Visit 10 websites
    visitWebsite(backwardStack, forwardStack, "https://example0.com", "Example Site 0");
    visitWebsite(backwardStack, forwardStack, "https://example1.com", "Example Site 1");
    visitWebsite(backwardStack, forwardStack, "https://example2.com", "Example Site 2");
    visitWebsite(backwardStack, forwardStack, "https://example3.com", "Example Site 3");
    visitWebsite(backwardStack, forwardStack, "https://example4.com", "Example Site 4");
    visitWebsite(backwardStack, forwardStack, "https://example5.com", "Example Site 5");
    visitWebsite(backwardStack, forwardStack, "https://example6.com", "Example Site 6");
    visitWebsite(backwardStack, forwardStack, "https://example7.com", "Example Site 7");
    visitWebsite(backwardStack, forwardStack, "https://example8.com", "Example Site 8");
    visitWebsite(backwardStack, forwardStack, "https://example9.com", "Example Site 9");

    printf("=======================================================\n");

    int choice;
    do {
        displayStacks(backwardStack, forwardStack);
        
        printf("Menu:\n");
        printf("1. Go forward\n");
        printf("2. Go backward\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                goForward(backwardStack, forwardStack);
                break;
            case 2:
                goBack(backwardStack, forwardStack);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);

    // Clean up stacks
    while (!isEmpty(backwardStack)) {
        pop(backwardStack);
    }
    while (!isEmpty(forwardStack)) {
        pop(forwardStack);
    }

    free(backwardStack);
    free(forwardStack);

    return 0;
}
