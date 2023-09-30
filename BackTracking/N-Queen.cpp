#include<iostream>
using namespace std;

void printMatrix(int** arr,int m,int n){
    for(int j=0;j<m;j++){
        for(int i=0;i<n;i++) cout<<arr[j][i]<<" ";
        cout<<endl;
    }
}

bool inBounds(int** arr,int row,int col,int n){

    int i,j;

    for(i=0;i<row;i++) if(arr[i][col] == 1) return false;
    for(i=col,j=row ; i>=0 && j>=0 ; i--,j--) if(arr[j][i] == 1) return false;
    for(i=col,j=row ; i<n && j>=0 ; i++,j--) if(arr[j][i] == 1) return false;
    
    return true;

}

bool SolveQueen(int** arr,int row,int n){
    
    if(row == n) return true;
    
    for(int i=0;i<n;i++){
        if(inBounds(arr,row,i,n)){
            arr[row][i] = 1;
            if(SolveQueen(arr,row+1,n)) return true;
            arr[row][i] = 0;
        }
    }

        return false;

    
}

int main(){

    int n;
    cout<<"Enter the size of board : ";
    cin>>n;

    int ** arr = new int*[n];

    for(int i=0;i<n;i++){
        arr[i] = new int[n];
        for(int j=0;j<n;j++) arr[i][j] = 0;
    }
    
    cout<<" ==>> The current board is :\n\n";    
    
    printMatrix(arr,n,n);
    cout<<endl;

    if(SolveQueen(arr,0,n)){
        cout<<"The board has been solved !\n";
        printMatrix(arr,n,n);
    }
    else cout<<"The board cannot be solved !\n";

    return 0;
}