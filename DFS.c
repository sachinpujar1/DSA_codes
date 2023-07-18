#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Graph data structure
typedef struct Graph {
    int** adjacencyMatrix;
    int numVertices;
} Graph;

// Function to create a new graph
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;

    // Allocate memory for the adjacency matrix
    graph->adjacencyMatrix = (int**)malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjacencyMatrix[i] = (int*)malloc(numVertices * sizeof(int));
        // Initialize matrix cells to 0 (no connections)
        for (int j = 0; j < numVertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }

    return graph;
}

// Function to add an edge between two vertices
void addEdge(Graph* graph, int src, int dest) {
    graph->adjacencyMatrix[src][dest] = 1;
    graph->adjacencyMatrix[dest][src] = 1;
}

// Depth-first search traversal
void DFS(Graph* graph, int startVertex, bool* visited) {
    printf("%d ", startVertex);
    visited[startVertex] = true;

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjacencyMatrix[startVertex][i] == 1 && !visited[i]) {
            DFS(graph, i, visited);
        }
    }
}

// Breadth-first search traversal
void BFS(Graph* graph, int startVertex, bool* visited) {
    bool* queue = (bool*)malloc(graph->numVertices * sizeof(bool));
    int front = 0;
    int rear = 0;

    visited[startVertex] = true;
    printf("%d ", startVertex);
    queue[rear++] = startVertex;

    while (front != rear) {
        int currentVertex = queue[front++];

        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                printf("%d ", i);
                queue[rear++] = i;
            }
        }
    }

    free(queue);
}

int main() {
    int numVertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    // Create a graph with the specified number of vertices
    Graph* graph = createGraph(numVertices);

    // Generate random numbers and build the graph
    int numRandomNumbers;
    printf("Enter the number of random numbers to generate: ");
    scanf("%d", &numRandomNumbers);

    printf("Enter the random numbers:\n");
    for (int i = 0; i < numRandomNumbers; i++) {
        int randomNumber = rand() % numVertices;
        int vertex = i % numVertices;
        addEdge(graph, vertex, randomNumber);
    }

    // Perform DFS traversal starting from vertex 0
    printf("DFS Traversal: ");
    bool* visitedDFS = (bool*)calloc(numVertices, sizeof(bool));
    DFS(graph, 0, visitedDFS);
    printf("\n");

    // Perform BFS traversal starting from vertex 0
    printf("BFS Traversal: ");
    bool* visitedBFS = (bool*)calloc(numVertices, sizeof(bool));
    BFS(graph, 0, visitedBFS);
    printf("\n");

    // Clean up memory
    free(visitedDFS);
    free(visitedBFS);
    for (int i = 0; i < numVertices; i++) {
        free(graph->adjacencyMatrix[i]);
    }
    free(graph->adjacencyMatrix);
    free(graph);

    return 0;
}
