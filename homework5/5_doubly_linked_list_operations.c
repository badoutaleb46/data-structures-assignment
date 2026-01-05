#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};


struct Node* insertEnd(struct Node* head, int x) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->prev = NULL;
    n->next = NULL;

    if (head == NULL)
        return n;

    struct Node* t = head;
    while (t->next != NULL)
        t = t->next;

    t->next = n;
    n->prev = t;
    return head;
}


struct Node* insertAfter(struct Node* head, int key, int x) {
    struct Node* t = head;

    while (t != NULL && t->data != key)
        t = t->next;

    if (t == NULL) {
        printf("Value %d not found.\n", key);
        return head;
    }

    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;

    n->next = t->next;
    n->prev = t;

    if (t->next != NULL)
        t->next->prev = n;

    t->next = n;
    return head;
}


struct Node* deleteNode(struct Node* head, int key) {
    struct Node* t = head;

    while (t != NULL && t->data != key)
        t = t->next;

    if (t == NULL) {
        printf("Value %d not found.\n", key);
        return head;
    }

    if (t->prev != NULL)
        t->prev->next = t->next;
    else
        head = t->next;

    if (t->next != NULL)
        t->next->prev = t->prev;

    free(t);
    return head;
}


void traverse(struct Node* head) {
    printf("Doubly Linked List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}


int main() {
    struct Node* head = NULL;
    int n, x, key, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insertEnd(head, x);
    }

    printf("Enter value after which to insert: ");
    scanf("%d", &key);

    printf("Enter value to insert: ");
    scanf("%d", &x);

    head = insertAfter(head, key, x);

    printf("Enter value to delete: ");
    scanf("%d", &key);

    head = deleteNode(head, key);

    traverse(head);

    return 0;
}
