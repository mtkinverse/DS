#include<iostream>
using namespace std;

template <class t>
void printArray(t arr[],int n){
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
}

template <class t>
void ShellSort(t arr[],int size){
    
    for(int interval = size; interval>0 ; interval/=2){  
      for(int i=interval;i<size;i++){
        int j,key = arr[i];

        for( j=i;j>=interval && arr[j-interval]>key ;j-=interval) arr[j] = arr[j-interval];
        arr[j] = key;
    }
    }
}

int main(){

    int arr[] = {9,4,5,3,8,0,1,5};
    int n = sizeof(arr)/sizeof(int);

    printArray( arr, n);

    ShellSort(arr,n);

    printArray( arr, n);
    
    return 0;

}