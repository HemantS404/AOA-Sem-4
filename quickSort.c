#include <stdio.h>
#define max 10

int arr[] = {10,9,8,7,6,5,4,3,2,1};

int partion(int low, int high){
    int i=low, j=high, key=low;
    while(i<=j){
        while(arr[i] <= arr[key]){
            i++;
        }
        while(arr[j] > arr[key]){
            j--;
        }
        if(i <= j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[key];
    arr[key] = arr[j];
    arr[j] = temp;
    return j;
}

void quicksort(int low, int high){
    if(low<high){
        int k = partion(low, high);
        quicksort(low, k-1);
        quicksort(k+1, high);
    }
}

void main(){
    quicksort(0, max-1);
    printf("Soln\n");
    for(int i=0; i<max; i++){
        printf("%d\t", arr[i]);
    }
}