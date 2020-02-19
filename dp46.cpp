//3D - dp problem with 2D space optimization
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
bool isValid(int i, int j, int N){
    if(i>=0 && i<N && j>=0 && j<N) return true;
    return false;
}
int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll T;cin>>T;
	while(T--){
	    int N;int X;int Y;int K;
	    cin>>N;cin>>X;cin>>Y;cin>>K;
	    if(!isValid(X,Y,N)) {
            cout << "0.000000" << endl;
        } else if(K==0){
            cout << "1.000000" << endl;
        } else {
            double dp[N][N];
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    dp[i][j] = 1;
                }
            }
            for(int k=1;k<=K;k++){
                double dp_prev[N][N];
                for(int i=0;i<N;i++){
                    for(int j=0;j<N;j++){
                        dp_prev[i][j] = dp[i][j];
                    }
                }
                for(int i=0;i<N;i++){
                    for(int j=0;j<N;j++){
                        dp[i][j]=0;
                        if(isValid(i-2,j+1, N)){
                            dp[i][j]+=(0.125000)*dp_prev[i-2][j+1];
                        }
                        if(isValid(i-1,j+2, N)){
                            dp[i][j]+=(0.125000)*dp_prev[i-1][j+2];
                        }
                        if(isValid(i+1,j+2, N)){
                            dp[i][j]+=(0.125000)*dp_prev[i+1][j+2];
                        }
                        if(isValid(i+2,j+1, N)){
                            dp[i][j]+=(0.125000)*dp_prev[i+2][j+1];
                        }
                        if(isValid(i+2,j-1, N)){
                            dp[i][j]+=(0.125000)*dp_prev[i+2][j-1];
                        }
                        if(isValid(i+1,j-2, N)){
                            dp[i][j]+=(0.125000)*dp_prev[i+1][j-2];
                        }
                        if(isValid(i-1,j-2, N)){
                            dp[i][j]+=(0.125000)*dp_prev[i-1][j-2];
                        }
                        if(isValid(i-2,j-1, N)){
                            dp[i][j]+=(0.125000)*dp_prev[i-2][j-1];
                        }
                    }
                }
            }
            
            cout << fixed << setprecision(6) << dp[X][Y] << endl; 
        }	    
	}
	return 0;
}