#include<iostream>
using namespace std;


// Here the binary and interpolation search is compared with 10000 elements


void PrintArr(int arr[],int n){
    for(int i=0;i<n;i++) cout << arr[i]<<" ";
    cout << endl;
}

template <class t>
class Node{
    
    public:

    t value;
    Node<t>* next;

    Node(){
        this->value = 0;
        this->next = nullptr;
    }
    Node(t value){
        this->value = value;
        this->next = nullptr;
    }

};

template <class t>
class SinglyLinkedList{
    
    Node<t> *head,*tail;
    
    public:

    SinglyLinkedList(){
        head = nullptr;
    }

    void InsertAtEnd(int value){

        if(head != nullptr){
            tail->next = new Node<t>;
            tail->next->value = (value);
            tail = tail->next;
        }
        else{
            head = new Node<t>;
            head->value = (value);
            tail = head;
        }
        
    }

    bool Contains(t val){
        Node<t>* temp = head;
        while(temp != nullptr) {
            if(temp->value == val) return true;
            temp = temp->next;
        }
        return false;
    }

};

void MergeSort(int arr[],int low,int high){

    if(low >= high) return;

    int mid = (low + high)/2;
    int* copy = new int[high - low + 1]{0};

    MergeSort(arr,low,mid);
    MergeSort(arr,mid+1,high);

    int i = low;
    int j = mid+1;
    int k=0;

    while(i<=mid && j<=high){
        if(arr[i]<arr[j]) copy[k++] = arr[i++];
        else copy[k++] = arr[j++];
    }

    while(i<=mid) copy[k++] = arr[i++];
    while(j<=high) copy[k++] = arr[j++];

    int copy_ind = 0;
    for(int i=low;i<=high;i++,copy_ind++) arr[i] = copy[copy_ind];
    
    delete[] copy;
    copy = nullptr;

}

int ReturnMax(int arr[],int n){
    int max = 0;

    for(int i=1;i<n;i++) if(arr[max] < arr[i])max = i;

    return arr[max];

}

// We have to check the unifomity bcause interpolation search works on the array that is uniform , having equal number of frequencies of every element
// The lower the uniformity the lower the proper working chances of interpolation search would be. 

float FindUniformity(int arr[],int n){
    
    int max = ReturnMax(arr,n);
    int* freqArr = new int[max + 1]{0};

    for(int i=0;i<n;i++) freqArr[arr[i]]++;
    
    SinglyLinkedList<int> Distinct;
    int numberOfWords = 0;

    for(int i=0;i<=max;i++){
        if(freqArr[i] == 0)continue;

        if( ! Distinct.Contains(freqArr[i])){
            Distinct.InsertAtEnd(freqArr[i]);
            numberOfWords++;
            bool found = false;

            for(int j=i+1;j<=max;j++) if(freqArr[i] == freqArr[j]){
                found = true;
                numberOfWords++;
            }

            if(!found)
            numberOfWords--;

        }
        
    }

    delete[] freqArr;
    return (float)numberOfWords/max;
    
}

int BinarySearch(int arr[],int low,int high,int val ){
	
	if(low >= high) return -1;
	
	int mid = (low + high)/2;
	
	if(arr[low] == val) return low;
	if(arr[high] == val) return high;
	if(arr[mid] == val) return mid;
	
	if(val < arr[mid]) return BinarySearch(arr,low,mid - 1,val);
	else return BinarySearch(arr,mid + 1,high,val);
	
}

int InterpolationSearch(int arr[],int low,int high,int key){
    if(low>high) return -1;
    
    int ind = low + ( ( (high-low) / (arr[high]-arr[low]) ) * (key - arr[low]));
    
    if(arr[low]==key) return low;
    else if(arr[high]==key) return high;
    else if(arr[ind]==key) return ind;

    if(key > arr[ind]) return InterpolationSearch(arr,ind+1,high,key);
    else return InterpolationSearch(arr,low,ind-1,key);
    
}

int main(){

    // int arr[] = {1,2,4,1,7,4,9,11};
    srand(time(NULL));

    int n = 10000;
    int* arr = new int[n];
    printf("\t--------------------------------------------------------------------------\n");
    printf("%10s ||%-20s | %-20s | %-20s||\n\n","","Uniformity(%)","Binary search(sec)","Interpolation Search(sec)");
    printf("\t--------------------------------------------------------------------------\n");

    for(int k=0;k<100;k++){
        
        for(int i=0;i<n;i++) arr[i] = 1 + rand() % 100;

        float uniformity = FindUniformity(arr,n)*100;

        MergeSort(arr,0,n-1);

        int val;
        val = 1 + rand()%100;

        clock_t before,after;
        float t1,t2;

        before = clock();
        BinarySearch(arr,0,n-1,val);
        after = clock();

        t1 = (after - before)/(float)CLOCKS_PER_SEC;    

        before = clock();
        InterpolationSearch(arr,0,n-1,val);
        after = clock();

        t2 = (after - before)/(float)CLOCKS_PER_SEC;    

        printf("%10s|| %-20.4f| %-20.4f| %-20.4f||\n","",uniformity,t1,t2);

    }
    return 0;
    
}

