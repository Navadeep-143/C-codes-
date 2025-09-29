#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int adj[MAX][MAX];
int visited[MAX];
int n;

void createGraph() {
    int i, j;
    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
}

void DFS(int v) {
    int i;
    visited[v] = 1;
    printf("%d ", v);

    for (i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

int isConnected() {
    int i;
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    DFS(0);

    for (i = 0; i < n; i++) {
        if (!visited[i])
            return 0;
    }
    return 1;
}

int main() {
    int start, choice;
    createGraph();

    while (1) {
        printf("\n--- Graph Operations ---\n");
        printf("1. Print all nodes reachable from a given city (DFS)\n");
        printf("2. Check whether graph is connected or not\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter starting city (0 to %d): ", n-1);
            scanf("%d", &start);

            for (int i = 0; i < n; i++) visited[i] = 0;

            printf("Cities reachable from %d: ", start);
            DFS(start);
            printf("\n");
            break;

        case 2:
            if (isConnected())
                printf("Graph is CONNECTED.\n");
            else
                printf("Graph is NOT CONNECTED.\n");
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int adj[MAX][MAX];
int visited[MAX];
int n;

void createGraph() {
    int i, j;
    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
}

void DFS(int v) {
    int i;
    visited[v] = 1;
    printf("%d ", v);

    for (i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

int isConnected() {
    int i;
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    DFS(0);

    for (i = 0; i < n; i++) {
        if (!visited[i])
            return 0;
    }
    return 1;
}

int main() {
    int start, choice;
    createGraph();

    while (1) {
        printf("\n--- Graph Operations ---\n");
        printf("1. Print all nodes reachable from a given city (DFS)\n");
        printf("2. Check whether graph is connected or not\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter starting city (0 to %d): ", n-1);
            scanf("%d", &start);

            for (int i = 0; i < n; i++) visited[i] = 0;

            printf("Cities reachable from %d: ", start);
            DFS(start);
            printf("\n");
            break;

        case 2:
            if (isConnected())
                printf("Graph is CONNECTED.\n");
            else
                printf("Graph is NOT CONNECTED.\n");
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}