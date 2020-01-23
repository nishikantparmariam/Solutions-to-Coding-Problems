#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int data){
    struct Node *root = (struct Node *)malloc(sizeof(struct Node));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
};

void inorder(struct Node *root){
    if(root==NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(struct Node *root){
    if(root==NULL) return;    
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int max_(pair<int,int> p){
    return max(p.first, p.second);
}

//(that includes child and straight, that may/may not include child, may/may not be staight)
pair<int,int> pathWithMaxSum(struct Node *root){
    if(root==NULL) return make_pair(0,0);
    pair<int,int> p1 = pathWithMaxSum(root->left);
    pair<int,int> p2 = pathWithMaxSum(root->right);

    //returning first type of path
    int type1 = max(root->data+p1.first, root->data+p2.first);
    int type2 = max(root->data+p1.first+p2.first, max(p1.second, p2.second));

    return make_pair(type1, type2);

}

int main(){
    int pre[] = {10, 11, 51, 49, 46, 50,100,52};
    struct Node *root = newNode(pre[0]);    
    struct Node *temp = root;
    stack<struct Node *> s;
    s.push(root);
    int n = sizeof(pre)/sizeof(int);
    for(int i=1;i<n;i++){
        if(pre[i]<s.top()->data){
            temp->left = newNode(pre[i]);
            temp = temp->left;
            s.push(temp);
        } else {
            while(!s.empty()){
                if(s.top()->data < pre[i]){
                    temp = s.top();
                    s.pop();
                } else {
                    break;
                }                
            }        
            temp->right = newNode(pre[i]);
            temp = temp->right;
            s.push(temp);                                                
        }
    }

    inorder(root);
    cout << endl;
    preorder(root);

    //Iterative Preorder Traversal
   /* cout << "\nIterative Preorder : ";
    stack<struct Node *> stack;    
    struct Node *temp2 = root;
    while(!stack.empty() || temp2!=NULL){        
        if(temp2!=NULL){
            while(temp2!=NULL){
                cout << temp2->data << " ";                                                
                stack.push(temp2);
                temp2=temp2->left;
            }            
        } else {
            temp2 = stack.top()->right;
            stack.pop();
            //stack.push();
        }
    } */

     /*cout << "\nIterative Inorder : ";
    stack<struct Node *> stack;    
    struct Node *temp2 = root;
    while(!stack.empty() || temp2!=NULL){        
        if(temp2!=NULL){
            while(temp2!=NULL){
                                                               
                stack.push(temp2);
                temp2=temp2->left;
            }            
        } else {
            
            cout << stack.top()->data << " ";             
            temp2 = stack.top()->right;
            stack.pop();
            //stack.push();
        }
    }  */

    cout << "\nIterative Postorder : ";
    stack<struct Node *> stack_1;
    stack<struct Node *> stack_2;
    struct Node *top = root;   
    stack_1.push(top); 
    while(!stack_1.empty()){
        struct Node *top = stack_1.top();
        stack_1.pop();
        stack_2.push(top);
        if(top->left!=NULL) stack_1.push(top->left);            
        if(top->right!=NULL) stack_1.push(top->right);
    }        

    while(!stack_2.empty()){
        cout << stack_2.top()->data << " ";
        stack_2.pop();
    }

    

    cout << endl;

    struct Node *root2 = newNode(10); 
    root2->left        = newNode(2); 
    root2->right       = newNode(10); 
    root2->left->left  = newNode(20); 
    root2->left->right = newNode(1); 
    root2->right->right = newNode(-25); 
    root2->right->right->left   = newNode(3); 
    root2->right->right->right  = newNode(4); 

    cout << "\n Max Path : ";

    cout << max_(pathWithMaxSum(root2)) << endl;

    

}