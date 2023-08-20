#include<stdio.h>

void printArray(int arr[],int n){
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");
}

void SelectoinSort(int arr[],int n){
    int minInd,temp;
    for(int i=0;i<n-1;i++){
        int j = i+1;
        minInd = i;
        for(j;j<n;j++){
            if(arr[j]<arr[minInd]){
                temp = arr[minInd];
                arr[minInd]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

void main(){
    int arr[] = {9,4,5,3,8,0};
    int n = sizeof(arr)/sizeof(int);

    printArray( arr, n);

    SelectoinSort(arr,n);

    printArray( arr, n);

}