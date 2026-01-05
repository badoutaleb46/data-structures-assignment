#include <stdio.h>


void insert(int a[], int *n, int pos, int val) {
    int i;

    for (i = *n; i > pos; i--)
        a[i] = a[i - 1];

    a[pos] = val;
    (*n)++;
}


void delete(int a[], int *n, int pos) {
    int i;

    for (i = pos; i < *n - 1; i++)
        a[i] = a[i + 1];

    (*n)--;
}


void display(int a[], int n) {
    int i;
    printf("Array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}


int main() {
    int a[100];
    int n, i, pos, val;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    
    printf("Enter position to insert (0-based index): ");
    scanf("%d", &pos);

    printf("Enter value to insert: ");
    scanf("%d", &val);

    insert(a, &n, pos, val);
    display(a, n);

    
    printf("Enter position to delete (0-based index): ");
    scanf("%d", &pos);

    delete(a, &n, pos);
    display(a, n);

    return 0;
}
