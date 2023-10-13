#include<iostream>
#include<string>

using namespace std;

class Books{
	string* arr;
	int noBooks;
	public:
	
	Books(){
		arr = NULL;
		noBooks = 0;
	}
	
	Books(const Books& obj){
		arr = new string[obj.noBooks];
		for(int i=0;i<obj.noBooks;i++) arr[i] = obj.arr[i];
	}
	
	void operator = (const Books& obj){
		arr = new string[obj.noBooks];
		for(int i=0;i<obj.noBooks;i++) arr[i] = obj.arr[i];
	}
	
	void AddNewBook(string val){
		string* newArr =new string[++noBooks];
		
		for(int i=0;i<noBooks-1;i++) newArr[i] = arr[i];
		
		arr = new string[noBooks];
		
		for(int i=0;i<noBooks;i++) arr[i] = newArr[i];
		
		arr[noBooks-1] = val;
		
		delete[] newArr;
	}
	
	void shellSort(){
		for(int size=noBooks;size>0;size/=2){
			for(int j=size;j<noBooks;j++){
			
			string key = arr[j];
			int i;
			for(i=j;i-size >= 0 && arr[i-size] > key; i-=size) arr[i] = arr[i-size];
			arr[i] = key;
		}
		}
	}
	
	void Print(){
		for(int i=0;i<noBooks;i++) cout << " - " << arr[i] << endl;
	}
	~Books(){
		delete[] arr;
	}
};

int main(){
	
	Books obj;
	
	obj.AddNewBook("Harry");
	obj.AddNewBook("Adaptive");
	obj.AddNewBook("Zero");
	obj.AddNewBook("Horror");
	obj.AddNewBook("Bord");
	obj.AddNewBook("Ball in space");
	
	cout << "==>> Before sorting :\n\n";
	obj.Print();
	
	obj.shellSort();
	
	cout << "\n==>> After sorting :\n\n";
	obj.Print();
	
	
	return 0;
}
