#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool cmp_func(const pair<ll,pair<ll,ll>> &p1, const pair<ll,pair<ll,ll>> &p2){
    if(p1.first == p2.first){
        return p1.first+p1.second.first+p1.second.second < p2.first+p2.second.first+p2.second.second;
    }
    return p1.first < p2.first;
}

struct Node {
    ll rank;
    struct Node *parent;
    ll v;
};

struct Node * newNode(ll v){
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->rank = 0;
    new_node->parent = NULL;
    new_node->v = v;
    return new_node;
}

struct Node* find(ll vertex, struct Node* labels_array[]){
    struct Node *root  = labels_array[vertex];
    while(root->parent!=NULL){
        root = root->parent;
    }
    /*log*(n) wala improvement*/
    struct Node *v  = labels_array[vertex];
    while(v!=root){
        struct Node *temp = v;
        v = v->parent;
        temp->parent=root;
    }
    /*log*(n) wala improvement*/


    return root;
}

void union_set(struct Node *root1, struct Node *root2){
    if(root1==root2) return;
    if(root1->rank == root2->rank){
        root1->rank = root1->rank+1;
        root2->parent = root1;
    } else if(root1->rank > root2->rank){
        root2->parent = root1;
    } else {
        root1->parent = root2;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N; ll M;
    cin>>N;cin>>M;
    vector<pair<ll,ll>> adjList[N];
    vector<pair<ll,pair<ll,ll>>> edges;
    for(ll i=0;i<M;i++){
        ll u; ll v; ll w;
        cin>>u;cin>>v;cin>>w;
        u--;v--;
        edges.push_back(make_pair(w,make_pair(u, v)));       
        adjList[u].push_back(make_pair(v,w));
        adjList[v].push_back(make_pair(u,w));
    }

    sort(edges.begin(), edges.end(), cmp_func);

    struct Node * labels_array[N];
    for(ll i=0;i<N;i++){
        labels_array[i] = newNode(i);
    }
    

    ll MST_sum = 0;
    //cout << edges.size() << endl;
    for(pair<ll,pair<ll,ll>> edge:edges){
        ll u = edge.second.first;
        ll v = edge.second.second;
        ll w = edge.first;
        //cout << u << " " << v << " " << w << endl;        
        struct Node *root1 = find(u,labels_array);
        struct Node *root2 = find(v,labels_array);
        if(root1!=root2){
            MST_sum+=w;
            union_set(root1, root2);
        }
    }
    
    cout << MST_sum << endl;

    return 0;
}
