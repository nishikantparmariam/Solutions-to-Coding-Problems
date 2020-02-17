#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll go(ll i, ll arr[], ll prev, ll N){
    if(i>=N) return 0;        
    if(arr[i]<=prev){        
        return 1+go(i+1, arr, prev+1, N);
    } else {
        if(arr[i]==prev+1){
            return go(i+1, arr, arr[i], N);
        } else {
            return min(go(i+1, arr, arr[i], N),1+go(i+1, arr, prev+1, N));
        }
    }
} 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T;cin>>T;
    while(T--){
        ll N;cin>>N;
        ll arr[N];
        for(ll i=0;i<N;i++){
            cin>>arr[i];
        }
        //cout << go(0,arr,-INT_MAX, N) << endl;
        
    }
    return 0;
}