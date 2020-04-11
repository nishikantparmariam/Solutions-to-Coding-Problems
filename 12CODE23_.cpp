#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll MAX_SIZE = 26*26;

struct Node {    
    struct Node * children[MAX_SIZE];    
    ll nodes_beneath;   
    ll nodes_used; 
};

struct Node *makeNewNode(){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->nodes_beneath = 0;
    newNode->nodes_used = 0;
    for(ll i=0;i<MAX_SIZE;i++){
        newNode->children[i] = NULL;
    }
    return newNode;
}


void insert(struct Node *root, string S){
    struct Node *temp = root;
    for(ll i=0;i<S.size();i++){
        ll char_f = (ll)(S[i]-'a');
        ll char_b = (ll)(S[S.size()-i-1]-'a');
        ll VALUE = char_f*26+char_b;        
        if(!(temp->children[VALUE])) temp->children[VALUE] = makeNewNode();
        temp = temp->children[VALUE];
        temp->nodes_beneath++;
    }
}

void printAll(struct Node *root){
    if(root){
        if(root->nodes_beneath > 0) cout << root->nodes_beneath << endl;
        for(ll i=0;i<MAX_SIZE;i++) printAll(root->children[i]);
    }
}

ll dfs(struct Node *root, ll level, ll *ans){
    if(root==NULL) return 0;    
    root->nodes_used = 0;    
    for(ll i=0;i<MAX_SIZE;i++) {
        root->nodes_used+=dfs(root->children[i], level+1, ans);
    }
    ll left = root->nodes_beneath-root->nodes_used;
    if(left>=2){
        (*ans)+=(left/2)*(level*level);
        left = left%2;
        root->nodes_used = root->nodes_beneath - left;
    }    
    return root->nodes_used;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T;cin>>T;
    while(T--){
        ll N;cin>>N;        
        struct Node *root = makeNewNode();        
        for(ll i=0;i<N;i++){            
            string S;cin>>S;
            insert(root, S);
        }     
        //printAll(root);   
        ll ans = 0;
        dfs(root, 0, &ans);
        cout << ans << endl;        
    }
    return 0;
}