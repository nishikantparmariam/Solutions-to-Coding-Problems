#include <bits/stdc++.h>
using namespace std;

//setup[0][i-1]
//setup[1][i-1]

// / _ \
// 0 1 2

int main(){    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        vector<vector<char>> setup(2, vector<char> (N, 0));        
        for(int i=0;i<N;i++){
            cin>>setup[0][i];
        }
        for(int i=0;i<N;i++){
            cin>>setup[1][i];
        }
        vector<vector<unsigned int>> dp(2, vector<unsigned int> (N+1, (unsigned int)0));  
        dp[0][0] = 0;
        dp[1][0] = INT_MAX;
        for(int i=1;i<=N;i++){
            if(setup[0][i-1]=='/' && setup[1][i-1]=='/'){
                dp[0][i] = min(1+dp[0][i-1], dp[1][i-1]);
                dp[1][i] = min(2+dp[0][i-1], 1+dp[1][i-1]);
            } else if(setup[0][i-1]=='/' && setup[1][i-1]!='/' && setup[1][i-1]!='_'){
                dp[0][i] = min(1+dp[0][i-1], 1+dp[1][i-1]);
                dp[1][i] = min(1+dp[0][i-1], 1+dp[1][i-1]);
            } else if(setup[0][i-1]=='/' && setup[1][i-1]=='_'){
                dp[0][i] = min(1+dp[0][i-1], 1+dp[1][i-1]);
                dp[1][i] = min(2+dp[0][i-1], dp[1][i-1]);
            } else if(setup[0][i-1]!='/' && setup[0][i-1]!='_' && setup[1][i-1]=='/'){
                dp[0][i] = min(1+dp[0][i-1], 1+dp[1][i-1]); 
                dp[1][i] = min(1+dp[0][i-1], 1+dp[1][i-1]);
            } else if(setup[0][i-1]!='/' && setup[0][i-1]!='_' && setup[1][i-1]!='/' && setup[1][i-1]!='_'){
                dp[0][i] = min(1+dp[0][i-1], 2+dp[1][i-1]);
                dp[1][i] = min(dp[0][i-1], 1+dp[1][i-1]);
            } else if(setup[0][i-1]!='/' && setup[0][i-1]!='_' && setup[1][i-1]=='_'){
                dp[0][i] = min(1+dp[0][i-1], 2+dp[1][i-1]);
                dp[1][i] = min(1+dp[0][i-1], dp[1][i-1]);
            } else if(setup[0][i-1]=='_' && setup[1][i-1]=='/'){
                dp[0][i] = min(dp[0][i-1], 1+dp[1][i-1]);
                dp[1][i] = min(2+dp[0][i-1], 1+dp[1][i-1]);    
            } else if(setup[0][i-1]=='_' && setup[1][i-1]!='/' && setup[1][i-1]!='_'){
                dp[0][i] = min(dp[0][i-1], 2+dp[1][i-1]);
                dp[1][i] = min(1+dp[0][i-1], 1+dp[1][i-1]);    
            } else if(setup[0][i-1]=='_' && setup[1][i-1]=='_'){
                dp[0][i] = min(dp[0][i-1], 2+dp[1][i-1]);
                dp[1][i] = min(2+dp[0][i-1], dp[1][i-1]);
            }               
        }

        cout << min(dp[0][N], dp[1][N]) << endl;
        
    }
    return 0;
}