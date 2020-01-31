#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct Node {
    int data;
    int * children;
    int height;
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;cin>>T;
    while(T--){
        ll N;cin>>N;
        ll A[N];
        for(ll i=0;i<N;i++) cin>>A[i];        
        if(N==1) cout << A[0] << endl;
        else if(N==2) cout << max(A[0], A[1]) << endl;
        else {
            //when B[0] = 0 
            ll dp[N][2];
            dp[0][0] = 0;
            dp[0][1] = 0;
            for(ll i=1;i<N;i++){
                if(i==1){
                    dp[i][0] = 0;
                    dp[i][1] = A[i];
                } else {
                     dp[i][0] = max(dp[i-1][0], dp[i-1][1]+A[i-1]);
                     dp[i][1] = max(dp[i-1][0]+A[i], dp[i-1][1]+abs(A[i]-A[i-1]));
                }               
            }
            

            //when B[0] = A[0]
            ll dp2[N][2];
            dp2[0][0] = 0;
            dp2[0][1] = 0;
            for(ll i=1;i<N;i++){
                if(i==1){
                    dp2[i][0] = A[i-1];
                    dp2[i][1] = abs(A[i]-A[i-1]);
                } else {
                     dp2[i][0] = max(dp2[i-1][0], dp2[i-1][1]+A[i-1]);
                     dp2[i][1] = max(dp2[i-1][0]+A[i], dp2[i-1][1]+abs(A[i]-A[i-1]));
                }               
            }

            ll ans1 = max(dp[N-1][0], dp[N-1][1]+A[N-1]);
            ll ans2 = max(dp2[N-1][0]+A[0], dp2[N-1][1]+abs(A[N-1]-A[0]));
            cout << max(ans1, ans2) << endl;

        }
        

    }
    return 0;
}