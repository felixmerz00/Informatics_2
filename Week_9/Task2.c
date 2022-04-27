#include <stdio.h>
#include <stdlib.h>

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

/*to print a tree I need two functions, one to print all subtrees recursively (inorder traversal)
and one method to print the new line character at the end*/
void recursivePrint(struct TreeNode* root)
{
    if(root == NULL){return;}
    recursivePrint(root->left);
    printf("%d ", root->val);
    recursivePrint(root->right);
}

void printTree(struct TreeNode* root)
{
    recursivePrint(root);
    printf("\n");
}

struct TreeNode* search(struct TreeNode* root, int val)
{
    if(root == NULL){return NULL;}
    else{
        //if we found the node, then return it
        if(root->val == val){return root;}
        //search the left subtree
        else if(root->val > val){return search(root->left, val);}
        //search the right subtree
        else{return search(root->right, val);}
    }
}

struct TreeNode* insert(struct TreeNode* root, int val)
{
    struct TreeNode* p;
    p = root;
    //create a new tree if root == NULL
    if(p == NULL){
        p = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        p->val = val;
        p->left = NULL;
        p->right = NULL;
        return p;
    }else{
        while(1){
            //insert the value as left child
            if(p->val > val && p->left == NULL){
                p->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
                p = p->left;
                p->val = val;
                p->left = NULL;
                p->right = NULL;
                return root;
            }
            //follow the left branch
            else if(p->val > val && p->left != NULL){
                p = p->left;
            }
            //insert the value as right child
            else if(p->val < val && p->right == NULL){
                p->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
                p = p->right;
                p->val = val;
                p->left = NULL;
                p->right = NULL;
                return root;
            }
            //follow the right branchf
            else if(p->val < val && p->right != NULL){
                p = p->right;
            }
        }
    }
}

int main()
{
    struct TreeNode* root;
    root = NULL;
    printf("Hello World \n");
    root = insert(root, 12);
    printf("insert 1 erfolgreich \n");
    insert(root, 35);
    printf("insert 2 erfolgreich \n");
    insert(root, 17);
    insert(root, 29);
    insert(root, 45);
    insert(root, 28);
    insert(root, 9);
    insert(root, 50);

    //test the serach function
    if(search(root, 28) == NULL){printf("Node 28 not found\n");}
    else{printf("Node 28 found\n");}

    if(search(root, 200) == NULL){printf("Node 200 not found\n");}
    else{printf("Node 200 found\n");}

    printTree(root);
    return 0;
}