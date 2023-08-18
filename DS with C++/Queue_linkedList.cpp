#include<iostream>
#include<string>
using namespace std;

template <class t>
class Node{
    t value;
public:
    Node<t>*next;
    Node(){
        value=-1;
        next=nullptr;
    }
    Node( t value ){
        this->value=value;
        this->next=nullptr;
    }
    t getValue(){ return this->value;}
    void setValue(t value){ this->value=value; }
};

template <class type>
class Queue{
    
    int size,curpos;
    Node<type> *back,*front;

public:

    Queue(int size){
        
        this->size=size;
        this->curpos = 0;
        back=new Node <type>;
        front=back;

    }
    bool isEmpty(){
        
        if(front->next==nullptr)return true;
        else return false;

    }
    bool isFull(){
        
        if(curpos>=size)return true;
        else return false;

    }
    void enqueue(int value){

        if(!isFull()){

            Node<type>* n = new Node<type>;
            this->curpos++;
            n->setValue(value);
            back->next = n;
            back=n;
            n->next = nullptr;
        }else cout<<"Cannot enqueue, Queue Full"<<endl;
        
    }
    int dequeue(){
        
        if(!isEmpty()){
            Node<type>* n = front;
            front=front->next;
            delete n;
            return front->getValue();
        }else {
            cout<<"Cannot deque, Queue is empty !"<<endl;
            return -1;
            }

    }
    int peek(int pos){
        
        Node<type>* p =front;
        int i=0;
        
        while(i<pos && p->next!=nullptr) {
            p=p->next;
            i++;
            }

        if(i==pos)return p->getValue();
        else {
            cout<<"Unable to peek at the given position !"<<i<<" "<<pos<<endl;
            return -1;
        }
        
    }

};

int main()
{
    Queue<int> que(5);

    while(!que.isFull()){
        cout<<"Enter the value : ";
        int n;
        cin>>n;
        que.enqueue(n);
    }

    cout<<"The value at  position 5 is : "<<que.peek(5)<<endl;
    cout<<"The queue is : ";
    
    while (!que.isEmpty())cout<<que.dequeue()<<" ";
    cout<<endl;
    
    cout<<que.dequeue();

return 0;    

}