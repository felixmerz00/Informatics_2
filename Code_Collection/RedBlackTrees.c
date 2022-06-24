#include <stdlib.h>
#include <stdio.h>

struct Node{
    int value;
    char color; // red = 'r', black = 'b'
    struct Node *parent;
    struct Node *rightChild;
    struct Node *leftChild;
};

void test_deletion_fixup();

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

// Checks weather a given value is in the given tree
// Returns 1 if the tree contains the value, 0 if not
int search(struct Node *root, int value)
{
    struct Node *n = root;
    while(n != NULL){
        if(n->value == value){
            return 1;
        }else if(value < n->value){
            n = n->leftChild;
        }else{
            n = n->rightChild;
        }
    }
    return 0;
}

struct Node* search_address(struct Node *root, int value)
{
    struct Node *n = root;
    while(n != NULL){
        if(n->value == value){
            return n;
        }else if(value < n->value){
            n = n->leftChild;
        }else{
            n = n->rightChild;
        }
    }
    return NULL;
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
    t->parent = NULL;

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

// x is the node that replaced the deleted node, p is the parent of the deleted node (and now the parent of x)
// Slides p. 447 (variable names have changed from the deletion method)
struct Node* fixup_deletion(struct Node *root, struct Node *x, struct Node *p)
{
    if(x == root){
        return root;
    }
    if(x != NULL && x->color == 'r'){    // Case 0
        x->color = 'b';
        return root;
    }

    // If x is a left child
    struct Node *b = NULL; // Brother of x
    if(p->leftChild == x){
        b = p->rightChild;
        if(b->color == 'r'){    // Case 1
            b->color = 'b';
            p->color = 'r';
            b = b->leftChild;
            root = leftRotate(root, p);
        }
        if((b->leftChild == NULL || b->leftChild->color == 'b') && (b->rightChild == NULL || b->rightChild->color == 'b')){ // Case 2
            b->color = 'r';
            if(p->color == 'r'){
                p->color = 'b';
            }else{
                root = fixup_deletion(root, p, p->parent);
            }
        }
        if(b->leftChild->color == 'r' && (b->rightChild == NULL || b->rightChild->color == 'b')){   // Case 3
            b->leftChild->color = 'b';
            b->color = 'r';
            root = rightRotate(root, b);
            b = p->rightChild;
        }
        if((b->leftChild == NULL || b->leftChild->color == 'b') && b->rightChild->color == 'r'){   // Case 4
            b->color = p->color;
            p->color = 'b';
            b->rightChild->color = 'b';
            leftRotate(root, p);
        }
    }
    /* Mirror cases */
    else if(p->rightChild == x){
        b = p->leftChild;
        if(b->color == 'r'){ // Mirror Case 1
            b->color = 'b';
            p->color = 'r';
            b = b->rightChild;
            root = rightRotate(root, p);
        }

        // Fix the conditions according to the not - mirror cases
        if((b->leftChild == NULL || b->leftChild->color == 'b') && (b->rightChild == NULL || b->rightChild->color == 'b')){ // Mirror Case 2
            b->color = 'r';
            if(p->color == 'r'){
                p->color = 'b';
            }else{
                root = fixup_deletion(root, p, p->parent);
            }
        }
        if((b->leftChild == NULL || b->leftChild->color == 'b') && b->rightChild->color == 'r'){   // Mirror Case 3
            b->rightChild->color = 'b';
            b->color = 'r';
            root = leftRotate(root, b);
            b = p->leftChild;
        }
        if(b->leftChild->color == 'r' && (b->rightChild == NULL || b->rightChild->color == 'b')){   // Mirror Case 4
            b->color = p->color;
            p->color = 'b';
            b->leftChild->color = 'b';
            rightRotate(root, p);
        }
    }

    return root;
}

// Takes a node x that should be deleted. The tree must contain x. You can check with the search/search_address function.
struct Node* delete_node(struct Node *root, struct Node *x)
{
    struct Node *parent = x->parent; // Save the parent of x for the color fixup

    // We first apply binary search tree deletion (Slides p. 423)
    // If x has two children:
    if(x->rightChild != NULL && x->leftChild != NULL){
        // Find the biggest element in the left subtree
        struct Node *p = x->leftChild;
        while(p->rightChild != NULL){
            p = p->rightChild;
        }

        x->value = p->value;    // Copy its value into the node to be deleted, and delete the biggest node of the left subtree instead
        x = p;
    }

