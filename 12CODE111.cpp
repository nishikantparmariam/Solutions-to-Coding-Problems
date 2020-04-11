#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T;cin>>T;
    while(T--){
        ll N;ll C;
        cin>>N;cin>>C;
        unordered_map<ll,ll> FREQ;
        for(ll i=0;i<N;i++){
            ll val;cin>>val;
            FREQ[val]++;
        }
        priority_queue<ll> pq;
        for(auto it=FREQ.begin(); it!=FREQ.end();it++){
            pq.push(it->second);
        }
        while(C && !pq.empty()){
            if(pq.top()==1) break; 
            ll topVal = pq.top();
            //cout << topVal << " ";
            pq.pop();
            pq.push(topVal-1);
            C--;
        }
        ll toSub = 0;
        while(!pq.empty()){
            if(pq.top()==1) break;
            toSub+=(pq.top()*(pq.top()-1))/2;
            pq.pop();
        }
        cout << (N*(N-1))/2-toSub << endl;
    }
    return 0;
}


2