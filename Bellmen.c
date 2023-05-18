#include <stdio.h>
#define n 9
                //  0 1 2 3 4 5 6 7 8
int graph[n][n] = {{0,4,0,0,0,0,0,8,0},
                   {4,0,8,0,0,0,0,11,0},
                   {0,8,0,7,0,4,0,0,2},
                   {0,0,7,0,9,14,0,0,0},
                   {0,0,0,9,0,10,0,0,0},
                   {0,0,4,14,10,0,2,0,0},
                   {0,0,0,0,0,2,0,1,6},
                   {8,11,0,0,0,0,1,0,7},
                   {0,0,2,0,0,0,6,7,0}};
                   
int distance[n], visited[n], parent[n];

void initializeGraph(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if (graph[i][j] == 0 && i != j){
                graph[i][j] = 100;
            }
        }
    }
}


void initializeSingleSource(int source){
    initializeGraph();
    for(int i=0; i<n; i++){
        distance[i] = 100;
        parent[i] = -1;
        visited[i] = 0;
    }
    distance[source] = 0;
}

void Relax(int u, int v){
    if(distance[u] + graph[u][v] < distance[v]){
        distance[v] = distance[u] + graph[u][v];
        parent[v] = u;
    }
}

void BellmenFord(int source){
    initializeSingleSource(source);
    for(int k=0; k<n; k++){
        for(int u=0; u<n; u++){
            for(int v=0; v<n; v++){
                if(graph[u][v] != 100 && u != v){
                    Relax(u,v);
                }
            }
        }
    }
}

void printSol(){
    printf("Node\tDistance\tParen\n");
    for(int i=0; i<n; i++){
        printf("%d\t\t%d\t\t%d\n",i,distance[i],parent[i]);
    }
}

void main(){
    int source;
    printf("Enter Source : ");
    scanf("%d", &source);
    BellmenFord(source);
    printSol();
}