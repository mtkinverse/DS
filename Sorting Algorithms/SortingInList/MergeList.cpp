#include<iostream>
using namespace std;

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

    void InsertionSort(){

        Node<t> *sorted,*next,*cur,*temp;
        sorted = nullptr;
        temp = head;

        while(temp != nullptr){

            next = temp->next;

            if(sorted == nullptr || sorted->value >= temp->value){
                temp->next = sorted;
                sorted = temp;
            }
            else{

                cur = sorted;
                while(cur->next != nullptr && temp->value > cur->next->value) cur = cur->next;
                
                if(cur != nullptr){
                    temp->next = cur->next;
                    cur->next = temp;
                }

            }
            tail = temp;
            temp = next;
        }
        this->head = sorted;

    }

    void Traverse() const {
        Node<t>* temp = head;
        while(temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }

// Both the parameter lists are already sorted
    void MergeList(SinglyLinkedList& l1,SinglyLinkedList& l2){
        Node<t> *temp1,*temp2,*temp;
        temp1 = l1.head;
        temp2 = l2.head;
        
        
        if(temp1->value < temp2->value){
            head = temp = temp1;
            temp1 = temp1->next;
        }else{
            head = temp = temp2;
            temp2 = temp2->next;
        }

        while(temp1 != nullptr && temp2 != nullptr){
            if(temp1->value < temp2->value){
                temp->next = temp1;
                temp1 = temp1->next;
            }else{
                temp->next = temp2;
                temp2 = temp2->next;
            }
            tail = temp;
            temp = temp->next;
        }
        while(temp1 != nullptr){
            temp->next = temp1;
            tail = temp1;
            temp1 = temp1->next;
            temp = temp->next;
        }
        while(temp2 != nullptr){
            temp->next = temp2;
            tail = temp2;
            temp2 = temp2->next;
            temp = temp->next;
        }

    }
};

int main(){
    SinglyLinkedList<int> list;
    list.InsertAtEnd(6); 
    list.InsertAtEnd(7); 
    list.InsertAtEnd(0); 
    list.InsertAtEnd(2); 
    list.InsertAtEnd(11); 
    list.InsertAtEnd(3); 
    list.InsertAtEnd(9);

    SinglyLinkedList<int> list2;
    list2.InsertAtEnd(5); 
    list2.InsertAtEnd(1); 
    list2.InsertAtEnd(6); 
    list2.InsertAtEnd(4); 
    list2.InsertAtEnd(9); 
    list2.InsertAtEnd(4); 

    list.InsertionSort();
    list2.InsertionSort();

    SinglyLinkedList<int> SortedList;
    SortedList.MergeList(list,list2);
    SortedList.Traverse();
    return 0;
}