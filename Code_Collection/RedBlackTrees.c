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

// Right rotates around a given root t of a subtree
// The left child of t, node s will be the root of the subtree after the changes and t will be the right child of s
// Slides 433
struct Node* rightRotate(struct Node *t, struct Node *root)
{
    struct Node *s = t->leftChild;
    t->leftChild = s->rightChild;
    s->parent = t->parent;
    if(s->rightChild != NULL){
        s->rightChild->parent = t;
    }
    if(t->parent == NULL){
        root = s;
    }else{
        if(t == t->parent->leftChild){
            t->parent->leftChild = s;
        }else{
            t->parent->rightChild = s;
        }
    }
    s->rightChild = t;
    t->parent = s;

    return root;
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
    /* Test the rightRotate function
    root = rightRotate(root->leftChild->leftChild->leftChild, root);
    displayTreePreorder(root); printf("\n");
    printf("Rightrotate successful"); */
    return 0;
}