#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Graph {
    Node** adjList;
} Graph;

typedef struct Queue {
    Node* head;
} Queue;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Graph* g, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = g->adjList[src];
    g->adjList[src] = newNode;
}

Graph* createGraph(int vertices) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->adjList = (Node**)malloc(vertices * sizeof(Node*));

    for (int i = 0; i < vertices; ++i) {
        g->adjList[i] = NULL;
    }

    return g;
}

void bfs(Graph* g, int vertices, int startVertex) {
    Queue q = {NULL};
    int* visited = (int*)calloc(vertices, sizeof(int));

    printf("BFS starting from vertex %d: ", startVertex);
    visited[startVertex] = 1;

    Node* newNode = createNode(startVertex);
    q.head = newNode;

    while (q.head) {
        int curVertex = q.head->data;
        printf("%d -> ", curVertex);

        Node* temp = g->adjList[curVertex];
        while (temp) {
            int adjVertex = temp->data;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;

                newNode = createNode(adjVertex);
                if (q.head) {
                    Node* current = q.head;
                    while (current->next != NULL) {
                        current = current->next;
                    }
                    current->next = newNode;
                } else {
                    q.head = newNode;
                }
            }
            temp = temp->next;
        }

        Node* dequeuedNode = q.head;
        q.head = q.head->next;
        free(dequeuedNode);
    }

    free(visited);
}

int main() {
    int vertices = 6;
    Graph* g = createGraph(vertices);

    addEdge(g, 5, 0);
    addEdge(g, 5, 2);
    addEdge(g, 4, 0);
    addEdge(g, 4, 1);
    addEdge(g, 2, 3);
    addEdge(g, 3, 1);

    printf("Adjacency list:\n");
    for (int i = 0; i < vertices; ++i) {
        printf("%d: ", i);
        for (Node* temp = g->adjList[i]; temp; temp = temp->next) {
            printf("%d -> ", temp->data);
        }
        printf("NULL\n");
    }

    bfs(g, vertices, 5);

    return 0;
}
