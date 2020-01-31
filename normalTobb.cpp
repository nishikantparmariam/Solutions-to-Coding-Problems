#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

int height(Node *root){
    if(root==NULL) return 0;
    return 1+max(height(root->left), height(root->right));
}

int balance_factor(Node *root){
    if(root==NULL) return 0;
    return height(root->left) - height(root->right);
}

Node *LLrotation(Node *root){
    Node *a = root;
    Node *b = root->left;
    //Node *c = root->left->left;
    
    a->left = b->right;
    b->right = a;
    
    return b;
}

Node *RRrotation(Node *root){
    Node *a = root;
    Node *b = root->right;
    //Node *c = root->right->right;
    
    a->right = b->left;
    b->left = a;
    
    return b;
}

Node *LRrotation(Node *root){
    Node *a = root;
    Node *b = root->left;
    Node *c = root->left->right;
    
    b->right = c->left;
    c->left = b;
    
    return LLrotation(a);
}

Node *RLrotation(Node *root){
    Node *a = root;
    Node *b = root->right;
    Node *c = root->right->left;
    
    b->left = c->right;
    c->right = b;
    
    return RRrotation(a);
}

Node* InsertInBalancedTree(Node* root, int x)
{    
    
	if(root==NULL) {
        root = (Node *)malloc(sizeof(Node));
        root->data = x;
        root->left = NULL;
        root->right = NULL;
    } else if(root->data > x){
        root->left = InsertInBalancedTree(root->left,x);
    } else {
        root->right = InsertInBalancedTree(root->right,x);
    }



	int left_height = height(root->left);
	int right_height = height(root->right);
	int bf = balance_factor(root);
	int bf_l = balance_factor(root->left);
	int bf_r = balance_factor(root->right);	
	
	if(bf ==2 && bf_l==1){
	    root = LLrotation(root);
	} else if(bf ==2 && bf_l==-1){
	    root = LRrotation(root);
	} else if(bf ==-2 && bf_l==1){
	    root = RLrotation(root);
	} else if(bf ==-2 && bf_l==-1){
	    root = RRrotation(root);
	}		
	
	return root;
}


void _inorderTrav(Node *root, vector<int> &inorder_traversal_array){
    if(root==NULL) return;
    _inorderTrav(root->left,inorder_traversal_array);
    inorder_traversal_array.push_back(root->data);
    _inorderTrav(root->right,inorder_traversal_array);
}

Node* buildBalancedTree(Node* root){
    if(root==NULL) return NULL;
    vector<int> inorder_traversal_array;
    _inorderTrav(root, inorder_traversal_array);
}