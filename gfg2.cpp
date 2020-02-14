#include <bits/stdc++.h>
using namespace std;

struct Node {
    char c;    
    struct Node *parent;
    int rank;
};

struct Node *makeNode(char v){
    struct Node *newNode = (struct Node *)malloc(sizeof(Node));
    newNode->c = v;
    newNode->parent = NULL;
    newNode->rank = 0;
    return newNode;
}

struct Node *giveRoot(char c, unordered_map<int, struct Node *> &MAP){
    struct Node *curr = MAP[c];
    while(curr->parent!=NULL){
        curr = curr->parent;
    }
    return curr;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;cin>>T;
    while(T--){
        int N;cin>>N; 
        int Q;cin>>Q;  
        unordered_map<int, struct Node *> MAP;     
        for(int i=0;i<N;i++){
            char cc;cin>>cc;
            MAP[cc] = makeNode('a');
        }

        while(Q--){
            string type_q;
            cin>>type_q;
            char c1; char c2;cin>>c1;cin>>c2;
            if(type_q=="arewefriends"){
                if(giveRoot(c1, MAP)==giveRoot(c2, MAP)){
                    cout << 1 << endl;
                } else {
                    cout << 0 << endl;
                }
            } else {
                struct Node *root1 = giveRoot(c1, MAP);
                struct Node *root2 = giveRoot(c2, MAP);
                if(root1!=root2){
                    if(root1->rank==root2->rank){
                        root1->rank = root1->rank+1;
                        root2->parent = root1; 
                    } else if(root1->rank > root2->rank){
                        root2->parent = root1;
                    } else {
                        root1->parent = root2;
                    }
                }
            }
        }

    }
    return 0;
}