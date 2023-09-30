#include<iostream>
using namespace std;

void printMatrix(int arr[][9]){
    for(int j=0;j<9;j++){
        for(int i=0;i<9;i++) arr[j][i] == 0 ? cout<<"- " : cout<<arr[j][i]<<" ";
        cout<<endl;
    }
}

bool inBounds(int arr[][9],int row,int col,int num){

    if(row<0 || row>=9 || col<0 || col>=9)return false;

    for(int j=0;j<9;j++){
        if(arr[row][j] == num || arr[j][col] == num)return false;
    }
    int startRow,startCol;
    startRow = row - row % 3;
    startCol = col - col % 3;

    for(int j=startRow+1;j<startRow+3;j++){
        for(int i=startCol+1;i<startCol+3;i++){
            if(arr[j][i] == num)return false;
        }
    }

    return true;
}

bool SudokuSolver(int arr[][9],int row,int col){
    
    if(row == 8 && col == 9) return true;
    else if (col == 9){
        row++;
        col = 0;
    }
    
    if(arr[row][col] != 0) return SudokuSolver(arr,row,col+1);

        for(int i=1;i<=9;i++){
            if(inBounds(arr,row,col,i)){
                
                arr[row][col] = i;

                if(SudokuSolver(arr,row,col+1))return true;
                arr[row][col] = 0;
            }    
        }

    return false;
}


int main(){

    int arr [][9] = {
        {4,5,0,0,0,0,0,0,0},
        {0,0,2,0,7,0,6,3,0},
        {0,0,0,0,0,0,0,2,8},
        {0,0,0,9,5,0,0,0,0},
        {0,8,6,0,0,0,2,0,0},
        {0,2,0,6,0,0,7,5,0},
        {0,0,0,0,0,0,4,7,6},
        {0,0,0,0,4,5,0,0,0},
        {0,0,8,0,0,9,0,0,0}
        // WE can also solve it for 0 matrix
        // {0,0,0,0,0,0,0,0,0},
        // {0,0,0,0,0,0,0,0,0},
        // {0,0,0,0,0,0,0,0,0},
        // {0,0,0,0,0,0,0,0,0},
        // {0,0,0,0,0,0,0,0,0},
        // {0,0,0,0,0,0,0,0,0},
        // {0,0,0,0,0,0,0,0,0},
        // {0,0,0,0,0,0,0,0,0},
        // {0,0,0,0,0,0,0,0,0}
                    };
    
    cout<<"The current board is : "<<endl;
    printMatrix(arr);

    if(SudokuSolver(arr,0,0)){
        cout << "Board Solved ! the board appeares as :\n";
        printMatrix(arr);
    }
    else cout << "Unable to solve the board !\n";



    return 0;

}