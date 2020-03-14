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
        int min_el = INT_MAX;
        int max_el = -INT_MAX;
	    for(int i=0;i<N;i++){
	        cin>>arr[i];
            min_el = min(arr[i], min_el);
            max_el = max(arr[i], max_el);
	    }
        int maxDiff = max_el-min_el;
        int dp[N][maxDiff+1];
        int ans = 0;
        for(int i=0;i<N;i++){            
            for(int d=0;d<=maxDiff;d++){                
                if(d==0) dp[i][d] = 0;
                else {
                    if(i==0){
                        dp[i][d] = 1;
                    } else {
                        if(true){
                            //from i-d to i-1 both inclusive
                            int low = 0;//i-d;
                            int high = i-1;
                            int ansIndex = -1;
                            while(low<=high){
                                int mid = (low+high)/2;
                                int diff = arr[i]-arr[mid];
                                if(diff==d){
                                    ansIndex = mid;
                                    break;
                                } else if(diff > d){
                                    low = mid+1;
                                } else {
                                    high = mid-1;
                                }
                            }

                            if(ansIndex!=-1){
                                dp[i][d] = 1+dp[ansIndex][d];
                            } else {
                                dp[i][d] = 1;
                            }                            
                        } else {
                            dp[i][d] = 1;
                        }
                    }                    
                }               
                ans = max(ans, dp[i][d]);
            }            
        }

        cout << ans << endl;
 	}
	return 0;
}