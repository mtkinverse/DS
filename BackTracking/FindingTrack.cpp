#include<iostream>
#include<cstdlib>
using namespace std;

void printMatrix(int** arr,int m,int n){
    for(int j=0;j<m;j++){
        for(int i=0;i<n;i++) cout<<arr[j][i]<<" ";
        cout<<endl;
    }
}

bool inBounds(int** arr,int row,int col,int m,int n){
    if(row<0 || row>=m || col<0 || col>=n || arr[row][col] == 1) return false;
    else return true;
}

bool FindRoute(int** arr,int row,int col,int m,int n){

    
    if(row == m-2 && col == 0 && arr[row][col] == 0) {
        arr[row][col] = 2;
        return true;
    }
    
    if(inBounds(arr,row,col,m,n)){

        if(arr[row][col] == 2) return false;    //checking if visited
        
        int value = arr[row][col];
        arr[row][col] = 2;                      // marking visited
    
        
        if(FindRoute(arr,row+1,col,m,n)) return true;
        if(FindRoute(arr,row,col+1,m,n)) return true;
        if(FindRoute(arr,row-1,col,m,n)) return true;
        if(FindRoute(arr,row,col-1,m,n)) return true;
        
        arr[row][col] = value;
        return false;

    }

    else return false;

}


int main(){

    srand(time(0));

    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    int ** arr = new int*[n];

    for(int i=0;i<n;i++){
        arr[i] = new int[n];
        for(int j=0;j<n;j++) {
            arr[i][j] = rand() % 4;

            if(arr[i][j] < 3) arr[i][j] = 0;
            else arr[i][j] = 1;
            
            }
    }

    arr[1][n-1] = 0;
    arr[n-2][0] = 0;

    cout<<"The current matrix is :\n";    
    
    printMatrix(arr,n,n);
    
    if(FindRoute(arr,1,n-1,n,n)) cout<<"\n ==>> Path exist !\n";
    else cout<<"\n ==>> Path does not found !\n";

    return 0;
}