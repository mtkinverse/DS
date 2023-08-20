#include<stdio.h>

void printArray(int arr[],int n){
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");
}

int partition(int arr[],int low,int high){

    int piviot = arr[low],temp;
    int i=low+1;
    int j = high;

    do{

    while(arr[i]<=piviot) i++;
    while(arr[j]>piviot) j--;
    
    if(i<j){
        temp = arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        }

    }while(i<j);
        
        temp = arr[low];
        arr[low]=arr[j];
        arr[j]=temp;
        
        return j;

}


void QuickSort(int arr[],int low,int high){

    if(low>high)return;

    int piviotInd=partition(arr,low,high);
    QuickSort(arr,low,piviotInd-1);
    QuickSort(arr,piviotInd+1,high);


}

void main(){

    int arr[] = {3,5,2,13,12,0,11};
    int n = sizeof(arr)/sizeof(int);

    printArray(arr,n);
    QuickSort(arr,0,n-1);
    printArray(arr,n);

}