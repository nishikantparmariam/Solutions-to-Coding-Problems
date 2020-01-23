#include<bits/stdc++.h>
using namespace std;
/*


bool canPartition(int i, int sum1, int sum2, int N, int arr[], 
    bool hasValue[][100000][100000], bool dp[][100000][100000]){
    if(i==N){
        if(sum1==sum2) return true;
        else return false;
    } else {
        if(hasValue[i][sum1][sum2]){
            return dp[i][sum1][sum2];
        }
        
        dp[i][sum1][sum2] = canPartition(i+1,sum1+arr[i],sum2,N,arr,
            hasValue, dp)
            | canPartition(i+1,sum1,sum2+arr[i],N,arr, hasValue, dp);
        hasValue[i][sum1][sum2] = true;
        return dp[i][sum1][sum2];
    }
}*/


int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	//code
	int T;cin>>T;
	while(T--){
	    
	    int N;cin>>N;
	    int arr[N];
	    int sum = 0;
	    for(int i=0;i<N;i++){
	        cin>>arr[i];
	        sum+=arr[i];
	    }
	    if(sum%2!=0){
	        cout << "NO" << endl;
	    } else {
	        bool dp[sum/2+1][N];            
	        for(int s=0;s<=sum/2;s++){                
	            for(int i=0;i<N;i++){
	                if(i==0){
    	                if(arr[i]==s) dp[s][i] = true;
    	                else dp[s][i] = false;
    	            }
    	            else if(s-arr[i]>=0){
    	                dp[s][i] = dp[s-arr[i]][i-1] |  dp[s][i-1];
    	            } else dp[s][i] = dp[s][i-1];
                    /*if(dp[s][i]) cout << "1 ";
                    else cout << "0 "; */
	            }
                cout << endl;
	        }
	        
	        if(dp[sum/2][N-1]){
	            cout << "YES" << endl;
	        } else {
	            cout << "NO" << endl;
	        }
	    }
	    
	}
	return 0;
}