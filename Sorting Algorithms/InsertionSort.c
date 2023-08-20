#include<stdio.h>

void InsertoinSort(int arr[],int n){

    for(int i=1;i<n;i++){

        int key = arr[i];
        int j=i-1;
        
        while(j>=0 && key<arr[j]){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
        
    }

}

void printArray( int arr[],int n){

    for (int i = 0; i < n; i++) printf("%d ",arr[i]);
    
}

void main(){

    int arr [] = {3,1,0,4,5,2,7,9,2};
    int size = sizeof(arr)/sizeof(int);

    printf("Before sorting : ");
    printArray(arr,size);

    InsertoinSort(arr,size);

    printf("\nAfter sorting : ");
    printArray(arr,size);
    
}