#include <iostream>
using namespace std;

class Node
{
public:
    Node *prev, *next;
    int value;

    Node()
    {
        this->prev = nullptr;
        this->next = nullptr;
        this->value = 0;
    }
    Node(Node &prev, Node &next, int value)
    {
        this->prev = &prev;
        this->next = &next;
        this->value = value;
    }
    void setValue(int value) { this->value = value; }
    int getValue() { return this->value; }
};

class Stack
{
    int size, curPos;
    Node *top;

public:
    Stack()
    {
        this->size = 0;
        this->top = nullptr;
    }
    Stack(int size)
    {
        this->top = new Node();
        this->size = size+1;
        this->curPos = 1;
    }
    void push(int val)
    {
        if (!isFull())
        {
            Node *p = new Node;
            this->top->next = p;
            p->next = nullptr;
            p->prev = top;
            p->value = val;
            top = p;
            this->curPos++;
        }
    }
    int pop()
    {

        if (!isEmpty())
        {
            int val = top->value;
            if (top->prev != nullptr)
            {
                top = top->prev;
                free(top->next);
                top->next = nullptr;
            }
            else
            {
                top->next=top->prev;
            }
            this->curPos--;
            return val;
        }
        else
            return -1;
    }

    bool isEmpty()
    {
        if (top->prev == nullptr)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if (this->curPos >= this->size)
            return true;
        else
            return false;
    }
    int peek(int i)
    {
        Node *p = top;
        int cur = curPos;
        while (cur > i + 1)
        {
            cur--;
            p = p->prev;
        }
        return p->value;
    }
};

int main()
{

    Stack s = Stack(10);

    while (!s.isFull())
    {
        cout << "Give the value : ";
        int val;
        cin >> val;
        s.push(val);
    }

    cout << "Value at position 5 : " << s.peek(5) << endl
         << "The list is : ";

    while (!s.isEmpty())
        cout << s.pop() << " ";
        
    s.push(55);
    cout<<endl<<s.pop()<<endl;
    return 0;
}