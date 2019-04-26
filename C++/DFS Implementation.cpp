#include <iostream>
#include <cstdio>

using namespace std;

void printDFS(int** edges, int n, int sv, int* visited) {
    printf("%d\n", sv);
    visited[sv] = 1;
    for(int i = 0; i < n; i++) {
        if(i == sv) {
            continue;
        }
        if(edges[sv][i] == 1) {
            if(visited[i] == 1) {
                continue;
            }
            printDFS(edges, n, i, visited);
        }
    }
}

int main() {
    int n, e;
    scanf("%d %d", &n, &e);

    // Graph Adjacency Matrix Creation
    // *****************************************************************************************************************************
    int** edges = new int* [n];
    for(int i = 0; i < n; i++) {
        edges[i] = new int[n];
        for(int j = 0; j < n; j++) {
            edges[i][j] = 0;
        }
    }
    // *****************************************************************************************************************************

    // Taking edges as input
    // *****************************************************************************************************************************
    //Taking first vertex and second vertex as input
    int f, s; 
    for(int i = 0; i < e; i++) {
        scanf("%d %d", &f, &s);
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    // *****************************************************************************************************************************

    int* visited = new int[n];
    for(int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    printf("\nThe Depth First Search Order is: \n");
    printDFS(edges, n, 0, visited);
    return 0; 
}