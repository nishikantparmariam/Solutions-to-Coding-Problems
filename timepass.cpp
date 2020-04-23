#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll T;cin>>T;
    while(T--){
        int N;cin>>N;
        vector<int> arr(N);
        for(int i=0;i<N;i++) cin>>arr[i];
        vector<int> dp(N, 1);
        int ans = dp[0];
        for(int i=0;i<N;i++){
            for(int j=0;j<=i-1;j++){
                if(arr[j] < arr[i]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
    }
    return 0;
}