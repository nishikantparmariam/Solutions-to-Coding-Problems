/*
Reference : https://www.geeksforgeeks.org/prime-factorization-using-sieve-olog-n-multiple-queries/
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll N_MAX = (ll)(1e6+1);
ll spf[N_MAX];

void makeSieve(){
    spf[1] = 1; 
    for(ll i=2;i<N_MAX;i++){
        spf[i]=i;
    }
    for(ll i=4;i<N_MAX;i+=2){
        spf[i]=2;
    }
    for(ll i=3;i*i<N_MAX;i++){
        if(spf[i]==i){
            for(ll j=i*i;j<N_MAX;j+=i){
                if(spf[j]==j){
                    spf[j] = i;
                }
            }
        }
    }
}


unordered_map<ll,ll> fact(ll N){
    unordered_map<ll,ll> MAP;
    while(N!=1){
        MAP[spf[N]]++;
        N = N/spf[N];
    }
    return MAP;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    makeSieve();

    ll T;cin>>T;
    while(T--){
        ll N;cin>>N;
        ll ANS = 1;
        unordered_map<ll,ll> count = fact(N);
        for(auto it=count.begin();it!=count.end();it++){
            if((it->second)%2==1){
                ANS = ANS*(it->first);
            }
        }
        cout << ANS << endl;
    }

    return 0; 
}