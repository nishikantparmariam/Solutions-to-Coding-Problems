#include <bits/stdc++.h>
using namespace std;

const int no_child = 26*26;

struct Node {
    int number_of_nodes;
    int nodes_used;
    struct Node * children[no_child];
    bool isEndOfaWord;
};

struct Node *makeNewNode(){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->isEndOfaWord = false;
    newNode->number_of_nodes = 0;
    newNode->nodes_used = 0;
    for(int i=0;i<no_child;i++){
        newNode->children[i] = NULL;
    }
    return newNode;
}

void insert(struct Node *root, vector<int> arr){
    struct Node *temp = root;
    int i = 0;
    while(i<arr.size()){
        if(i!=arr.size()-1){
            if(temp->children[arr[i]]==NULL){
                struct Node *newNode = makeNewNode();
                temp->children[arr[i]] = newNode;
                temp = newNode;
            } else {
                temp = temp->children[arr[i]];
            }
        } else {
            if(temp->children[arr[i]]==NULL){
                struct Node *newNode = makeNewNode();
                newNode->isEndOfaWord = true;
                temp->children[arr[i]] = newNode;                
                temp = newNode;
            } else {
                temp->children[arr[i]]->isEndOfaWord = true;
                temp = temp->children[arr[i]];
            }
        }  
        i++;     
    }
}

void search(struct Node *root, stack<int> &STACK){    
    if(root->isEndOfaWord){
        stack<int> temp = STACK;
        while(!temp.empty()){
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }

    for(int i=0;i<no_child;i++){
        if(root->children[i]){
            STACK.push(i);
            search(root->children[i],STACK);
            STACK.pop();
        }            
    }            
}

int dfs(struct Node *root){
    if(root==NULL) return 0;
    int count = 0;
    if(root->isEndOfaWord) count++;
    for(int i=0;i<no_child;i++){
        dfs(root->children[i]);
        if(root->children[i]) count+=root->children[i]->number_of_nodes;
    }
    root->number_of_nodes = count;
    return count;  
}


int main(){
    struct Node *root = makeNewNode();
    vector<int> A = {12,13,14,10,10,54,65,45};
    vector<int> B = {12,13,14,5,10,54,65,45};
    vector<int> C = {11,13,14,10,10,54,65,45};
    vector<int> E = {11,13,14,10,10,54,65,45,200};
    vector<int> D = {11,13,14,125,10,54,65,45,11,13,14,125,10,54,65,45,11,13,14,125,10,54,65,45,11,13,14,125,10,54,65,45,11,13,14,125,10,54,65,45};
    insert(root, A);
    insert(root, B);
    insert(root, C);
    insert(root, D);
    insert(root, E);
    stack<int> STACK;
    search(root, STACK);
    cout << dfs(root) << endl;
    return 0;
}