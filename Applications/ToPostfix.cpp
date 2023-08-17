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
    t Top(){
        return top->value;
    }
};

bool isOperator(char ch){
    switch(ch){
        case '+':case '-': case '/':case '*':case '%':return true;
        default : return false;
    }
}

bool checkPrec(char a,char b){
    // code to check precedence
    if(a=='%'||a=='*'||a=='/')if(b=='+'||b=='-')return true;
    return false;
}

const char* ToPostfix(const string& exp){
    int i,j;
    i=j=0;
    int size = exp.length();
     char* postfix=new char[size+1];

    Stack <char> stack(exp.length());

    while(exp[i]!='\0'){
        if(!isOperator(exp[i])){
            postfix[j++]=exp[i];
            i++;
        }else{
            if(stack.isEmpty()||checkPrec(exp[i],stack.Top())) stack.push(exp[i++]);
            else {
                postfix[j++]=stack.pop();
            }
        }
    }
    
    while(!stack.isEmpty()) postfix[j++]=stack.pop();
    postfix[j]='\0';
    return postfix;
}

int main(){
    cout<<"Enter the expression : ";
    string exp ;
    getline(cin,exp);
    cout<<"The postfix expression is : "<<ToPostfix(exp)<<endl;
    return 0;
}