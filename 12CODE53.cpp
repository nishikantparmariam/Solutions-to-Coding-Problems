#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll solveFor(ll j, ll i, ll BD[], ll YR[]){
    ll prevVal = -1;
    for(ll p=j;p<=i;p++){
        ll bd = BD[p];
        ll yr = YR[p];
        ll count = 0;
        while(bd!=yr){
            bd = (bd+1)%4;
            count++;
        }
        if(prevVal!=-1){
            if(prevVal%4!=count%4){  
                return -1;              
            }            
        }
        prevVal = count;
    }

    return prevVal;
}

int main(){    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T;cin>>T;
    while(T--){
        ll N;cin>>N;
        ll BD[N];
        ll YR[N];
        for(ll i=0;i<N;i++) cin>>BD[i];
        for(ll i=0;i<N;i++) cin>>YR[i];
        ll dp[N];
        for(ll i=0;i<N;i++){
            dp[i] = INT_MAX;
            for(ll j=0;j<=i;j++){
                //Assume that 0..j-1 is correct, solve for j...i
                ll ansHere = solveFor(j, i, BD, YR);
                if(ansHere!=-1){
                    dp[i] = min(dp[i], (j>0 ? dp[j-1] : 0)+ansHere);
                }                
            }
           //cout << dp[i] << " ";
        }
        cout << dp[N-1] << endl;
    }
    return 0;
}