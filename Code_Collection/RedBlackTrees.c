#include <stdlib.h>
#include <stdio.h>

struct Node{
    int value;
    char color; // red = "r", black = "b"
    struct Node *parent;
    struct Node *rightChild;
    struct Node *leftChild;
};

// Takes the root of a tree as a parameter
// Prints the values of the nodes in ascending order
void displayTreeInorder(struct Node *p)
{
    if(p != NULL){
        displayTreeInorder(p->leftChild);
        printf("%d ", p->value);
        displayTreeInorder(p->rightChild);
    }
}

// Takes the root of a tree as a parameter
// Prints the values of the nodes in preorder
void displayTreePreorder(struct Node *p)
{
    if(p != NULL){
        printf("%d ", p->value);
        displayTreePreorder(p->leftChild);
        displayTreePreorder(p->rightChild);
    }

}

// Takes a pointer to the root node of the tree and returns the root node of the edited tree
// Inserts a new node with the provided value into the tree
// Based on slides page 434
struct Node* RBTInsert(struct Node *root, int value)
{
    struct Node *s = NULL;
    struct Node *x = root;
    struct Node *t;
    t = (struct Node*)malloc(sizeof(struct Node));
    t->value = value;
    t->rightChild = NULL;
    t->leftChild = NULL;

    // Go to a leaf of the tree with similar value as the entered value for the new node
    while(x != NULL){
        s = x;
        if(t->value < x->value){
            x = x->leftChild;
        }else{
            x = x->rightChild;
        }
    }
    t->parent = s;
    t->color = 'r';
    if(s == NULL){
        root = t;  // derefrencing the double pointer
    }else{
        if(t->value < s->value){
            s->leftChild = t;
        }else{
            s->rightChild = t;
        }
    }
    return root;
    // Insert color fixup
}

int main()
{
    printf("Hello World\n");
    int A[] = {26, 17, 41, 14, 21, 30, 47, 10, 16, 19, 23, 28, 38, 7, 12, 15, 20, 35, 39, 3};   // length = 20
    struct Node *root;
    root = NULL;
    printf("Initialization successful\n");
    for(int i = 0; i < 20; i++){
        root = RBTInsert(root, A[i]);
    }
    printf("Tree build successful\n");
    displayTreePreorder(root);
    printf("\n");
    printf("Tree preorder print successful\n");
    displayTreeInorder(root);
    printf("\n");
    printf("Tree inorder print successful\n");
    return 0;
}