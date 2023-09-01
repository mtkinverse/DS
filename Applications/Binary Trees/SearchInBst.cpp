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

    Node& SearchKey(int value){
       return SearchKey(this->root,value);
    }

    Node& SearchKey(Node* ptr, int value){
        if(ptr == nullptr)return *(new Node);
        if(ptr->getValue() == value )return *ptr;
        if(ptr->getValue()>value) return SearchKey(ptr->left,value);
        else return SearchKey(ptr->right,value);
    }

    Node* SearchKeyIteratively(int value){
        Node* p = this->root;
        while(p!=nullptr){
            if(p->getValue() == value) return p;
            else if(p->getValue() > value) p = p->left;
            else p = p->right;
        }
        return nullptr;
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
   
   cout<<"Before insertion : ";
   bn.InOrder();
   cout<<endl;

    if(bn.CheckBst()){
        Node& n1 = bn.SearchKey(11);
        n1.setValue(10);
        Node* n2 = bn.SearchKeyIteratively(7);
        if (n2 == nullptr) cout<<"The key is not found !\n";
        else n2->setValue(8);
    }

   cout<<"After updating : ";
   bn.InOrder();
   cout<<endl;



    return 0;
}