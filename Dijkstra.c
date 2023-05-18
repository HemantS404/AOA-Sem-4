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

int isToExplore(){
    for(int i=0; i<n; i++){
        if(visited[i] == 0){
            return 1;
        }
    }
    return 0;
}

int getMinNode(){
    int minNode;
    for(int i=0; i<n; i++){
        if(distance[i] != 100 && visited[i] == 0){
            minNode = i;
            break;
        }
    }
    for(int i=minNode; i<n; i++){
        if(distance[i] != 100 && distance[i] < distance[minNode] && visited[i] == 0){
            minNode = i;
        }
    }
    return minNode;
}

void Relax(int u, int v){
    if(distance[u] + graph[u][v] < distance[v]){
        distance[v] = distance[u] + graph[u][v];
        parent[v] = u;
    }
}

void Dijkstra(int source){
    initializeSingleSource(source);
    while(isToExplore()){
        int u = getMinNode();
        for(int v=0; v<n; v++){
            if(graph[u][v] != 100 && u != v){
                Relax(u,v);
            }
        }
        visited[u] = 1;
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
    Dijkstra(source);
    printSol();
}