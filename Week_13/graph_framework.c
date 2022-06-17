#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} node_t;

void enqueue(node_t **head, int val) {
    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    if (!new_node) return;

    new_node->val = val;
    new_node->next = *head;

    *head = new_node;
}


int isEmpty(node_t **head) {
	if (*head == NULL) return 1;
	else return 0;
}

int dequeue(node_t **head) {
    node_t *current, *prev = NULL;
    int retval = -1;

    if (*head == NULL) return -1;

    current = *head;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    retval = current->val;
    free(current);
    
    if (prev)
        prev->next = NULL;
    else
        *head = NULL;

    return retval;
}

int main() {
	int adj[7][7] = {
		{0,0,0,0,0,0,0},	
		{0,1,1,0,0,0,0},
		{0,0,1,1,0,0,0},
		{0,0,0,1,1,0,0},
		{0,1,0,0,1,0,0},
		{0,0,0,0,1,1,1},
		{0,1,0,0,0,0,1}
		};
}

