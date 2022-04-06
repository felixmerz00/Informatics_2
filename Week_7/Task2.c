#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void displayList(struct Node** l);

void groupingLinkedList(struct Node** l, int length){
    int i;
    struct Node* p;
    struct Node* q;
    q = *l;
    p = *l;
    while(q->next != NULL){
        q = q->next;
    }
    for(i = 0; i < length; i++){
        displayList(l);
        if(p->data % 2 == 0){
            q->next = p;
            p = p->next;
            q->next->next = NULL;
            q = q->next;
        }
        else{
            p = p->next;
        }
    }
}

int getLength(struct Node** l)
{
    struct Node* p;
    p = *l;
    int count = 0;
    while(p != NULL){
        count++;
        p = p->next;
    }
    return count;
}

//takes the head of the list and insertts a new node at the end of the list
void insertList(struct Node** l, int data)
{ 
    struct Node* p;

    if(*l == NULL){
        p = (struct Node*)malloc(sizeof(struct Node));
        p->data = data;
        p->next = NULL;
        *l = p;
    }
    else{
        p = *l;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = (struct Node*)malloc(sizeof(struct Node));
        p->next->data = data;
        p->next->next = NULL;
        p = p->next;
    }
}

//takes the head of the list and prints the list
void displayList(struct Node** l)
{
    struct Node* p;
    p = *l;
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    int length;
    struct Node** l;
    l = malloc(sizeof(struct Node*));
    *l = NULL;
    insertList(l, 1); insertList(l, 10); insertList(l, 17); insertList(l, 2); insertList(l, 15);
    displayList(l);
    length = getLength(l);
    groupingLinkedList(l, length);
    displayList(l);

    return 0;
}