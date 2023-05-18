#include <stdio.h>
#define max 10

int arr[] = {10,9,8,7,6,5,4,3,2,1}, B[max];

void merge(int low, int mid, int high){
    int i=low,j=mid+1,k=0;
    while(i<=mid && j<=high){
        if(arr[i]>arr[j]){
            B[k] = arr[j];
            k++;
            j++;
        }
        else{
            B[k] = arr[i];
            k++;
            i++;
        }
    }
    while(i<=mid){
        B[k] = arr[i];
        k++;
        i++;
    }
    while(j<=high){
        B[k] = arr[j];
        k++;
        j++;
    }
    i=low;
    for(int f=0; f<k; f++){
        arr[i] = B[f];
        i++;
    }
}

void mergeSort(int low, int high){
    if(low<high){
        int mid = (low + high)/2;
        mergeSort(low, mid);
        mergeSort(mid+1, high);
        merge(low, mid, high);
    }
}

void main(){
    mergeSort(0, max-1);
    printf("Soln\n");
    for(int i=0; i<max; i++){
        printf("%d\t", arr[i]);
    }
}