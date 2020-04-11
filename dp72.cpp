#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;cin>>N;
    int arr[N];
    for(int i=0;i<N;i++) cin>>arr[i];
    int K;cin>>K;
    int dp[K+1][N];
    for(int k=0;k<=K;k++){
        for(int i=0;i<N;i++){
            if(k==0) dp[k][i] = 0;
            else if(i==0) dp[k][i] = (arr[i] <= k ? 1 : 0);
            else {
                dp[k][i] = dp[k][i-1] + ((arr[i] <= k && arr[i] > 0) ? (dp[k/arr[i]][i-1] + 1) : 0);
            }
        }
    }
    cout << dp[K][N-1] << endl;
    return 0;
}