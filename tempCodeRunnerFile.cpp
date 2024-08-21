void resizeStorage(Product *&head, char *name, int quantity, int price) {
    Product *tmp = head;
    while (tmp != NULL) {
        if (strcmp(tmp->name, name) == 0) {
            tmp->quantity += quantity;
            return;
        }
        tmp = tmp->next;
    }

    addProduct(head, name, quantity, price);
}