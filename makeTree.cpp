#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *makeNode(string num){
    int data = stoi(num);
    struct Node *newNode = (struct Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *makeTree(string tree, int s, int e){
    if(s+1 > e-1) return NULL;
    string data = "";
    int m = s+1;
    while(tree[m]!='(' && tree[m]!=')'){
        data+=tree[m];
        m++;
    }
    Node *root = makeNode(data);
    int p = m;
    int open_count = 0;
    int close_count = 0;
    while(true){
        if(tree[p]=='(') open_count++;
        else if(tree[p]==')') close_count++;
        if(open_count==close_count){
            break;
        }
        p++;
    }
    
    root->left = makeTree(tree, m, p);
    root->right = makeTree(tree, p+1,e-1);
    return root;
    
}

void inorder(Node *root){
    if(root==NULL) return;
    inorder(root->left);
    cout << root->data << endl;
    inorder(root->right);
}

int sumAtLeveL(Node *root, int current_level, int K){
    if(root==NULL) return 0;
    if(current_level==K){
        return root->data;
    }
    return sumAtLeveL(root->left,current_level+1,K)+sumAtLeveL(root->right, current_level+1,K);
}

int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll T;cin>>T;
	while(T--){
	    int K;cin>>K;
	    string tree;
	    cin>>tree;
	    Node *root = makeTree(tree, 0, tree.size()-1);	        
        cout << sumAtLeveL(root, 0, K) << endl;        
	}
	return 0;
}