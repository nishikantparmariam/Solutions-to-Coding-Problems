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
            ll totalSum = 0;
            for(ll i=0;i<N;i++){
                cin>>arr[i];
                totalSum+=arr[i];
            } 
            
            bool dp[N][totalSum+1];
            memset(dp,false,sizeof(dp));
            for(ll i=0;i<N;i++){
                for(ll sum=0;sum<=totalSum;sum++){
                    if(sum==0){
                        dp[i][sum] = true;
                    } else if(sum < arr[i]){
                        if(i>0) dp[i][sum] = dp[i-1][sum];
                        else dp[i][sum] = false;
                    } else {
                        if(i>0) dp[i][sum] = dp[i-1][sum] | dp[i-1][sum-arr[i]];
                        else {
                            if(sum==arr[i]) dp[i][sum] = true;
                            else dp[i][sum] = false;
                        }
                    }            
                }            
                
            }

            ll ans = INT_MAX;

            for(ll i=0;i<N;i++){
                for(ll sum=0;sum<=totalSum;sum++){
                    if(dp[i][sum]){
                        ans = min(ans, abs((totalSum-sum)-(sum)));
                    }
                }
            }

            cout << ans << endl;
        
        }
        return 0;
    }