#include<iostream>
#include<string>
using namespace std;

class Queue{
    int front,back,size;
    int * arr;
    public:
    Queue(){front=back=0;size=0;arr=nullptr;}
    Queue(int size){
        front=back=0;//Here we declared front and back 0 because if front would be before index (-1) the terminating condition (back+1)%size == front would never be acheived
        this->size=size;
        arr= new int[size];
    }
    bool isEmpty(){
        if(front==back)return true;
        else return false;
    }
    bool isFull(){
        if((back+1)%size == front)return true;
        else return false;
    }
    void enque(int val){
        if(!isFull()){
        this->back = (this->back+1)%this->size;
        arr[this->back]=val;
        }
        else throw runtime_error("Cannot enqueue, the que has been full !\n");
    }
    int deque(){
        if(!isEmpty()){
        this->front = (this->front+1)%this->size;
        return arr[this->front];
        }
        else throw runtime_error("cannot dequeue, the que is empty !\n");
    }
    int FrontValue(){
        if(!isEmpty())return arr[this->front];
        else throw runtime_error("Front value cannot be accessed !\n");
    }
    int BackValue(){
        if(!isEmpty())return arr[this->back];
        else throw runtime_error("Back value cannot be accessed !\n");
    }
    int Peek(int pos){
        int reqInd = this->front+pos;
        if(reqInd >= size || reqInd <= this->front) throw runtime_error("Cannot, peek to the given position");
        return arr[reqInd];    
    }
};

int main(){

    Queue que(10);
 try{

  
    while(!que.isFull()){
        int val;
        cout<<"Enter value : ";
        cin>>val;
        que.enque(val);
    }
    
    cout<<endl<<"At position 5 the value is : "<<que.Peek(5)<<endl<<"The que entered is : ";
    while(!que.isEmpty()) cout<<que.deque()<<" ";
    cout<<endl;

    que.enque(11);
    cout<<que.deque()<<endl;

    que.deque();//This would through an error
}
catch(runtime_error e){

    cout<<e.what()<<endl;

}
    return 0;

}