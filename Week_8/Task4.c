#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
	unsigned int capacity;
	int* items;
  	int top;
} Stack;

//methods written in Task2.c
Stack* create(int size);
void push(Stack* s, int value);
int pop(Stack* s);
int peek(Stack* s);

//returns 1 if push pop operations are possible, else 0
int achievable(int in[], int out[], int length)
{
    int i;
    int j = 0;
    Stack* s;
    s = create(length);
    while(j < length){
        while(j < length && out[i] != in[j]){
            push(s, in[j]);
            j++;
        }
        push(s, in[j]);
        j++;
        while(out[i] == peek(s)){
            pop(s);
            i++;
        }
    }
    if(i == length){
        return 1;
    }
    return 0;
}


int main()
{
    /*This array works*/
    int in[] = {1, 2, 3, 4, 5};
    int out[] = {4, 5, 3, 2, 1};
    int length = 5;
    
    /*This array doesn't work
    int in[] = {1, 2, 3, 4, 5};
    int out[] = {4, 3, 1, 5, 2};
    int length = 5;*/
    printf("%d\n", achievable(in, out, length));
}

//methods used from task2
Stack* create(int size)
{
	Stack* s;
	s = (Stack*)malloc(sizeof(Stack));
	s->capacity = size;
	s->items = (int*)malloc(size*sizeof(int));
	s->top = 0;
	return s;
}

void push(Stack* s, int value)
{
	s->items[s->top] = value;
	s->top++;
}

int pop(Stack* s)
{
	s->top--;
	return s->items[s->top];
}

int peek(Stack* s)
{
	if(s->top == 0){return -1;}
	return s->items[s->top-1];
}