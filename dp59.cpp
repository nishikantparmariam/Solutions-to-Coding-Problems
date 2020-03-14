#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll T;cin>>T;
	while(T--){
	    int N;cin>>N;
	    int arr[N];
	    for(int i=0;i<N;i++) cin>>arr[i];
	    
	    int incr[N];
	    for(int i=0;i<N;i++) incr[i] = arr[i];        
	    for(int i=1;i<N;i++){
	        for(int j=0;j<i;j++){
	            if(arr[j] < arr[i]){
	                incr[i] = max(incr[i], arr[i]+incr[j]);
	            }
	        }            
	    }        
	    
	    int decr[N];
	    for(int i=0;i<N;i++) decr[i] = arr[i];	    
	    for(int i=N-2;i>=0;i--){
	        for(int j=i+1;j<N;j++){
	            if(arr[j] < arr[i]){
	                decr[i] = max(decr[i], arr[i]+decr[j]);
	            }
	        }            
	    }
	    
	    int ans = arr[0];
	    for(int i=0;i<N;i++){            
	        ans = max(ans, incr[i]+decr[i]-arr[i]);
	    }
	    cout << ans << endl;
	}
	return 0;
}