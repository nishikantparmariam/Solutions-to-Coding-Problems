#include<bits/stdc++.h>
using namespace std;
int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T;cin>>T;
	while(T--){ 
	    string S;cin>>S;
        //S = "ababbbabbababa";
	    int N = S.size();
	    bool isPalindrome[N][N];
	    for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(i==j) isPalindrome[i][i] = true;
                else isPalindrome[i][j] = false;
            }	        
	    }
	    for(int length=1;length<=N;length++){
	        for(int i=0;i<=N-length-1;i++){
	            int j=i+length;
	            if(length==1){
                    if(S[i]==S[j]) isPalindrome[i][j] = true;
                    else isPalindrome[i][j] = false;
                }
                else {
                    if(S[i]==S[j]) isPalindrome[i][j] = isPalindrome[i+1][j-1]; 
                    else isPalindrome[i][j] = false;
                }
	        }
	    }

        int minCuts[N][N];

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                minCuts[i][j] = 0;
                /*if(isPalindrome[i][j]){
                    cout << 1 << " ";
                } else cout << 0 << " ";*/
                
            }
           // cout << endl;
        }

       // cout << endl << endl;
        

        int minCutsTillNow[N];

        for(int i=0;i<N;i++){
	        if(isPalindrome[0][i]){
	            minCutsTillNow[i] = 0;
	        } else {
	            minCutsTillNow[i] = INT_MAX;
	            for(int j=0;j<i;j++){
	                if(isPalindrome[j+1][i]){
	                    minCutsTillNow[i] =
	                    min(minCutsTillNow[i], 1+minCutsTillNow[j]);
	                }
	            }
	        }
	    }
       
        cout << minCutsTillNow[N-1] << endl;
        

	}
	return 0;
}