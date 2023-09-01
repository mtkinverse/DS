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

    void preOrder(Node* node){

        if(node==nullptr) return;

        cout<<node->getValue()<<" ";
        preOrder(node->left);
        preOrder(node->right);

    }

    void preOrder(){

        if(this->root != nullptr){
            cout<<root->getValue()<<" ";
            preOrder(root->left);
            preOrder(root->right);
        }

    }

    void postOrder(){
        
        if(this->root != nullptr){
            postOrder(root->left);
            postOrder(root->right);
            cout<<root->getValue()<<" ";

        }

    }

    void postOrder(Node* node){
        if(node!=nullptr){
            postOrder(node->left);
            postOrder(node->right);
            cout<<node->getValue()<<" ";
        }
    }

    void InOrder(){
        if(this->root != nullptr){
        InOrder(root->left);
        cout<<root->getValue()<<" ";
        InOrder(root->right);
        }
    }

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
 
    bn.getRoot().setValue(2);

    bn.getRoot().left = fillRoot(4);
    bn.getRoot().left->left = fillRoot(1);
    bn.getRoot().left->left->right = fillRoot(7);

    bn.getRoot().right = fillRoot(6);
    
    bn.getRoot().right->right = fillRoot(11);
    bn.getRoot().right->right->right = fillRoot(45);
    bn.getRoot().right->right->left = fillRoot(9);

    bn.getRoot().right->left = fillRoot(3);

    //                              Tree till now                         
    //                                  2                        
    //                                /   \                           
    //                               4     6                             
    //                              /     / \                       
    //                             1     3   11                       
    //                              \       /  \
    //                               7     9    45
   

     bn.preOrder();
     cout<<endl;
     bn.postOrder();
     cout<<endl;
     bn.InOrder();

    return 0;
}