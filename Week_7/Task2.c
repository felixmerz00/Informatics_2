//
//  main.c
//  Ex06Task02
//
//  Created by Felix Merz on 07.04.22.
//

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void displayList(struct Node** l);

void groupingLinkedList(struct Node** l, int length){
    struct Node* p; //iterates through the list to find the nodes with even data
    struct Node* q; //points on the last element of the list
    struct Node* end;   //points to the end of the original list and doesn't move
    q = *l;
    p = *l;
    while(q->next != NULL){
        q = q->next;
    }
    end = q;
    while(1 == 1){
        if(p->next->data % 2 == 0){
            q->next = p->next;
            p->next = p->next->next;
            q->next->next = NULL;
            q = q->next;
        }
        else{
            p = p->next;
        }
        if(q == end || p == end){
            break;
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
