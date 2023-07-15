#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Creating an edge between vertices x and y
void makeEdge(int x, int y, struct Node** adj)
{
    // Create a new node for vertex y
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = y;
    newNode->next = NULL;

    // Add the new node to the adjacency list of vertex x
    if (adj[x] == NULL) {
        adj[x] = newNode;
    } else {
        struct Node* temp = adj[x];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Create a new node for vertex x
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = x;
    newNode->next = NULL;

    // Add the new node to the adjacency list of vertex y
    if (adj[y] == NULL) {
        adj[y] = newNode;
    } else {
        struct Node* temp = adj[y];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Printing the tree
void printTree(int root, struct Node** adj, int n)
{
    // creating a queue
    int* queue = (int*)malloc(n * sizeof(int));
    int front = -1, rear = -1;

    // creating a visited array
    int* visited = (int*)calloc(n, sizeof(int));

    // Enqueue the root node and mark it as visited
    queue[++rear] = root;
    visited[root] = 1;

    // This while loop runs until the queue is empty
    while (front != rear) {
        int node = queue[++front];
        printf("%d ", node);

        // Traverse the adjacency list of the current node
        struct Node* temp = adj[node];
        while (temp != NULL) {
            int neighbor = temp->vertex;
            if (visited[neighbor] == 0) {
                visited[neighbor] = 1;
                queue[++rear] = neighbor;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

// Driver code
int main()
{
    // Number of nodes
    int N = 7, Root = 1;

    // Array of pointers to represent the adjacency list
    struct Node** adj = (struct Node**)malloc((N + 1) * sizeof(struct Node*));
    for (int i = 1; i <= N; i++) {
        adj[i] = NULL;
    }

    // Creating the tree
    makeEdge(1, 2, adj);
    makeEdge(1, 3, adj);
    makeEdge(2, 4, adj);
    makeEdge(2, 5, adj);
    makeEdge(3, 6, adj);
    makeEdge(3, 7, adj);

    printTree(1, adj, N + 1);

    return 0;
}

