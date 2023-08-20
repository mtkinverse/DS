#include <stdio.h>
#include <stdlib.h>

void printArray( int arr[],int n){

    for (int i = 0; i < n; i++) printf("%d ",arr[i]);
    printf("\n");
    
}

void Merge(int arr[],int low,int high,int mid){

    int i=low,j=mid+1,k=low,Copy[100];

    while(i<=mid && j<=high){

        if(arr[i]<arr[j]) Copy[k++]=arr[i++];
        else  Copy[k++]=arr[j++];

    }
    
    while(i<=mid) Copy[k++]=arr[i++];
    while(j<=high) Copy[k++]=arr[j++];

    for(int i=0;i<=high;i++) arr[i]=Copy[i];

}

void MergeSort(int arr[],int low,int high){

    if(low<high){
        int mid= (low+high)/2;
        MergeSort(arr,low,mid);
        MergeSort(arr,mid+1,high);
        Merge(arr,low,high,mid);
    }

}

void main()
{
    int arr[] = {3, 5, 2, 13, 12, 0, 11};
    int n = sizeof(arr) / sizeof(int);

    printArray(arr, n);
    MergeSort(arr, 0, n - 1);
    printArray(arr, n);

}