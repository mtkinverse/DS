#include <iostream>
#include <string>
using namespace std;

template <class type>
struct Node
{
    type value;
    struct Node<type> *next;
};

template <class t>

class Stack
{

    struct Node<t> *top;
    int size, curPos;

public:
    Stack() {}
    Stack(int size)
    {
        top = new struct Node<t>;
        top->value = -1;
        top->next = nullptr;
        this->size = size + 1;
        this->curPos = 0;
    }
    void push(int val)
    {
        if (!isFull())
        {
            struct Node<t> *p = new struct Node<t>;
            p->next = top;
            p->value = val;
            top = p;
            this->curPos++;
        }
    }

    t pop()
    {
        if (!isEmpty())
        {
            int val = top->value;
            struct Node<t> *cur = top;
            top = top->next;
            this->curPos--;
            free(cur);
            return val;
        }
        else
        {
            return -1;
        }
    }
    bool isEmpty()
    {
        if (top->next == nullptr)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if (this->curPos >= this->size - 1)
            return true;
        else
            return false;
    }
};

bool checkParenthesis(const string &exp)
{

    bool balanced = true;
    Stack<char> stack(exp.length());
    int i = 0;
    char c;
    while (exp[i] != '\0')
    {
        switch (exp[i])
        {
            // pushing all the opening bracket
        case '(':
        case '{':
        case '[':
            stack.push(exp[i]);
            break;
            // Checking the curresponding brackets
        case ')':
            if (stack.isEmpty() || (c=stack.pop()) != '(')
                return false;
            break;
        case '}':
            if (stack.isEmpty() || (c=stack.pop()) != '{')
                return false;
            break;
        case ']':
            if (stack.isEmpty() || (c=stack.pop()) != '[')
                return false;
            break;
        }
        i++;
    }
    // Checking condition number 2 , is stack empty or not ?
    if (!stack.isEmpty())
        balanced = false;

    return balanced;
}

int main()
{

    cout << "Enter the expression : ";

    string exp;
    getline(cin, exp);

    if (checkParenthesis(exp))
        cout << endl << "The expression is balanced !" << endl;
    else
        cout << endl << "The expression is not balanced ! " << endl;

    return 0;
}