#include <iostream>
using namespace std;
// In this problem the list is given with the values and it is sorted in such a way that all the evens comes
// before the odd . Consequently, the even values would be on the LHS and odd values would be on RHS.
class Node
{
public:

    int  data;
    Node *next;

    Node()
    {
         data = 0;
        next = nullptr;
    }

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }

};

class SinglyLinkedList
{
public:

    Node *head; // Note, only using head for pointing , not using its data

    SinglyLinkedList()
    {
        head = new Node();
    }

    void insert_tail(int value){

        if(NodeExist(value)){
            cout<<" A node with a value "<<value<<" already exist !"<<endl;
        }
        else
         {
            Node* n = head;
            while(n->next != nullptr) n=n->next;
            n->next = new Node(value);
        }   

    }

    bool NodeExist(int value){

        Node* n = head->next;

        while(n != nullptr && n->data != value) n=n->next;
        
        if(n != nullptr && n->data == value) return true;
        else return false;

    }

    void traverse(){

        Node* n = head->next;

        while(n != nullptr) {
            cout<<n->data<<" ";
            n=n->next;
            }
    }
    
};

int main()
{
    SinglyLinkedList list;
    
    cout<<"How many elements do you want in list : ";
    int n;
    cin>>n;

    cout<<"\nNote repeated elements cannot be inserted ! \n\n";

    for(int i=0;i<n;i++)
    {
        cout<<"Enter the value you want to insert : ";
        int temp;
        cin>>temp;
        list.insert_tail(temp);
    }
    
    cout<<"The list is : ";
    list.traverse();
    cout<<endl;

    return 0;
}