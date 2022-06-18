#include <stdlib.h>
#include <stdio.h>

struct Node{
    int value;
    char color; // red = 'r', black = 'b'
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
        printf("(%d, %c) ", p->value, p->color);
        displayTreeInorder(p->rightChild);
    }
}

// Takes the root of a tree as a parameter
// Prints the values of the nodes in preorder
void displayTreePreorder(struct Node *p)
{
    if(p != NULL){
        printf("(%d, %c) ", p->value, p->color);
        displayTreePreorder(p->leftChild);
        displayTreePreorder(p->rightChild);
    }
}

// Right rotates around a given root t of a subtree
// The left child of t, node s will be the root of the subtree after the changes and t will be the right child of s
// Slides 433
struct Node* rightRotate(struct Node *root, struct Node *t)
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

// Left rotates around a given root t of a subtree
// The right child of t, node s will be the root of the subtree after the changes and t will be the left child of s
// Slides 433
struct Node* leftRotate(struct Node *root, struct Node *t)
{
    struct Node *s = t->rightChild;
    t->rightChild = s->leftChild;
    s->parent = t->parent;
    if(s->leftChild != NULL){
        s->leftChild->parent = t;
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
    s->leftChild = t;
    t->parent = s;
    return root;
}

// Fixup takes a node and corrects the coloring and the black height to fullfill the red black tree properties
// Slide 435 and following
struct Node* fixup(struct Node *root, struct Node *t)
{
    // If t is the root --> color it black and return
    if(t == root){
        t->color = 'b';
        return root;
    }
    // If t has no grandparent, there is nothing to do
    if(t->parent->parent == NULL){return root;}
    struct Node *p = t->parent; // Parent of t
    struct Node *g = t->parent->parent; // Grandparent of t
    struct Node *u = NULL; // Uncle of t

    // Test weather p is the left child of g: case 0 - case 3
    // From Slide 435 - 439
    if(g->leftChild == p){
        if(g->rightChild != NULL){  // Asign uncle
            u = g->rightChild;
        }
        if(p->color == 'b'){    // Case 0: Color of p is black --> no property violated, hence nothing to do
            
        }else if(u != NULL && u->color == 'r'){  // Case 1: t's uncle is red --> p->col = u->col = black, g->col = red, set t = g
            p->color = 'b';
            u->color = 'b';
            g->color = 'r';
            t = g;
            root = fixup(root, t);
        }else if(p->rightChild == t){   // Case 2: t's uncle is black and t is a right child --> leftRotate(p), t = p
            leftRotate(root, p);
            t = p;
            root = fixup(root, t);
        }else if(p->leftChild == t){    // Case 3: t’s uncle u is black and t is a left child --> p->col = black, g->col = red, rightRotate(g)
            p->color = 'b';
            g->color = 'r';
            rightRotate(root, g);
        }
    }else{  // p is the right child of g: mirror cases of case 0 - case 3
        if(g->leftChild != NULL){  // Asign uncle
            u = g->leftChild;
        }
        if(p->color == 'b'){    // Case 0: Color of p is black --> no property violated, hence nothing to do
            
        }else if(u != NULL && u->color == 'r'){  // Case 1: t's uncle is red --> p->col = u->col = black, g->col = red, set t = g
            p->color = 'b';
            u->color = 'b';
            g->color = 'r';
            t = g;
            root = fixup(root, t);
        }else if(p->leftChild == t){   // Case 2: t's uncle is black and t is a left child --> rightRotate(p), t = p
            rightRotate(root, p);
            t = p;
            root = fixup(root, t);
        }else if(p->rightChild == t){    // Case 3: t’s uncle u is black and t is a right child --> p->col = black, g->col = red, leftRotate(g)
            p->color = 'b';
            g->color = 'r';
            leftRotate(root, g);
        }
    }
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
    fixup(root, t);
    return root;
}

int main()
{
    int A[] = {26, 17, 41, 14, 21, 30, 47, 10, 16, 19, 23, 28, 38, 7, 12, 15, 20, 35, 39, 3};   // length = 20
    struct Node *root;
    root = NULL;
    for(int i = 0; i < 20; i++){
        root = RBTInsert(root, A[i]);
    }
    printf("Tree preorder print:\n");
    displayTreePreorder(root);
    printf("\n");
    printf("Tree inorder print:\n");
    displayTreeInorder(root);
    printf("\n");

    // Exercise from p 444: Insert 36 into the RBT above
    printf("Tree preorder after insertion of 36\n");
    root = RBTInsert(root, 36);
    displayTreePreorder(root);
    printf("\n");


    /* Test the rightRotate function
    root = rightRotate(root->leftChild->leftChild->leftChild, root);
    root = rightRotate(root, root);
    displayTreePreorder(root); printf("\n");
    printf("Rightrotate successful\n");*/

    /* Test the leftRotate function
    root = leftRotate(root, root->rightChild);
    root = leftRotate(root, root);
    displayTreePreorder(root);
    printf("\n"); */
    return 0;
}