#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int sum(int m, int n, int prefix_sum[]){
    if(m>0) return prefix_sum[n]-prefix_sum[m-1];
    return prefix_sum[n];
}

bool isPossible(int arr[], int k, int mid, int N){
    int no_of_workers = 1;
    int sum_now = 0;
    int i = 0;
    while(i<N){
        sum_now+=arr[i];
        if(sum_now>mid){
            no_of_workers++;
            sum_now = arr[i];
        }        
        i++;
    }
  //  cout << "->" <<mid << " " << k << endl;
    if(no_of_workers <= k) return true;
    return false;
}
int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll T;cin>>T;
	while(T--){
	    int k;cin>>k;
	    int n;cin>>n;
	    int arr[n];
        int prefix_sum[n];
        int maxValue = -INT_MAX;
	    for(int i=0;i<n;i++) {
            cin>>arr[i];	   
            if(i==0) prefix_sum[i] = arr[i];
            else prefix_sum[i] = prefix_sum[i-1]+arr[i];
            maxValue = max(maxValue, arr[i]);
        }
        /*
	    int dp[k+1][n];
        int ans = INT_MAX;
	    for(int p=0;p<=k;p++){
	        for(int i=0;i<n;i++){                
	            if(p==0 || p>i+1) dp[p][i] = INT_MAX;
	            else if(p==1){
	                if(i>0) dp[p][i] = arr[i]+dp[p][i-1];
	                else dp[p][i] = arr[i];
	            } else {	                
                    if(i>0){
                        dp[p][i] = INT_MAX;
                        for(int j = i-1; j>=p-2;j--){
                                dp[p][i] = min(max(sum(j+1, i, prefix_sum), dp[p-1][j]), dp[p][i]);
                        }
                    } else {
                        //will never reach here.
                    }                       
	            }

                if(i==n-1){
                    ans = min(ans, dp[p][n-1]);
                }                
	        }                        
	    }

        cout << ans << endl;*/


        //Binary Search Solution
        int low = maxValue;
        int high = prefix_sum[n-1];
        int ans = INT_MAX;
        while(low<=high){
            int mid = (low+high)/2;
            if(isPossible(arr, k, mid, n)){
                ans = min(ans, mid);
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        cout << ans << endl;
	}
	return 0;
}