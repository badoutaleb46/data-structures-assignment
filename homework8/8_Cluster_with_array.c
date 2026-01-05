#include <stdio.h>

int n;
int graph[20][20];
int visited[20];


void dfs(int v) {
    int i;
    visited[v] = 1;
    printf("%d ", v);

    for (i = 0; i < n; i++) {
        if (graph[v][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}


int main() {
    int i, j, cluster = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    
    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nClusters in the graph:\n");

    for (i = 0; i < n; i++) {
        if (visited[i] == 0) {
            cluster++;
            printf("Cluster %d: ", cluster);
            dfs(i);
            printf("\n");
        }
    }

    return 0;
}
