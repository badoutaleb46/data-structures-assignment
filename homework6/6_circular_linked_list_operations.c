#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *next;
};


struct Node* insertEnd(struct Node* last, int x) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;

    if (last == NULL) {
        n->next = n;
        return n;
    }

    n->next = last->next;
    last->next = n;
    return n;
}

struct Node* insertAfter(struct Node* last, int key, int x) {
    if (last == NULL)
        return NULL;

    struct Node* t = last->next;

    do {
        if (t->data == key) {
            struct Node* n = (struct Node*)malloc(sizeof(struct Node));
            n->data = x;
            n->next = t->next;
            t->next = n;

            if (t == last)
                last = n;

            return last;
        }
        t = t->next;
    } while (t != last->next);

    printf("Value %d not found.\n", key);
    return last;
}


struct Node* deleteNode(struct Node* last, int key) {
    if (last == NULL)
        return NULL;

    struct Node *curr = last->next, *prev = last;

    do {
        if (curr->data == key) {
            if (curr == last && curr->next == last) {
                free(curr);
                return NULL;
            }

            prev->next = curr->next;

            if (curr == last)
                last = prev;

            free(curr);
            return last;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != last->next);

    printf("Value %d not found.\n", key);
    return last;
}


void traverse(struct Node* last) {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* t = last->next;
    printf("Circular Linked List: ");

    do {
        printf("%d ", t->data);
        t = t->next;
    } while (t != last->next);

    printf("\n");
}


int main() {
    struct Node* last = NULL;
    int n, x, key, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        last = insertEnd(last, x);
    }

    printf("Enter value after which to insert: ");
    scanf("%d", &key);

    printf("Enter value to insert: ");
    scanf("%d", &x);

    last = insertAfter(last, key, x);

    printf("Enter value to delete: ");
    scanf("%d", &key);

    last = deleteNode(last, key);

    traverse(last);

    return 0;
}
