#include<iostream>
using namespace std;

void printMatrix(char** arr,int n){
    for(int j=0;j<n;j++){
        for(int i=0;i<n;i++) cout<<arr[j][i]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

bool inBounds(char** arr,int row,int col,int n){
    if(col<0 || row<0 || col>=n || row>=n || arr[row][col]=='V' || arr[row][col] == 'W') return false;
    else return true;
}

void CountTrees(char** arr,int row,int col,int n,int& numTrees){

    if(inBounds(arr,row,col,n)){
        char thisONe = arr[row][col];
        arr[row][col] = 'V';
        numTrees ++;
        CountTrees(arr,row,col+1,n,numTrees);
        CountTrees(arr,row+1,col,n,numTrees);
        CountTrees(arr,row,col-1,n,numTrees);
        CountTrees(arr,row-1,col,n,numTrees);
    }

}

int main( ){

int n;
cin>>n;

char** arr;
arr = new char*[n];

for(int i=0;i<n;i++) {
    arr[i] = new char[n];
    for(int j=0;j<n;j++){
        if(rand() % 2 == 0)arr[i][j] = 'T';
        else arr[i][j] = 'W';
    }
    }

printMatrix(arr,n);
int max = 0;
for(int j=0;j<n;j++)
 for(int i=0;i<n;i++){

    if(arr[j][i] == 'T'){
        
        int numOnes = 0;
        
        CountTrees(arr,j,i,n,numOnes);

        if(numOnes > max) max = numOnes;
        
    }

}
   
   cout<<"The maximum number of trees are : "<<max<<endl;

return 0;

}