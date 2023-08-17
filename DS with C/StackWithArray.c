#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int top, size;
    int *arr;
};

int isEmpty (struct stack* p){
    if(p->top==-1)return 1;
    else return 0;
}

int isFull (struct stack* p){
    if(p->top==p->size-1)return 1;
    else return 0;
}


void push(struct stack * p , int value){
    if(!isFull(p)){
        if(value<0){
            printf("stack cannot only contain positive values !");
        }else{
        p->top++;
        p->arr[p->top]=value;
        }
    }else{
        printf("\n ==>> Cannot push stack overflowed !\n");
    }
}

int pop(struct stack * p ){
    if(!isEmpty(p)){
        int val = p->arr[p->top];
        p->arr[p->top]=-1;
        p->top--;
        return val;
    }else{
        printf("\n ==>> Cannot pop stack underflowed !\n");
        return -1;
    }
}


void Forced_push(struct stack* p,int value){
    if(isFull(p)){
        p->size++;
        p->top++;
        p->arr = (int*)realloc(p->arr,p->size*sizeof(int));
        p->arr[p->top]=value;
    }else push(p,value);
}
void main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int*)malloc(sizeof(int));

    for(int i =0 ;i<7;i++) push(s,i);

    Forced_push(s,25);

    while(s->top>=0)
    printf("%d\n",pop(s));
    pop(s);
    
    free(s->arr);
    free(s);
}
