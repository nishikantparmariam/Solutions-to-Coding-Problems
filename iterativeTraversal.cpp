#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    struct Node *left;
    struct Node *right;
};


vector<int> preorder(Node *root){
    vector<int> TRAVERSAL;
    stack<Node *> S;
    Node *temp = root;
    while(!S.empty() || temp!=NULL){
        while(temp!=NULL){
            TRAVERSAL.push_back(temp->val);
            S.push(temp);
            temp=temp->left;            
        }
        temp=S.top();
        S.pop();
        temp=temp->right;
    }
}

vector<int> inorder(Node *root){
    vector<int> TRAVERSAL;
    stack<Node *> S;
    Node *temp = root;
    while(!S.empty() || temp!=NULL){
        while(temp!=NULL){            
            S.push(temp);
            temp=temp->left;            
        }
        temp=S.top();        
        S.pop();
        TRAVERSAL.push_back(temp->val);
        temp=temp->right;
    }
}

vector<int> postorder(Node *root){
    /*
        0 = going left
        1 = left done, going right        
    */
    vector<int> TRAVERSAL;
    stack<pair<Node *,int>> S;
    Node *temp = root;
    int visited;
    while(!S.empty() || temp!=NULL){
        while(temp!=NULL){            
            S.push({temp,0});
            temp=temp->left;            
        }
        temp=S.top().first;
        visited=S.top().second;        
        S.pop();
        if(visited==0){
            S.push({temp,1});
            temp=temp->right;
        } else {
            TRAVERSAL.push_back(temp->val);
            temp=NULL;
        }        
    }
}



int main(){
    return 0;
}