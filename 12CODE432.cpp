#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T;cin>>T;
    while(T--){
        string S;cin>>S;
        ll N = S.size();
        vector<ll> arr(N, 0);
        for(ll i=0;i<N;i++){
            arr[i] = (ll)(S[i]-'a');                        
        }       
           

        for(int i=0;i<N;i++){
            int j = arr[i];
            //take this in increasing
            for(int k=0;k<26;k++){
                for(int p=0;p<=j;p++){
                    dp[i][j][k] = max(dp[i][j][k], 1+ (i>0 ? dp[i-1][p][k] : 0));
                }
            }

            //take this in decreasing
            for(int k=0;k<26;k++){
                for(int p=j;p<26;p++){
                    dp[i][k][j] = max(dp[i][k][j], 1+(i>0 ? dp[i-1][k][p] : 0) );
                }
            }

            //do not take it
            for(int k=0;k<26;k++){
                for(int p=0;p<26;p++){
                    dp[i][k][p] = max(dp[i][k][p], (i>0 ? dp[i-1][k][p] : 0));
                }
            }
            
        }


        int ans = 0;
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                ans = max(ans, dp[N-1][i][j]);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
    