#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int countPalindrome(int i, int j, string S, vector<vector<bool>> &isPalindrome, vector<vector<int>> &dp){
	if(dp[i][j]!=-1) return dp[i][j];

    if(i==j) dp[i][j] =  1;
    else if(i+1==j){
        if(isPalindrome[i][j]){
            dp[i][j] =  3;
        } else dp[i][j] =  2;
    } else {        
        dp[i][j] =  (isPalindrome[i][j] ? 1 : 0)+countPalindrome(i+1,j,S,isPalindrome,dp)+countPalindrome(i,j-1,S,isPalindrome,dp)-countPalindrome(i+1,j-1,S,isPalindrome,dp);        
    }

    return dp[i][j];
}

int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
	ll T;cin>>T;
	while(T--){
	    int N;cin>>N;
	    string S;cin>>S;
	    vector<vector<bool>> isPalindrome(N, vector<bool> (N, false));
	    int ans = 0;
	    for(int len=1;len<=N;len++){
	        int i=0;
	        int j=i+len-1;
	        while(j<N){
	            if(len==1){
	                isPalindrome[i][j] = true;
	            } else if(len==2){
	                if(S[i]==S[j]) isPalindrome[i][j] = true;
	                else isPalindrome[i][j] = false;
	            } else {
	                if(S[i]==S[j]) isPalindrome[i][j] = isPalindrome[i+1][j-1];
	                else isPalindrome[i][j] = false;
	            }
	            i++;
	            j++;
	        }
	    }

	    vector<vector<int>> dp(N, vector<int> (N,-1));
	    cout << countPalindrome(0,N-1,S,isPalindrome,dp) << endl;
	   
	   
	}
	return 0;
}