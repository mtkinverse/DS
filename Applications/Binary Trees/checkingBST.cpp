#include<iostream>
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
        static Node* prev = nullptr;
        if(curRoot != nullptr){
            if(!CheckBst(curRoot->left))return false;
            if(prev!=nullptr && prev->getValue()>=curRoot->getValue())return false;
            prev = curRoot;
            return CheckBst(curRoot->right);
        }else return true;
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
   
    if(bn.CheckBst())cout<<"The current tree is binary tree"<<endl;
    else cout<<"Not a binary tree"<<endl;

    return 0;
}