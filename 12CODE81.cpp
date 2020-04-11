#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll K;


void prllStack(stack<ll> &STACK){
    if(STACK.size()>0){
        ll x = STACK.top();
        STACK.pop();
        prllStack(STACK);
        cout << x+K << " ";
    }
}

void recurse(ll i, ll left, ll N, stack<ll> &STACK){   
    if(i>N){
        if(left==0){
            stack<ll> STACK2 = STACK;
            prllStack(STACK2);
            cout << endl;
        }
    } else {
        for(ll j=0;j<=left;j++){
            STACK.push(j);
            recurse(i+1,left-j,N,STACK);
            STACK.pop();
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    ll N;ll S;
    cin>>N;cin>>S;cin>>K;
    if(K*N==S){
        for(ll i=0;i<N;i++){
            cout << K << " ";
        }        
        cout << endl;
    } else if(K*N < S){        
        stack<ll> STACK;
        recurse(1,S-K*N,N,STACK);        
    }   
    cout << -1 << endl;
    return 0; 
}