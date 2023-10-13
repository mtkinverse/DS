#include<iostream>
using namespace std;

// This code finds the permutation (all possible combinations) of letters , defined by the user

void findPermutations(string&str,int start,int size){
	if(start==size)	cout<<str<<endl;
	else{

		for(int i=start;i<=size;i++){
			swap(str[start],str[i]);
			findPermutations(str,start+1,size);
			swap(str[start],str[i]);
		}
	}
}

int main(){

    int n;
    cout<<"Enter n: ";
    cin>>n;
    
    char letter='a';
    string str="";
    
    for(int i=1;i<=n;i++,letter++){
    	str+=letter;
    }
    
    findPermutations(str,0,n-1);
    
    return 0;
}
