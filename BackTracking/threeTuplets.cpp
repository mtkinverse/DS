#include<iostream>
using namespace std;

// This code checks all the three elements in given array whose sum leads to zero, and stores the indexes in a matrix.

    int ** threeSum(int nums[],int n) {
        int i,j,k;
        int l=0;
        int** arr = new int*[n]{NULL};

        for(j=0;j<n-2;j++){
            for(i=j+1;i<n-1;i++){
                for(k=i+1;k<n;k++){
                    if(nums[j]+nums[i]+nums[k] == 0){
                        
                        arr[l]=new int[3]{0};
                        arr[l][0] = j;
                        arr[l][1] = i;
                        arr[l][2] = k;
                        l++;
                        
                    }
                }
            }
        }
        return arr;
    }

int main(){
	
	int arr[ ] = {-1,0,1,2,-1,-2};
	int n = sizeof(arr)/sizeof(int);
	
	int ** p = threeSum(arr,n);
	
	
	for(int j=0;j<n;j++){
		if(p[j] != NULL){
			for(int i=0;i<3;i++) cout << p[j][i] <<" ";
	        cout << endl;
		}
	}
	return 0;
}
