#ifndef GRAF_H
#define GRAF_H

#include "boolean.h"
// #include "listlinier.h"

#define MAX_VERTICES 100

typedef struct
{
    int vertices;
    int edges;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

#define Vertices(v) (v)->vertices
#define Edges(v) (v)->edges
#define AdjMatrix(M, i, j) (M)->adjMatrix[(i)][(j)]

// Inisialisasi graf dengan jumlah vertex tertentu
void initGraph(Graph *graph, int vertices);

// Menambahkan edge antara dua vertex
void addEdge(Graph *graph, int vertex1, int vertex2);

void removeEdge(Graph *graph, int vertex1, int vertex2);

// Mengecek apakah ada edge antara dua vertex
boolean hasEdge(Graph *graph, int vertex1, int vertex2);

// Fungsi untuk memperluas graf dengan menambahkan newVertices baru
void expandGraph(Graph *graph, int newVertices);

// void connectedEdges(Graph *graph, int index, int edges[], ListLin *LL);

#endif