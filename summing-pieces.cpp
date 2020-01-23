#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll MOD = 1000000007;
    ll N;cin>>N;
    ll arr[N];
    for(ll i=0;i<N;i++){
        cin>>arr[i];
        arr[i] = arr[i]%MOD;
    }

    ll sum[N];
    ll ways[N];
    sum[0] = arr[0]%MOD;
    ways[0] = 1;
    for(ll i=1;i<N;i++){
        ll numways = 0;
        sum[i] = 0;
        sum[i]=((sum[i]%MOD)+(((ways[i-1]%MOD)*(arr[i]%MOD))%MOD+sum[i-1]%MOD)%MOD)%MOD;
        numways=(numways%MOD+ways[i-1]%MOD)%MOD;        
        ll sumTillj = arr[i];
        for(ll j=i-1;j>=0;j--){
            sumTillj=(sumTillj%MOD+arr[j]%MOD)%MOD;            
            if(j>0){
                sum[i]=(sum[i]%MOD+(((ways[j-1]%MOD)*(sumTillj%MOD)*((i-j+1)%MOD))%MOD+sum[j-1]%MOD)%MOD)%MOD;
                numways=(numways%MOD+ways[j-1]%MOD)%MOD;
            } else {
                sum[i]=(sum[i]%MOD+((sumTillj%MOD)*((i-j+1)%MOD))%MOD)%MOD;                
                numways=(numways%MOD+1)%MOD;
            }                     
        }

        ways[i] = numways;
        
    }
    cout << sum[N-1]%MOD << endl;

    return 0;
}