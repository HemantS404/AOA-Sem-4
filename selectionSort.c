#include <stdio.h>
#define max 10

int arr[] = {10,9,8,7,6,5,4,3,2,1};

void main(){
    for(int i=0; i<max; i++){
        int min = arr[i], key=i; 
        for(int j=i; j<max; j++){
            if(arr[j]<min){
                min = arr[j];
                key = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[key];
        arr[key] = temp; 
    }
    printf("Soln\n");
    for(int i=0; i<max; i++){
        printf("%d\t", arr[i]);
    }
}