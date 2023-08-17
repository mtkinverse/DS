#include<iostream>
using namespace std;

template <class type>
 struct Node{
    type value;
    struct Node<type>* next;
};

template < class t>

class Stack{

struct Node<t>* top;
int size,curPos;

public:

Stack(){}
Stack(int size){
    top=new struct Node<t>;
    top->value=-1;
    top->next=nullptr;
    this->size=size+1;
    this->curPos=0;
}
void push(int val){
 if(!isFull()){
    struct Node<t> * p=new struct Node<t>;
    p->next=top;
    p->value=val;
    top=p;
    this->curPos++;
 }else cout<<"Stack overflowed"<<endl;
}

t pop(){
    if(!isEmpty()){
        int val=top->value;
        struct Node<t> * cur=top;
        top=top->next;
        this->curPos--;
        free(cur);
        return val;
    }else {
        cout<<"stack underflowed !"<<endl;
        return sizeof(t);
    }
}
bool isEmpty(){
    if(top->next==nullptr)return true;
    else return false;
}
bool isFull(){
    if(this->curPos>=this->size-1)return true;
    else return false;
}
};

int main(){
    Stack <int> stack(5);
    while(!stack.isFull()){
        int val;
        cout<<"Enter the value : ";
        cin>>val;
        stack.push(val);
    }
    cout<<endl<<"The stack is : ";
    while(!stack.isEmpty()) cout<<stack.pop()<<" ";
    cout<<endl;
    cout<<stack.pop();  

    return 0;
}