#include <stdio.h>
#include <string.h>
#define max 10

int B[max][max], C[max+1][max+1];

void LCS(char *x, char *y){
    int m = strlen(x);
    int n = strlen(y);
    for(int i=0; i<=m; i++){
        C[i][0] = 0; 
    }
    for(int j=0; j<=n; j++){
        C[0][j] = 0; 
    }
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(x[i-1] == y[j-1]){
                C[i][j] = 1 + C[i-1][j-1];
                B[i-1][j-1] = 3;
            }
            else if(C[i][j-1] > C[i-1][j]){
                C[i][j] = C[i][j-1];
                B[i-1][j-1] = 1;
            }
            else{
                C[i][j] = C[i-1][j];
                B[i-1][j-1] = 2;
            }
        }
    }
}

void printLCS(int i, int j, char *x){
    if(i>=0 || j>=0){
        if (B[i][j] == 3){
            printLCS(i-1, j-1, x);
            printf("%c", x[i]);
        }
        else if (B[i][j] == 1){
            printLCS(i, j-1, x);
        }
        else{
            printLCS(i-1, j, x);
        }
    }
}

void main(){
    char x[] = "properties";
    char y[] = "prosperity";
    LCS(x, y);
    printf("B\n");
    for(int i=0; i<=max; i++){
        for(int j=0; j<=max; j++){
            printf("%d\t",B[i][j]);
        }
        printf("\n");
    }
    printf("C\n");
    for(int i=0; i<=max; i++){
        for(int j=0; j<=max; j++){
            printf("%d\t",C[i][j]);
        }
        printf("\n");
    }
    printLCS(max-1,max-1,x);
}