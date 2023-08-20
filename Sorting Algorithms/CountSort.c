#include <stdio.h>
#include <stdlib.h>

void printArray( int arr[],int n){

    for (int i = 0; i < n; i++) printf("%d ",arr[i]);
    printf("\n");
    
}

void CountSort(int arr[],int n){
    
    int maxInd = 0;
    for(int i=1;i<n;i++) if(arr[maxInd]<arr[i]) maxInd = i;

    maxInd = arr[maxInd]; //Note, now this is not pointing the max index

    int *count = (int*)calloc(maxInd+1,sizeof(int));

    for(int i=0;i<n;i++) count[arr[i]]++;

    int j=0,i=0;

    while(i<=maxInd) {
        
        if(count[i]>0){
            arr[j++]=i;
            count[i]--;
        }else i++;

        }
    
    free(count);
    
}

void main()
{
    int arr[] = {3, 5, 2, 13,11,0, 12, 0, 11};
    int n = sizeof(arr) / sizeof(int);

    printArray(arr, n);
    CountSort(arr, n);
    printArray(arr, n);

}