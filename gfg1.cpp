#include <bits/stdc++.h>
using namespace std;
typedef int ll;

struct myComp {
    bool operator()(const pair<ll,ll> &p1, const pair<ll,ll> &p2){
        return p1.first > p2.first;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T;cin>>T;
    while(T--){
        ll N;cin>>N;
        vector<pair<ll,ll>> adjList[N];
        for(ll i=0;i<N;i++){
            for(ll j=0;j<N;j++){
                ll cost;cin>>cost;   
                if(i!=j && cost!=-1){
                    adjList[i].push_back(make_pair(cost, j));                        
                }                                              
            }
        }

        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, myComp> pq;
        ll finalAns = 0;
        pq.push(make_pair(0,0));
        bool isinMST[N];
        ll weights[N];
        for(ll i=0;i<N;i++){
            isinMST[i] = false;        
            weights[i] = INT_MAX;
        } 

        ll numNodes = 0;
        while(!pq.empty()){
            pair<ll,ll> p = pq.top();            
            pq.pop();            
            if(isinMST[p.second]) continue;
            numNodes++;
            finalAns+=p.first; 
            isinMST[p.second] = true;

            if(numNodes==N) break;

            for(pair<ll,ll> p2:adjList[p.second]){
                ll v = p2.second;
                ll w = p2.first;
                if(isinMST[v]==false){
                    pq.push(make_pair(w, v));
                }
            }

            
        }

        cout << finalAns << endl;
    }
    return 0;
}