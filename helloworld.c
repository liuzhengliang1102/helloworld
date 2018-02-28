/*
				9
			4        15
          2   6    12  17
			    8
*/
#include <stdio.h>
#include <stdlib.h>

struct binary_tree {
    int data;  // Data area
    struct binary_tree *left;
    struct binary_tree *right;
}; 

typedef struct binary_tree node;

void insert(node ** tree, int val) {
    node * temp = NULL;
    if(!(*tree)) {
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return ;
    }
    
    if (val < (*tree)->data) {
        insert(&(*tree)->left,val);
    }else if (val > (*tree)->data) {
        insert(&(*tree)->right,val);
    }
}

void deltree(node * tree) {
    if(tree) {
    	if(tree->left)
        	deltree(tree->left);
        if(tree->right)
        	deltree(tree->right);
        free(tree);
        tree = NULL;
    }
}

void print_preorder(node * tree) {
    if(tree) {
        printf("%d\n",tree->data);
        print_preorder(tree->left);
        print_preorder(tree->right);
    }
}

void print_inorder(node * tree) {
    if(tree) {
        print_inorder(tree->left);
        printf("%d\n",tree->data);
        print_inorder(tree->right);
    }
}

void print_postorder(node * tree) {
    if(tree) {
        print_postorder(tree->left);
        print_postorder(tree->right);
        printf("%d\n",tree->data);
    }
}

int get_depth(node * tree)  
{  
    int cd,ld,rd;  
    cd = ld = rd = 0;  
    if(tree)  
    {  
        ld = get_depth(tree->left);  
        rd = get_depth(tree->right);  
        cd = (ld > rd ? ld : rd);  
        return cd+1;
    }  
    else  
        return 0;  
}  

int main(void)
{
    node * root = NULL;

    /* Inserting nodes into tree */
    insert(&root,9);
    insert(&root,4);
    insert(&root,15);
    insert(&root,6);
    insert(&root,12);
    insert(&root,17);
    insert(&root,2);
    insert(&root,8);

    printf("Pre Order Display---0\n");
    print_preorder(root);

    printf("In Order Display---0\n");
    print_inorder(root);

    printf("Post Order Display---0\n");
    print_postorder(root);

	printf("get the tree depth: %d \n",get_depth(root));
}