    // There are six different cases, if x has less then two children.
    struct Node *p = x->parent;
    struct Node *s; // Node that replaced the deleted node
    if(x->rightChild == NULL){
        if(x->parent == NULL){  // Case 1
            root = x->leftChild;
            x->leftChild->parent = NULL;
        }
        else if(p->leftChild == x){ // Case 2
            p->leftChild = x->leftChild;
            if(x->leftChild != NULL){
                x->leftChild->parent = p;
            }
        }else{  // Case 3
            p->rightChild = x->leftChild;
            if(x->leftChild != NULL){
                x->leftChild->parent = p;
            }
        }
        s = x->leftChild;
    }else if(x->leftChild == NULL){
        if(x->parent == NULL){  // Case 4
            root = x->rightChild;
            x->leftChild->parent = NULL;
        }else if(p->leftChild == x){    // Case 5
            p->leftChild = x->rightChild;
            x->rightChild->parent = p;
        }else{  // Case 6
            p->rightChild = x->rightChild;
            x->rightChild->parent = p;
        }
        s = x->rightChild;
    }

    if(x->color == 'r' || s == root){ // If x was red, we are done. Nothing bad can happen deleting a red node.
        free(x);
    }else{
        root = fixup_deletion(root, s, parent);
    }

    return root;
}

int main()
{
    /*
    int A[] = {26, 17, 41, 14, 21, 30, 47, 10, 16, 19, 23, 28, 38, 7, 12, 15, 20, 35, 39, 3};   // length = 20
    struct Node *root;
    root = NULL;
    for(int i = 0; i < 20; i++){
        root = RBTInsert(root, A[i]);
    }
    printf("Tree preorder print:\n");
    displayTreePreorder(root);
    printf("\n");
    */

    /* Test tree print inorder 
    printf("Tree inorder print:\n");
    displayTreeInorder(root);
    printf("\n"); */

    /* Exercise from p 444: Insert 36 into the RBT above
    printf("Tree preorder after insertion of 36\n");
    root = RBTInsert(root, 36);
    displayTreePreorder(root);
    printf("\n"); */


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

    /* Test the search function
    printf("The tree contains the number 19: %d\n", search(root, 19));
    printf("The tree contains the number 99: %d\n", search(root, 99)); */

    /* Test the search_address function
    struct Node *h;
    h = search_address(root, 26);
    if(h != NULL){
        printf("Node 26 found!\n");
    }else{
        printf("Node 26 not found!\n");
    }

    h = search_address(root, 27);
    if(h != NULL){
        printf("Node 27 found!\n");
    }else{
        printf("Node 27 not found!\n");
    } */

    /* Test deletion of node with delete_by_address for different nodes
    struct Node *x = search_address(root, 16);
    if(x != NULL){root = delete_node(root, x);}
    printf("Tree preorder after deleting 16.\n");
    displayTreePreorder(root);
    printf("\n");

    x = search_address(root, 26);
    if(x != NULL){root = delete_node(root, x);}
    printf("Tree preorder after deleting 26.\n");
    displayTreePreorder(root);
    printf("\n"); */

    test_deletion_fixup();

    return 0;
}

void test_deletion_fixup()
{
    int i;
    struct Node *x;
    /* Test case 0: x is red
    printf("Test deletion fixup case 0\n");
    struct Node *root = NULL;
    root = RBTInsert(root, 10); root = RBTInsert(root, 7); root = RBTInsert(root, 12); root = RBTInsert(root, 3);
    displayTreePreorder(root); printf("\n");
    x = search_address(root, 7);
    root = delete_node(root, x);
    displayTreePreorder(root); printf("\n"); */

    /* Test mirror case 0
    printf("Test deletion fixup mirror case 0\n");
    root = RBTInsert(root, 14);
    displayTreePreorder(root); printf("\n");
    x = search_address(root, 12);
    root = delete_node(root, x);
    displayTreePreorder(root); printf("\n"); */

    // Test case 1: b is red, every thing else black
    printf("Test deletion fixup case 1\n");
    struct Node *root2 = NULL;
    int A[] = {55, 40, 65, 60, 75, 57};
    for(i = 0; i < 6; i++){
        root2 = RBTInsert(root2, A[i]);
    }
    displayTreePreorder(root2); printf("\n");
    x = search_address(root2, 40);
    root2 = delete_node(root2, x);
    displayTreePreorder(root2); printf("\n");

    /* Test mirror case 1 */
    printf("Test deletion fixup mirror case 1\n");
    struct Node *root3 = NULL;
    int B[] = {55, 60, 35, 30, 40, 45};
    for(i = 0; i < 6; i ++){
        root3 = RBTInsert(root3, B[i]);
    }
    displayTreePreorder(root3); printf("\n");
    x = search_address(root3, 60);
    root3 = delete_node(root3, x);
    displayTreePreorder(root3); printf("\n");
}