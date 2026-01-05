#include <stdio.h>


void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}


void maxHeapify(int a[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && a[l] > a[largest])
        largest = l;

    if (r < n && a[r] > a[largest])
        largest = r;

    if (largest != i) {
        swap(&a[i], &a[largest]);
        maxHeapify(a, n, largest);
    }
}


void minHeapify(int a[], int n, int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && a[l] < a[smallest])
        smallest = l;

    if (r < n && a[r] < a[smallest])
        smallest = r;

    if (smallest != i) {
        swap(&a[i], &a[smallest]);
        minHeapify(a, n, smallest);
    }
}

int main() {
    int a[10], n, i;

    
    scanf("%d", &n);

    
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    
    for (i = n/2 - 1; i >= 0; i--)
        maxHeapify(a, n, i);

    printf("Max Heap: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");

    
    for (i = n/2 - 1; i >= 0; i--)
        minHeapify(a, n, i);

    printf("Min Heap: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
