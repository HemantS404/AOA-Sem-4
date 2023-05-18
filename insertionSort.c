#include <stdio.h>
#define max 10

int arr[] = {10,9,8,7,6,5,4,3,2,1};

void main(){
    for(int i=1; i<max; i++){
        int j = i-1;
        int key = arr[i];
        while(j>=0 && key<arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    printf("Soln\n");
    for(int i=0; i<max; i++){
        printf("%d\t", arr[i]);
    }
}