/****************************************************************************
 * University of Zurich, Informatics II, Spring Semester 2022               *
 * Exercise 7 - Task 2                                                      *
 *                                                                          *
 * @author <your name>                                                      *
 ****************************************************************************/

#include <stdlib.h>
#include <stdio.h>

typedef struct Stack {
	unsigned int capacity;
	int* items;
  	int top;
} Stack;

//TODO: your implementation

Stack* create(int size)
{
	Stack* s;
	s = (Stack*)malloc(sizeof(Stack));
	s->capacity = size;
	s->items = (int*)malloc(size*sizeof(int));
	s->top = 0;
	return s;
}

void delete(Stack* s)
{
	free(s->items);
	free(s);
}

int is_empty(Stack* s)
{
	if(s->top == 0){return 1;}
	else{return 0;}
}

/*Top points one place above the top element (see slide 377), thats why "top" has to be equal to "capacity" and not equal to "capacity-1"*/
int is_full(Stack* s){
	if(s->top == s->capacity){return 1;}
	else{return 0;}
}

int get_capacity(Stack* s)
{
	return s->capacity;
}

int num_items(Stack* s)
{
	return s->top;
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

void print(Stack* s)
{
	for(int i = 0; i < s->top; i++){
		printf("%d ", s->items[i]);
	}
	printf("\n");
}

/*returns 1 if s1 and s2 are equal, else 0
My definition of equality of two stacks: 
Two stacks are equal if they conatin the same elements in the same order (the capacity doesn't matter)*/
int is_equal(Stack* s1, Stack* s2)
{
	if(s1->top != s2->top){return 0;}
	for(int i = 0; i < s1->top; i++){
		if(s1->items[i] != s2->items[i]){return 0;}
	}
	return 1;
}

Stack* reverse(Stack* s)
{
	Stack* s_new;
	s_new = create(s->capacity);
	while(s->top != 0){
		push(s_new, pop(s));
	}
	return s_new;
}

int main() {
	//TODO: your implementation
	Stack* s;
	s = create(5);
	delete(s);
	s = create(4);
	printf("Currently there are %d elements on the stack.\n", num_items(s));
	printf("Peek: %d\n", peek(s));
	print(s);
	printf("The stack is empty: %d\n", is_empty(s));
	printf("The total capacity of the stack is: %d\n", get_capacity(s));
	push(s, 1);
	print(s);
	printf("Peek: %d\n", peek(s));
	printf("The stack is empty: %d\n", is_empty(s));
	printf("The stack is full: %d\n", is_full(s));
	push(s, 2);
	print(s);
	push(s, 3);
	print(s);
	push(s, 4);
	print(s);
	printf("Currently there are %d elements on the stack.\n", num_items(s));
	printf("The stack is full: %d\n", is_full(s));

	printf("Pop: %d\n", pop(s));
	printf("Pop: %d\n", pop(s));
	push(s, 5);
	print(s);
	printf("Peek: %d\n", peek(s));
	printf("Pop: %d\n", pop(s));
	print(s);
	printf("Pop: %d\n", pop(s));
	printf("Pop: %d\n", pop(s));
	print(s);
	printf("Currently there are %d elements on the stack.\n", num_items(s));
	printf("The stack is empty: %d\n", is_empty(s));
	printf("\n\n");

	//test is_equal()
	Stack* s2;
	s2 = create(7);
	printf("s1: "); print(s); printf("s2: "); print(s2);
	printf("The two stacks are equal: %d\n", is_equal(s, s2));	//should be equal bc both stacks are empty
	push(s2, 1);
	push(s2, 2);
	push(s2, 3);
	push(s, 1);
	push(s, 2);
	printf("s1: "); print(s); printf("s2: "); print(s2);
	printf("The two stacks are equal: %d\n", is_equal(s, s2));	//shouldn't be equal bc the two stacks have different top elements
	push(s, 3);
	printf("s1: "); print(s); printf("s2: "); print(s2);
	printf("The two stacks are equal: %d\n", is_equal(s, s2));	//should be equal
	pop(s);
	push(s, 4);
	printf("s1: "); print(s); printf("s2: "); print(s2);
	printf("The two stacks are equal: %d\n", is_equal(s, s2));	//shouldn't be equal bc they don't have the same elements
	printf("\n\n");

	//test reverse()
	print(s);
	s = reverse(s);
	print(s);
	return 0;
}
