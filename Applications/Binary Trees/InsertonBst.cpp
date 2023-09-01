#include<iostream>
#include<stdlib.h>
using namespace std;

class Node{
    int data;
    public:
    Node *left,*right;
    Node(){
        data = 0;
        left=right= nullptr;
    }
    Node(int val){
        data = val;
        left=right= nullptr;
    }
    int getValue () const{
        return this->data;
    }
    void setValue(int val){ this->data = val;}
};

class BinaryTree{

    Node *root;

    public:
    
    BinaryTree(){ root = new Node; }

    Node& getRoot() const { return *this->root; }

    bool CheckBst(){
        return CheckBst(this->root);
    }

    bool CheckBst(Node* curRoot ){
        
        static Node* prev;
        prev = nullptr;

        if(curRoot != nullptr){
            if(!CheckBst(curRoot->left))return false;
            if(prev!=nullptr && prev->getValue()>=curRoot->getValue())  return false;
            prev = curRoot;
            return CheckBst(curRoot->right);
        }
        else return true;

    }

    bool Insert(int value){

        Node* prev ,*curRoot;
        prev = curRoot = this->root;

        while (prev!=nullptr)
        {   
            curRoot = prev;
            if(value == prev->getValue())return false;
            if(value<prev->getValue())prev = prev->left;
            else prev= prev->right;
        }
        
        if(value < curRoot->getValue()){
            curRoot->left = new Node(value);
        }
        else {
            curRoot->right = new Node(value);
            }
        return true;
        
    }
    
    void InOrder(){ InOrder(this->root);}

    void InOrder(Node* node){
        if(node!=nullptr){
            InOrder(node->left);
            cout<<node->getValue()<<" ";
            InOrder(node->right);
        }
    }
    

};


Node* fillRoot(int value){
    
    Node* node = new Node;
    node->setValue(value);
    return node;

}

int main(){
    
    BinaryTree bn;
 
    bn.getRoot().setValue(5);

    bn.getRoot().left = fillRoot(4);
    bn.getRoot().left->left = fillRoot(1);
    bn.getRoot().left->left->right = fillRoot(2);

    bn.getRoot().right = fillRoot(7);
    
    bn.getRoot().right->right = fillRoot(11);
    bn.getRoot().right->right->right = fillRoot(45);
    bn.getRoot().right->right->left = fillRoot(9);

    bn.getRoot().right->left = fillRoot(6);

    //                              Tree till now                         
    //                                  5                        
    //                                /   \                           
    //                               4     7                             
    //                              /     / \                       
    //                             1     6   11                       
    //                              \       /  \
    //                               2     9    45
   
   cout<<"Before Modification : ";
   bn.InOrder();
   cout<<endl;
    int ch = 1;
    if(bn.CheckBst()){
        while(ch){
       cout<<"Enter the value you want to insert : ";
        int temp;
        cin>>temp;
        if(bn.Insert(temp))cout<<"The value has beem inserted !"<<endl;
        else cout<<"The value cannot be inserted !\n";

        cout<<" --> Enter 0 to exit or Enter any integer to insert more\n";
        cin>>ch;
        }
    }

   cout<<"After updating : ";
   bn.InOrder();
   cout<<endl;

    if(bn.CheckBst())cout<<"Still binary tree\n";
    else cout<<"Not Binary tree !\n";

    return 0;
    
}