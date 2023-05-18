#include <stdio.h>
#include <string.h>

int pi[10];

void cmp(char *p){
    int n = strlen(p);
    int k=1;
    pi[0] = 0;
    for(int i=1; i<n; i++){
        while(k!=0 && p[k] != p[i]){
            k=pi[k];
        }
        if(p[k] == p[i]){
            k++;
        }
        p[i] = k;
    }
}

void KMP(char *t, char *p){
    int m =strlen(t);
    int n = strlen(p);
    int q =1;
    for(int i=0; i<m; i++){
        while(q!=0 && p[q] != t[i]){
            q=pi[q];
        }
        if(p[q] == t[i]){
            q++;
        }
        if(q == n){
            printf("pattern at %d\n", i-n+1);
            q=pi[q];
        }
    }
}




int main() {
    KMP("abcdbcebce", "bce");
    return 0;
}