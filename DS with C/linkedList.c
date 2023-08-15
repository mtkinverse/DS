#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *nextNode;
};

void DisplayList(struct Node *head)
{
    // Traverseling into the list
    struct Node *ptr = head;

    do
    {
        printf("%d ", ptr->value);
        ptr = ptr->nextNode;
    } while (ptr->nextNode != NULL);

    printf("%d\n", ptr->value);
}

struct Node *InsertAtFirst(struct Node *head, int data)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->nextNode = head;
    p->value = data;
    return p;
}

void InsertAtLast(struct Node *head, int data)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    struct Node *ptr = head;

    while (ptr->nextNode != NULL)
        ptr = ptr->nextNode;
    ptr->nextNode = p;
    p->value = data;
    p->nextNode = NULL;
}

struct Node *InsertAtIndex(struct Node *head, int index, int data)
{

    if (index <= 0)
    {
        return InsertAtFirst(head, data);
    }

    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    struct Node *ptr = head;

    int i = 0;

    while (ptr->nextNode != NULL && i != index)
    {
        ptr = ptr->nextNode;
        i++;
    }

    if (i == index)
    {
            p->nextNode = ptr->nextNode;
            ptr->nextNode = p;
            p->value = data;
    }

    return head;
}

struct Node* DeleteAtFirst(struct Node* head){
    struct Node* p;
    p=head->nextNode;
    free(head);
    return p;
}

struct Node* DelteAtIndex(struct Node* head,int index){

    if(index == 0)return DeleteAtFirst(head);
    struct Node* p = head;
    int i=0;
    while(p->nextNode!=NULL && i<index-1){
        p=p->nextNode;
        i++;
    }
    if(i==index-1){
        struct Node* ptr = p->nextNode;
        p->nextNode=ptr->nextNode;
        free(ptr);
    }
    return head;
}

int main()
{
    // Rquesting memory in heap
    struct Node *FirstNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *SecondNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *ThirdNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *FourthNode = (struct Node *)malloc(sizeof(struct Node));

    // Creating the list
    FirstNode->value = 3;
    FirstNode->nextNode = SecondNode;
    SecondNode->value = 5;
    SecondNode->nextNode = ThirdNode;
    ThirdNode->value = 1;
    ThirdNode->nextNode = FourthNode;
    FourthNode->value = 9;
    FourthNode->nextNode = NULL;

    printf("List before insertion : ");
    DisplayList(FirstNode);

    FirstNode = InsertAtFirst(FirstNode, 99);
    printf("List after insertion at first index : ");
    DisplayList(FirstNode);
    FirstNode = InsertAtFirst(FirstNode, 109);
    printf("List after insertion at first index : ");
    DisplayList(FirstNode);
    InsertAtLast(FirstNode, 19);
    printf("List after insertion at last index : ");
    DisplayList(FirstNode);
    InsertAtLast(FirstNode, 6);
    printf("List after insertion at last index : ");
    DisplayList(FirstNode);

    FirstNode = InsertAtIndex(FirstNode, 3, 54);
    printf("List after insertion at 3rd index : ");
    DisplayList(FirstNode);
    FirstNode = InsertAtIndex(FirstNode, 6, 21);
    printf("List after insertion at 6th index : ");
    DisplayList(FirstNode);
    FirstNode = DelteAtIndex(FirstNode, 6);
    printf("List after deleting at 6th index : ");
    DisplayList(FirstNode);
    FirstNode = DelteAtIndex(FirstNode, 0);
    printf("List after deleting at 0th index : ");
    DisplayList(FirstNode);

    return 0;
}