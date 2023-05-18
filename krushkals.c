#include <stdio.h>
#define n 5

struct edge{
    int length,v1,v2;
};

int setval[n];

struct edge edges[20];

int graph[n][n] = {{0, 9, 75, 0, 0},
               {9, 0, 95, 19, 42},
               {75, 95, 0, 51, 66},
               {0, 19, 51, 0, 31},
               {0, 42, 66, 31, 0}};

int initializeEdges(){
    int k=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(graph[i][j] !=0){
                edges[k].length =graph[i][j];
                edges[k].v1 = i;
                edges[k].v2 = j;
                k++;
            }
        }
    }
    return k;
}

void makeset(int v1, int v2){
    if(setval[v1] < setval[v2]){
        for(int i=0; i<n; i++){
            if(setval[i] == setval[v2]){
                setval[i] = setval[v1];
            }
        }
    }
    else{
        for(int i=0; i<n; i++){
            if(setval[i] == setval[v1]){
                setval[i] = setval[v2];
            }
        }
    }
}

void Krushkal(int v){
    int j=0;
    for(int i=0; i<v; i++){
        if(setval[edges[i].v1] != setval[edges[i].v2]){
            printf("%d----%d PT : %d\n",edges[i].v1,edges[i].v2,edges[i].length);
            makeset(edges[i].v1,edges[i].v2);
            j++;
        }
        if(j == n-1){
            break;
        }
    }
}

void main(){
    int v = initializeEdges();
    for(int i=0; i<v; i++){
        setval[i] = i;
    }
    for(int i=1; i<v; i++){
        int j = i-1;
        struct edge key = edges[i];
        while(j>=0 && key.length<edges[j].length){
            edges[j+1] = edges[j];
            j--;
        }
        edges[j+1] = key;
    }
    Krushkal(v);
}