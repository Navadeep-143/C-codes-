#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) {
        return;
    }
    if (front == -1) {
        front = 0;
    }
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) {
        return -1;
    }
    return queue[front++];
}

void BFS(int adj[MAX][MAX], int n, int start) {
    int visited[MAX] = {0};
    
    enqueue(start);
    visited[start] = 1;
    
    printf("Nodes reachable from city %d: ", start);
    
    while (front <= rear) {
        int current = dequeue();
        printf("%d ", current);
        
        for (int i = 0; i < n; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int isConnected(int adj[MAX][MAX], int n) {
    int visited[MAX] = {0};
    
    front = rear = -1;
    
    enqueue(0);
    visited[0] = 1;
    
    while (front <= rear) {
        int current = dequeue();
        
        for (int i = 0; i < n; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            return 0;
        }
    }
    
    return 1;
}

int main() {
    int n, choice, start;
    int adj[MAX][MAX];
    
    printf("Enter number of cities: ");
    scanf("%d", &n);
    
    printf("Enter adjacency matrix (0/1):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    
    while (1) {
        printf("\n--- Graph Operations ---\n");
        printf("1. BFS Traversal from a city\n");
        printf("2. Check if graph is Connected\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter starting city (0 to %d): ", n - 1);
                scanf("%d", &start);
                front = rear = -1; 
                BFS(adj, n, start);
                break;
                
            case 2:
                if (isConnected(adj, n)) {
                    printf("Graph is connected.\n");
                } else {
                    printf("Graph is not connected.\n");
                }
                break;
                
            case 3:
                exit(0);
                
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    
    return 0;
}