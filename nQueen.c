#include <stdio.h>
#include <stdlib.h>
#define n 5

int x[4];

int Place(int k, int i){
    for(int j=0; j<k; j++){
        if(x[j] == i || (abs(x[j]-i) == abs(j-k))){
            return 0;
        }
    }
    return 1;
}

int NQUEEN(int k){
    for (int i=0; i<n; i++){
        if(Place(k,i)){
            x[k] = i;
            if(k == n-1){
                printf("\n");
                for(int j=0; j<n; j++){
                    printf("%d\t", x[j]);
                }
            }
            else{
                NQUEEN(k+1);
            }
        }
    }
}

void main(){
    NQUEEN(0);
}