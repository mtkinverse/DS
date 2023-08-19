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
    void enqueueB (int value){

        if(!isFull()){

            Node<type>* n = new Node<type>;
            this->curpos++;
            n->setValue(value);
            back->next = n;
            back=n;
            back->next = nullptr;
        }else cout<<"Cannot enqueue, Queue Full"<<endl;
        
    }
    void enqueueF (int value){

        if(!isFull()){

            Node<type>* n = new Node<type>;
            this->curpos++;
            n->setValue(value);
            Node<type>* p = front->next;
            if(p==nullptr)back=n;
            front->next = n;
            n->next= p;
        }else cout<<"Cannot enqueue, Queue Full"<<endl;
        
    }
    int dequeueF(){
        
        if(!isEmpty()){
            Node<type>* n = front->next;
            front->next = front->next->next;
            int val = n->getValue();
            delete n;
            return val;
        }else {
            cout<<"Cannot deque, Queue is empty !"<<endl;
            return -1;
            }

    }
    int dequeueB(){
        
        if(!isEmpty()){
            Node<type>* n = front->next;
            while ( n->next!=back ) n=n->next; 
            int val = back->getValue(); 
            back=n;
            n=back->next;
            delete back->next;
            back->next = nullptr;
            return val;
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

    void Traverse() {
        Node<type>* n = front->next;
        cout<<"The que is : ";
        while(n->next != nullptr) {
            cout<<n->getValue()<<" ";
            n=n->next;
            }
            cout<<n->getValue()<<endl;
    }

};

int main()
{
    Queue<int> que(10);

    que.enqueueF(2);
    que.enqueueF(45);
    que.enqueueF(43);
    que.Traverse();
    
    que.enqueueB(100);
    que.enqueueB(19);
    que.Traverse();
    
    que.dequeueB();
    que.dequeueF();
    que.Traverse();
    que.Traverse();
    que.enqueueB(55);
    que.Traverse();
return 0;    

}