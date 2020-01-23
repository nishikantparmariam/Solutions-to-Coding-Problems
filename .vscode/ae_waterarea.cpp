#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll T;cin>>T;
	while(T--){
	    ll N;cin>>N;
	    ll arr[N];
	    for(ll i=0;i<N;i++){
	        cin>>arr[i];
	    }
	    ll leftMaxIndex[N];
	    ll rightMaxIndex[N];
	    leftMaxIndex[0] = 0;
	    rightMaxIndex[N-1] = N-1;
	    for(ll i=1;i<N;i++){
	        if(arr[i]>arr[leftMaxIndex[i-1]]){
	            leftMaxIndex[i] = i;
	        } else {
	            leftMaxIndex[i] = leftMaxIndex[i-1];
	        }
	        cout << leftMaxIndex[i] << "--";
	    }
	    for(ll i=N-2;i>=0;i--){
	        if(arr[i]>arr[rightMaxIndex[i+1]]){
	            rightMaxIndex[i] = i;
	        } else {
	            rightMaxIndex[i] = rightMaxIndex[i+1];
	        }
	    }
	    
	    ll ans = 0;
	    for(ll i=0;i<N;i++){
	        if(leftMaxIndex[i]!=i && rightMaxIndex[i]!=i){
	            ll minHeight = min(leftMaxIndex[i],rightMaxIndex[i]);
	            if(minHeight>arr[i]){
	                ans+=minHeight-arr[i];
	            }
	        }
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}