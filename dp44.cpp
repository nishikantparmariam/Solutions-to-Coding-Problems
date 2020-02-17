#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll T;cin>>T;
	while(T--){
	    int K;cin>>K;
	    int N;cin>>N;
	    int grid[N][N];
	    for(int i=0;i<N;i++){
	        for(int j=0;j<N;j++){
	            cin>>grid[i][j];
	        }
	    }
	    
	    for(int i=N-1;i>=0;i--){
	        for(int j=N-1;j>=0;j++){
	            if(i==N-1 && j==N-1){
	                
	            } else if(i==N-1){
	                
	            } else if(j==N-1){
	                
	            } else {
	                
	            }
	        }
	    }
	}
	return 0;
}