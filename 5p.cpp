#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
pair<pair<ll,ll>,ll> go(ll i, ll arr[], ll N){
    //cout <<"(" << i << " " << N-2 << ") ";
    if(N==2 || i==N-2){        
        return make_pair(make_pair(arr[i], arr[i+1]), 0);        
    } if(i==N-3){        
        return make_pair(make_pair(arr[i], arr[i+2]), arr[i]*arr[i+1]*arr[i+2]);  
    } else {

        
        ll prod_final_ = INT_MAX;
        ll end_point = -1;

        for(ll k=i+2;k<=N-2;k++){
            pair<pair<ll,ll>,ll> p1 = go(k,arr, N);            
            ll prod_final = p1.second;
            for(ll m=2;m<=k;m++){
                prod_final+=arr[i]*arr[m-1]*arr[m-2];                
            }
            prod_final+=arr[i]*p1.first.first*p1.first.second;
            prod_final_ = min(prod_final_, prod_final);
            if(prod_final_ > prod_final){
                prod_final_ = prod_final;
                end_point = p1.first.second;
            }
        }

        //pair<pair<ll,ll>,ll> p1 = go(i+2,arr, N);
        pair<pair<ll,ll>,ll> p2 = go(i+1,arr, N);        
        //ll prod1 = (arr[i]*arr[i+1]*arr[i+2])+(arr[i]*arr[i+2]*p1.first.second)+p1.second;

        ll prod2 = arr[i]*p2.first.first*p2.first.second+p2.second;
        
        
         //* cout << "i= "<< i <<", (" << arr[i] << ", " <<  p1.first.second << "), " << prod1 << ", (" << arr[i] << ", " <<  p2.first.second << "), " << prod2 << endl;   
        if(prod_final_ < prod2){                    
            return make_pair(make_pair(arr[i], end_point), prod_final_);
        } else {                        
            return make_pair(make_pair(arr[i], p2.first.second), prod2);
        }
    }
}
int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T;cin>>T;
    while(T--){
        ll N;cin>>N;
        ll arr[N];
        for(ll i=0;i<N;i++) cin>>arr[i];
        pair<pair<ll,ll>,ll> ans = go(0, arr, N);
        cout << ans.second << endl;
    }
	return 0;
}