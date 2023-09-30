#include<iostream>
using namespace std;

void printMatrix(char** arr,int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)cout << arr[i][j]<<" ";
        cout << endl;
    }
    cout<<endl;
}

bool isSafe(char** arr,int row,int col,int m,int n,char arr2[],int ind){
    if(col<0 || row<0 || col>=n || row>=m) return false;
    else return arr[row][col] == arr2[ind];
}

void FindWord(char** arr,int row ,int col,int m,int n,char arr2[],int ind,int& coutWord){
    if(ind == m-1 && arr[row][col] == arr2[ind]){
        coutWord++;
        return;
    }
    if(isSafe(arr,row,col,m,n,arr2,ind)){
        coutWord++;
        FindWord(arr,row,col+1,m,n,arr2,ind+1,coutWord);
        FindWord(arr,row+1,col,m,n,arr2,ind+1,coutWord);
        FindWord(arr,row,col-1,m,n,arr2,ind+1,coutWord);
        FindWord(arr,row-1,col,m,n,arr2,ind+1,coutWord);
    }
}

int main(){
    srand(time(NULL));

    char** arr = new char*[4];
    for(int i=0;i<4;i++){
        arr[i] = new char[5];
        for(int j=0;j<5;j++) arr[i][j] = 65 + rand() % 26;
    }

    cout << "The current matrix is :\n";
    printMatrix(arr,4,5);

    cout<<"Enter the word you wnat to find : ";
    char a[5] = {'\0'};
    cin>>a;
    
    int totalWrods = 0;
    int curWord;
    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++){
            curWord = 0;
            if(arr[i][j] == a[0]){
                FindWord(arr,i,j,4,5,a,0,curWord);
            }
            totalWrods +=  curWord/4;
        }
    }

    cout<<"The total number of words are : "<<totalWrods<<endl;
    
}