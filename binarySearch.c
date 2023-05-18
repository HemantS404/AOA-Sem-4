#include <stdio.h>

int arr[] = {1,2,3,4,5,6,7,8,9,10,40};

int binarySearch(int low, int high, int search){
    if(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] == search){
            return mid;
        }
        else if(arr[mid] < search){
            return binarySearch(mid+1, high, search);
        }
        else{
            return binarySearch(low, mid, search);
        }
    }
    return -1;
}

void main(){
    printf("%d found at index : %d", 5, binarySearch(0,11,5));
}