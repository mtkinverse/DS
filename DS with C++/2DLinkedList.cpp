#include<iostream>
using namespace std;

class DoubleNode
{
    int data;

public:
    DoubleNode *next, *prev;

    DoubleNode()
    {
        this->data = 0;
        this->next = this->prev = nullptr;
    }

    DoubleNode ( int data )
    {
        this->data = data;
        this->next = this->prev = nullptr;
    }

    void setValue(int value) { this->data = value; }
    int getValue() const { return this->data; }

};

class ListHeader{

    public:
    DoubleNode* head,*tail;
    ListHeader* next;

    ListHeader(){ head = tail = nullptr; next = nullptr; }

};

class LinkedList2D{

    ListHeader* head,*tail ;
    int curInd;

    public:
    
    LinkedList2D(){ head = tail = nullptr; curInd = -1; }

    void createNewList(){
        if(tail == nullptr){
            head = tail = new ListHeader();
            curInd++ ;
        }else{
            ListHeader *temp = new ListHeader();
            tail->next = temp;
            tail = temp;
            curInd++ ;
        }
    }

    ListHeader* GiveNode(int ind){
        if(ind > curInd || ind < 0 || tail == nullptr)return nullptr;
        else
        {
            ListHeader *temp = head;
            for(int i=0; i<ind ; i++) temp = temp->next;

            return temp;
        }
    }

    void InsertAttail(int value,int index){
        
        if(index > curInd || index < 0) cout<<"Out of bounds !\n";
        else {
            
            ListHeader* temp = GiveNode(index);
            
            if(temp->tail == nullptr){
                temp->head = temp->tail = new DoubleNode(value);
            }
            else{
                DoubleNode *d = new DoubleNode(value);
                d->prev = temp->tail;
                temp->tail->next = d;
                temp->tail = d;
            }

                temp->tail->next = temp->head;    
                temp->head->prev = temp->tail;
        }

    }

    void InsertAtHead(int value, int index){
         if(index > curInd || index < 0) cout<<"Out of bounds !\n";
        else {
            
            ListHeader* temp = GiveNode(index);
            
            if(temp->tail == nullptr){
                temp->head = temp->tail = new DoubleNode(value);
            }
            else{
                DoubleNode *d = new DoubleNode(value);
                d->next = temp->head;
                temp->head->prev = d;
                temp->head = d;
            }

                temp->tail->next = temp->head;    
                temp->head->prev = temp->tail;
        }

    }

    void InsertAfterIndex(int value,int index,int listInd){
        if(listInd > curInd || listInd < 0) cout << "Out of bonds !\n";
        else
        {
            ListHeader* temp = GiveNode(listInd);

            DoubleNode *d = temp->head;
            for(int i = 0; i < index && d != nullptr; i++) d = d->next; 

            if ( d == nullptr ){
                cout << "Out of bonds, the provided list does not contains the given index !\n";
                return;
            }
            
            DoubleNode *d1 = new DoubleNode(value);
            d1->next = d->next;
            d1->prev = d;
            d->next->prev = d1;
            d->next = d1;

            if(d == temp->tail) temp->tail = d;         
        }
    }

void DelteAtIndex(int index,int listInd){
        if(listInd > curInd || listInd < 0) cout << "Out of bonds !\n";
        else
        {
            ListHeader* temp = GiveNode(listInd);

            DoubleNode *d = temp->head;
            for(int i=0 ; i<index && d!=nullptr ; i++) d = d->next;

            if(d == nullptr){
                cout << "The given list does not contain the specified index !\n";
                return;
            }

            d->prev->next = d->next;
            d->next->prev = d->prev;

            if(d == temp->head) temp->head = d->next;
            else if(d == temp->tail) temp->tail = d->prev; 
            
            d->next = d->prev = nullptr;

            delete d;
        }
    }

    void UpdateIndex(int value,int index,int listInd){
        ListHeader *temp = GiveNode(listInd);
        if(temp == nullptr){
            cout<<"Out of bonds !\n";
            return;
        }
        else
        {
            DoubleNode *d = temp->head;
            for(int i=0 ; i<index && d!=nullptr ; i++) d = d->next;

            if(d == nullptr) cout<<"You are accessing out of bonds in the provided list index !\n";
            else
            {
                d->setValue(value);
            }

        }
    }

    void printAt(int index) const {
        
        if(index > curInd || index < 0) cout<<"Out of bonds !\n";
        else
        {
            ListHeader *temp = head;
            
            for(int i=0; i<index; i++) temp = temp->next;

            DoubleNode * d = temp->head;
            do
            {
                cout<<d->getValue()<<" ";
                d = d->next;
            }
            while (d != temp->head);
            cout<<endl;

        }
    }

    void Display () const {
        for(int i=0;i<=curInd;i++) printAt(i);
    }
};

int main(){

    LinkedList2D khatarnak;

    khatarnak.createNewList();

    khatarnak.InsertAttail(45,0);
    khatarnak.InsertAttail(4,0);
    khatarnak.InsertAttail(25,0);
    khatarnak.InsertAttail(13,0);

    khatarnak.createNewList();

    khatarnak.InsertAttail(11,1);
    khatarnak.InsertAttail(3,1);
    khatarnak.InsertAttail(0,1);
    khatarnak.InsertAttail(6,1);

    cout<<"After tail insertion the lists are :\n";
    khatarnak.Display();

    khatarnak.InsertAtHead(14,1);
    khatarnak.InsertAtHead(23,1);

    khatarnak.InsertAtHead(56,0);
    khatarnak.InsertAtHead(35,0);
    
    cout<<"After head insertion the lists are :\n";
    khatarnak.Display();
    
    khatarnak.InsertAfterIndex(77,3,0);
    khatarnak.InsertAfterIndex(41,5,1);
    
    cout<<"After insertion at specified points the lists are :\n";
    khatarnak.Display();

    khatarnak.DelteAtIndex(0,0);
    khatarnak.DelteAtIndex(5,0);

    khatarnak.DelteAtIndex(0,1);
    khatarnak.DelteAtIndex(4,1);

    cout<<"After deletion at specified index the lists are :\n";
    khatarnak.Display();

    khatarnak.UpdateIndex(0,1,0);
    khatarnak.UpdateIndex(56,3,1);

    cout<<"After updating at specified point the lists are :\n";
    khatarnak.Display();

    return 0;

}