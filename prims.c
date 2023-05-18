#include <stdio.h>
#define n 5

int distance[n], visited[n], parent[n];

int graph[n][n] = {{0, 9, 75, 0, 0},
               {9, 0, 95, 19, 42},
               {75, 95, 0, 51, 66},
               {0, 19, 51, 0, 31},
               {0, 42, 66, 31, 0}};


void initializeGraph(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if (graph[i][j] == 0 && i != j){
                graph[i][j] = 100;
            }
        }
    }
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

void initializeSingleSource(int source){
    initializeGraph();
    for(int i=0; i<n; i++){
        distance[i] = 100;
        parent[i] = -1;
        visited[i] = 0;
    }
    distance[source] = 0;
}

void Prims(){
    initializeSingleSource(0);
    while(isToExplore()){
        int u = getMinNode();
        for(int v=0; v<n; v++){
            if(graph[u][v] != 100 && u != v){
                if(graph[u][v] < distance[v]){
                    distance[v] = graph[u][v];
                    parent[v] = u;
                }
            }
        }
        visited[u] = 1;
    }
}
void printSol(int source){
    printf("Node\tDistance\tParent\n");
    for(int i=0; i<n; i++){
        if(i != source){
            printf("%d----%d PT : %d\n",parent[i],i,distance[i]);
        }
    }
}


void main(){
    Prims(0);
    printSol(0);
}