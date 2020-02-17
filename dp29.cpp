#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
pair<int,int> dp[105][105][2];
pair<int,int> go(int i, int j, bool turn, int arr[]){
    if(turn){
        if(dp[i][j][0].first!=-1) return dp[i][j][0];
    } else {
        if(dp[i][j][1].first!=-1) return dp[i][j][1];
    }
    if(i==j) {
        if(turn){
            dp[i][j][0] = make_pair(arr[i], 0);            
            return dp[i][j][0];
        } else {
            dp[i][j][1] = make_pair(0, arr[i]);            
            return dp[i][j][1];
        }
    }
    pair<int,int> pair_1 = go(i+1,j,!turn,arr);
    pair<int,int> pair_2 = go(i,j-1,!turn,arr);
    int p1_score;
    int p2_score;
    if(turn){
        if(arr[i]+pair_1.first > arr[j]+pair_2.first){
            p1_score = arr[i]+pair_1.first;
            p2_score = pair_1.second;
        } else {
            p1_score = arr[j]+pair_2.first;
            p2_score = pair_2.second;
        }        
    
    }  else {
        if(arr[j]+pair_2.second > arr[i]+pair_1.second){
            p2_score = arr[j]+pair_2.second;
            p1_score = pair_2.first;
        } else {
            p2_score = arr[i]+pair_1.second;
            p1_score = pair_1.first;
        }
    }

    if(turn){
        dp[i][j][0] = make_pair(p1_score, p2_score);
        return dp[i][j][0];
    } else {
        dp[i][j][1] = make_pair(p1_score, p2_score);    
        return dp[i][j][1];
    }

    //return make_pair(p1_score, p2_score);
}
int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll T;cin>>T;
	while(T--){
	    int N;cin>>N;
	    int arr[N];
        for(int i=0;i<N+2;i++){
            for(int j=0;j<N+2;j++){
                dp[i][j][0] = make_pair(-1, -1);
                dp[i][j][1] = make_pair(-1, -1);
            }
        }
	    for(int i=0;i<N;i++){
	        cin>>arr[i];
	    }
        cout << go(0, N-1, true,arr).first << endl;	    
	}
	return 0;
}