#include <bits/stdc++.h>
using namespace std;
typedef int ll;
int maxy;

ll findCount(ll arr[], ll x1, ll x2, ll y, ll N){
    ll count = 0;
    if(y>maxy) return count;
    if(x1>=1 && x2<=N){
        for(ll i=max(0, x1-1);i<min(N-1, x2+1);i++){        
            if((i+1 >= x2) || (i+2 <= x1)){
                continue;   
            } else {            
                if( (arr[i]<=y && arr[i+1]>=y) || (arr[i]>=y && arr[i+1]<=y) ){
                    if(arr[i]==arr[i+1]){
                        if(x2 < i+1 || x1 > i+2){
                            continue;
                        } else count++;     
                    } else {
                        double x = (double)((double)((y-arr[i])/(arr[i+1]-arr[i]))+i+1);                    
                        if(x>=x1 && x<=x2) count++;
                    }
                }
            } 
        }
    }    
    return count;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T;cin>>T;
    while(T--){
        ll N;cin>>N;
        ll Q;cin>>Q;  
        ll arr[N];      
        maxy = -INT_MAX;
        for(ll i=0;i<N;i++) {
            cin>>arr[i];
            maxy = max(arr[i], maxy);
        }
        while(Q--){
            ll x1;ll x2;ll y;
            cin>>x1;cin>>x2;cin>>y;
            cout << findCount(arr, x1, x2, y, N) << endl;
        }
    }
    return 0;
}