#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N;ll M;ll MOD;ll V;
    cin>>N;cin>>M;cin>>MOD;cin>>V;
    ll grid[N][M];
    for(ll i=0;i<N;i++){
        for(ll j=0;j<M;j++){
            cin>>grid[i][j];
            grid[i][j] = grid[i][j]%MOD;
        }
    }

    ll sum[N][M];
    /*O(NxM)*/
    for(ll i=0;i<N;i++){
        for(ll j=0;j<M;j++){
            //sum[i][j] denotes sum from (0,0) to (i,j)
            sum[i][j] = ((((i>0?sum[i-1][j]:0)%MOD+(j>0?sum[i][j-1]:0)%MOD)%MOD+MOD-(i>0&&j>0?sum[i-1][j-1]:0)%MOD)%MOD+grid[i][j]%MOD)%MOD;
        }
    }    

    ll ans = 0;
        
    unordered_map<ll,ll> MAP; 
    for(ll col1=0;col1<M;col1++){
        for(ll col2=col1;col2<M;col2++){                   
            MAP.clear();           
            for(ll i=0;i<N;i++){
                ll prefixSum = (sum[i][col2]%MOD-(col1>0?sum[i][col1-1]:0)%MOD+MOD)%MOD;       //sum till the current row between col1 and col2         
                if(prefixSum%MOD==V) ans++;                
                ans+=MAP[prefixSum-V+(prefixSum-V < 0 ? MOD : 0)];
                MAP[prefixSum]++;
            }                       
        }
    }
         

    cout << ans;


    return 0;
}