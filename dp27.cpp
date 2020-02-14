#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll T;cin>>T;
	while(T--){
	    int n;cin>>n;
	    unordered_map<string,bool> MAP;
	    for(int i=0;i<n;i++){
	        string s;
	        cin>>s;
	        MAP[s] = true;
	    }
	    string S;
	    cin>>S;
	    int N = S.size();
	    bool dp[N];
	    for(int i=0;i<N;i++){
	        dp[i] = false;
	    }
	    
	    for(int i=0;i<N;i++){
	        if(i==0){
	            if(MAP[S.substr(0,1)]){
	                dp[i] = true;
	            }
	        }
	        for(int j=i;j>=0;j--){                
                if(j==0){
                    if(MAP[S.substr(j,i-j+1)]){
                        dp[i] = true;
                        break;
                    }
                } else if(dp[j-1] && MAP[S.substr(j,i-j+1)]){
                    dp[i] = true;
                    break;
                }
	        }            
	    }        
        if(dp[N-1]){
            cout << 1 << endl;
        } else cout << 0 << endl;
	}
	return 0;
}