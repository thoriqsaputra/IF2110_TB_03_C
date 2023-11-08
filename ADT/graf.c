#include <stdio.h>
#include <stdlib.h>
#include "graf.h"

// Inisialisasi graf dengan jumlah vertex tertentu
void initGraph(Graph* graph, int vertices) {
    Vertices(graph) = vertices;
    Edges(graph) = 0;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            AdjMatrix(graph, i, j) = 0;
        }
    }
}

// Menambahkan edge antara dua vertex
void addEdge(Graph* graph, int vertex1, int vertex2) {
    if (vertex1 >= 0 && vertex1 < Vertices(graph) && vertex2 >= 0 && vertex2 < Vertices(graph)) {
        AdjMatrix(graph, vertex1, vertex2) = 1;
        AdjMatrix(graph, vertex2, vertex1) = 1;
        Edges(graph)++;
    }
}

void removeEdge(Graph* graph, int vertex1, int vertex2) {
    if (vertex1 >= 0 && vertex1 < Vertices(graph) && vertex2 >= 0 && vertex2 < Vertices(graph)) {
        AdjMatrix(graph, vertex1, vertex2) = 0;
        AdjMatrix(graph, vertex2, vertex1) = 0;
        Edges(graph)--;
    }
}

// Mengecek apakah ada edge antara dua vertex
boolean hasEdge(Graph* graph, int vertex1, int vertex2) {
    if (vertex1 >= 0 && vertex1 < Vertices(graph) && vertex2 >= 0 && vertex2 < Vertices(graph)) {
        return AdjMatrix(graph, vertex1, vertex2) == 1;
    }
    return false;
}

// Fungsi untuk memperluas graf dengan menambahkan newVertices baru
void expandGraph(Graph* graph, int newVertices) {
    if (newVertices <= 0) {
        printf("Invalid number of new vertices.\n");
        return;
    }

    int prevVertices = Vertices(graph);
    int totalVertices = prevVertices + newVertices;

    // Check for exceeding the maximum vertices
    if (totalVertices > MAX_VERTICES) {
        printf("Cannot exceed the maximum number of vertices.\n");
        return;
    }

    // Create a new adjacency matrix with expanded size
    int newAdjMatrix[MAX_VERTICES][MAX_VERTICES] = {0};

    // Copy the content of the old graph into the new adjacency matrix
    for (int i = 0; i < prevVertices; i++) {
        for (int j = 0; j < prevVertices; j++) {
            newAdjMatrix[i][j] = AdjMatrix(graph, i, j);
        }   
    }

    // Update the graph structure with the expanded size and new adjacency matrix
    Vertices(graph) = totalVertices;
    Edges(graph) = Edges(graph); // Edges remain the same

    for (int i = 0; i < totalVertices; i++) {
        for (int j = 0; j < totalVertices; j++) {
            AdjMatrix(graph, i, j) = newAdjMatrix[i][j];
        }
    }
}