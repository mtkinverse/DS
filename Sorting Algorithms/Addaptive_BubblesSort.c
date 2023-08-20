#include<stdio.h>

void BubbleSort (int arr[],int n){

    for(int i=0;i<n-1;i++){
            int isSorted = 1;
            printf("Working on pass %d\n",i+1);
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                isSorted = 0;
            }
        }
            if(isSorted) return;
    }
}

void printArray( int arr[],int n){

    for (int i = 0; i < n; i++) printf("%d ",arr[i]);
    
}

void main(){

int arr[] = {1,2,4,5,9,5,7,6};

printf("Array before sorting : ");
printArray(arr,sizeof(arr)/sizeof(int));

BubbleSort(arr,sizeof(arr)/sizeof(int));// Though it contains 8 elements, but it will sort the array in 2 pass because its first four elements are sorted ! 

printf("\nArray after sorting : ");
printArray(arr,sizeof(arr)/sizeof(int));

}