#include <stdio.h>

#define MAX 100

int tree[MAX];

int main() {
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter tree elements (level order):\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &tree[i]);
    }

    printf("\nTree using array representation:\n");
    for (i = 0; i < n; i++) {
        printf("Node %d = %d", i, tree[i]);

        if (2 * i + 1 < n)
            printf(", Left Child = %d", tree[2 * i + 1]);

        if (2 * i + 2 < n)
            printf(", Right Child = %d", tree[2 * i + 2]);

        printf("\n");
    }

    return 0;
}
