#include<bits/stdc++.h>
using namespace std;
long long int MOD_ =  100000000000000000000000007;
long long int go(int N, vector<int> steps, int dp[]){
	//cout << N << endl;
	if(N<0) return 0;
	if(dp[N]!=-1) return dp[N];
	if(N==0) dp[N] =  1;
	else {
		dp[N] = 0;
		for(int x:steps) dp[N]+=go(N-x, steps,dp);
	}	
	return dp[N];
}
int main() {
	int N = 105;
	unsigned long long int dp[N+1];
	memset(dp, -1, sizeof(dp));
	vector<int> steps = {1,2,3,4,5,6,7,8,9,10};
	for(int i=0;i<=N;i++){
		if(i==0) dp[i] = 1;
		else {
			dp[i] = 0;
			for(int x:steps){
				if(i-x>=0){
					dp[i]+=dp[i-x]%MOD_;
				}
			}
		}
		cout << dp[i]%MOD_ << " ";
	}
	
	//cout << dp[N];
	return 0;
}