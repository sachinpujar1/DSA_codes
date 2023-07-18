#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct {
    int items[MAX_VERTICES];
    int front;
    int rear;
} Queue;


typedef struct {
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;


void enqueue(Queue* q, int value) {
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(Queue* q) {
    int item = q->items[q->front];
    q->front++;
    return item;
}

int isEmpty(Queue* q) {
    return q->rear < q->front;
}


void initializeGraph(Graph* graph, int numVertices) {
    graph->numVertices = numVertices;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
}

void addEdge(Graph* graph, int source, int destination) {
    graph->adjacencyMatrix[source][destination] = 1;
    graph->adjacencyMatrix[destination][source] = 1;
}
void bfsTraversal(Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    Queue queue;
    queue.front = 0;
    queue.rear = -1;


    enqueue(&queue, startVertex);
    visited[startVertex] = 1;

    while (!isEmpty(&queue)) {
        int currentVertex = dequeue(&queue);
        printf("%d ", currentVertex);

        for (int i = 0; i <= graph->numVertices; i++) {
            if (graph->adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
                enqueue(&queue, i);
                visited[i] = 1;
                visited[currentVertex] = 1;
            }
        }
    }
}



int main() {
    Graph graph;
    int numVertices, numEdges, sourceVertex;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);

    initializeGraph(&graph, numVertices);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &numEdges);

    for (int i = 0; i < numEdges; i++) {
        int source, destination;
        printf("Enter edge %d: ", i + 1);
        scanf("%d %d", &source, &destination);
        addEdge(&graph, source, destination);
    }

    printf("Enter the starting vertex for BFS traversal: ");
    scanf("%d", &sourceVertex);

    printf("BFS Traversal: ");
    bfsTraversal(&graph, sourceVertex);

    return 0;
}
