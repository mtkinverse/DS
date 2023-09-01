#include<iostream>
using namespace std;

template <class t>
void CombSort (t arr[],int gap,int n){
    for(int i=0;i+gap<n;i++){
        if(arr[i]>arr[i+gap]){
            int temp = arr[i];
            arr[i] = arr[i+gap];
            arr[i+gap] = temp;
        }
    }
    if(gap>0) CombSort(arr,gap/1.3,n);
}

template <class t>
void printArray(t arr[],int n){
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){

    int arr[] = {9,4,5,3,8,0,1,5};
    int n = sizeof(arr)/sizeof(int);

    printArray( arr, n);

    CombSort(arr,n/1.3,n);

    printArray( arr, n);
    
    return 0;

}