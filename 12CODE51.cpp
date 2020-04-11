#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 10;
ll N;
ll power(ll N, ll p){
    int a = p%4;
    if(a==0) return 6;
    else if(a==1) return 2;
    else if(a==2) return 4;
    else return 8;
    /*
    if(p==0) return 1;
    ll res = 1;
    while(p){
        if(p&1) res = (N%MOD*res%MOD)%MOD;
        N = (N%MOD*N%MOD)%MOD;
        p = p>>1;
    }
    return res%MOD;*/
}

int main(){    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    int T;cin>>T;
    while(T--){
        cin>>N;
        if(N%2==1){            
            cout << "NO\n";
        } else {
            cout << (N%MOD*power(2,N-1)%MOD)%MOD << "\n";
        }
    }
    return 0;
}