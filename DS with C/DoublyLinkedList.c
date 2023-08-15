#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *prev;
    struct node *next;
};

void PrintForward(struct node *head)
{

    struct node *p = head;

    while (p->next != NULL)
    {
        printf("%d ", p->value);
        p = p->next;
    }
    printf("%d\n", p->value);
}

void PrintBackward(struct node *head)
{
    struct node *p = head;
    while (p->prev != NULL)
    {
        printf("%d ", p->value);
        p = p->prev;
    }
    printf("%d\n", p->value);
}

struct node *InsertAtFirst(struct node *head, int data)
{

    struct node *p = (struct node *)malloc(sizeof(struct node));

    p->prev = NULL;
    p->next = head;
    p->value = data;
    head->prev = p;

    return p;
}

struct node *InsertAtLast(struct node *head, int data)
{
    struct node *p = head;

    while (p->next != NULL)
        p = p->next;

    struct node *ptr = (struct node *)malloc(sizeof(struct node));

    ptr->next = NULL;
    ptr->prev = p;
    ptr->value = data;
    p->next = ptr;

    return head;
}

struct node *InsertAtIndex(struct node *head, int ind, int data)
{
    if (ind <= 0)
        return InsertAtFirst(head, data);

    struct node *p = head;
    int i = 0;
    while (p->next != NULL && i < ind)
    {
        p = p->next;
        i++;
    }

    if (i == ind)
    {
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        p->prev->next = ptr;
        ptr->prev = p->prev;
        p->prev = ptr;
        ptr->next = p;
        ptr->value = data;
    }
    return head;
}

struct node *DeleteAtIndex(struct node *head, int ind)
{
    struct node *p = head;

    int i = 0;
    while (p->next != NULL && i < ind)
    {
        p = p->next;
        i++;
    }
    if (i == ind)
    {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        free(p);
    }

    return head;
}

struct node* DeleteAtFirst(struct node* head){
    struct node* p = head->next;
    p->prev=NULL;
    free(head);
    return p;
}

struct node* DeleteAtLast(struct node * head){
    struct node * p = head;
    while(p->next!=NULL) p=p->next;
    p->prev->next= NULL;
    return head;
}

void main()
{

    struct node *n1, *n2, *n3, *n4;

    n1 = (struct node *)malloc(sizeof(struct node));
    n2 = (struct node *)malloc(sizeof(struct node));
    n3 = (struct node *)malloc(sizeof(struct node));
    n4 = (struct node *)malloc(sizeof(struct node));

    n1->prev = NULL;
    n1->next = n2;
    n1->value = 83;

    n2->prev = n1;
    n2->next = n3;
    n2->value = 3;

    n3->prev = n2;
    n3->next = n4;
    n3->value = 12;

    n4->prev = n3;
    n4->next = NULL;
    n4->value = 5;

    PrintForward(n1);
    PrintBackward(n3);

    n1 = InsertAtFirst(n1, 322);
    printf("After inserting at first index : ");
    PrintForward(n1);

    n1 = InsertAtLast(n1, 11);
    printf("After inserting at last index : ");
    PrintForward(n1);

    n1 = InsertAtIndex(n1, 3, 56);
    printf("After inserting at third index : ");
    PrintForward(n1);

   
    n1 = DeleteAtIndex(n1, 3);
    printf("After deleting at third index : ");
    PrintForward(n1);

    n1 = DeleteAtFirst(n1);
    printf("After deleting at first index : ");
    PrintForward(n1);

    n1 = DeleteAtLast(n1);
    printf("Printing in reverse after deleting at last : ");
    PrintBackward(n4);
}
