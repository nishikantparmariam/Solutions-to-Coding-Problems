#include <bits/stdc++.h>
#include <string>
using namespace std;

int numWays(int i, string S){
    
    if(i==S.size()) return 1;
    if(S[i]=='0') return 0;
    if(i==S.size()-1) return 1;
    
    
    if(stoi(S.substr(i,2))<=26){
        int a = numWays(i+1,S);
        int b = numWays(i+2,S); 
        return a+b;
    }
    return numWays(i+1,S);
}
int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	//code
	int T;cin>>T;
	while(T--){
	    int N;cin>>N;
	    string S;cin>>S;
	    //cout << numWays(0,S) << endl;
	    int dp[N];
	    for(int i=0;i<N;i++){
	        if(i==0) {
	            if(S[i]!='0') dp[i] = 1;
	            else dp[i] = 0;
	        } else {
	            if(stoi(S.substr(i-1,2))<=26){
	                dp[i]=0;
                    if(S[i]!='0') dp[i] = dp[i-1];
                    else dp[i] = 0;
                    if(S[i-1]!='0'){
                        if(i<2) dp[i]++;
                        else dp[i]+=dp[i-2];
                    }   
	            } 
	            else {
	                if(S[i]=='0'){
	                    dp[i] = 0;
	                } else {
	                    dp[i] = dp[i-1];
	                }  
	            }
	        }
	    }
	    cout << dp[N-1] << endl;
	}
	return 0;
}