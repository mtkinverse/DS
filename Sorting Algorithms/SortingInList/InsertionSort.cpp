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

    cout << "Bfore Sorting : ";
    list.Traverse();

    list.InsertionSort();

    cout << "After sorting : ";
    list.Traverse();

    cout << "Checking insertion : ";
    list.InsertAtEnd(3);
    list.Traverse();
    
    return 0;
}