#include<iostream>
#include<stdio.h>

using namespace std;

void printMatrix(int** arr,int n){
    for(int j=0;j<n;j++){
        for(int i=0;i<n;i++) cout<<arr[j][i]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

bool inBounds(int** arr,int row,int col,int n){
    int i,j;
    i=col; j=row;
    
    if(row<0 || col<0 || row>=n || col>=n || arr[row][col] == 1)return false;

    if(i-2 >= 0 && j-1 >= 0 && arr[j-1][i-2] == 1)return false;
    if(i-1 >= 0 && j-2>=0 && arr[j-2][i-1] == 1)return false;

    if(i-2 >= 0 && j+1 < n && arr[j+1][i-2] == 1)return false;

    if(i-1 >= 0 && j+2<n && arr[j+2][i-1] == 1)return false;
    
    if(i+2 < n && j-1  >= 0 && arr[j-1][i+2] == 1)return false;
    if(i+1 < n && j-2 >=0 && arr[j-2][i+1] == 1)return false;

    if(i+2 < n && j+1 < n && arr[j+1][i+2] == 1)return false;
    if(i+1 < n && j+2 < n && arr[j+2][i+1] == 1)return false;

    return true;

}

bool PLaceKnight(int** arr,int row,int col,int n,int num){

    if(num <= 0) return true;
    if(row >= n) return false;
    
    
        if(inBounds(arr,row,col,n)){
            arr[row][col] = 1;
            
            if(num == 1) return true;
            
            if(
                PLaceKnight(arr,row-1,(col-1),n,num-1) ||
                PLaceKnight(arr,row-1,(col+1),n,num-1) ||
                PLaceKnight(arr,row+1,(col-1),n,num-1) ||
                PLaceKnight(arr,row+1,(col+1),n,num-1) 
                ) return true;    
                
            arr[row][col] = 0;
            
            return (PLaceKnight(arr,row,(col+1),n,num) || PLaceKnight(arr,row+1,col,n,num));
                
        }

    return false;
}

int main(){
        // Note this solution maximum works for 8x8 order
    cout<<"Enter the order of the square board : ";
    int n;
    cin >> n;
    
    int ** arr = new int*[n];

    for(int i=0;i<n;i++){
        arr[i] = new int[n];
        for(int j=0;j<n;j++) arr[i][j] = 0;
    }
    
    int knightNum = (n*n) / 2;
    
    cout<<"As per the given order "<<knightNum<<" knights can be placed"<<endl;

    cout<<" ==>> The current board is :\n\n";    
    printMatrix(arr,n);

    if(PLaceKnight(arr,0,0,n,knightNum)) cout<<"Solution completed !\n";
    else cout<<"Solution cannot be found !"<<endl;
    
    printMatrix(arr,n);

    return 0;

}