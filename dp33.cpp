#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
/*int go(int i, int buffer, int N, int A_screen){
    if(i==N) return A_screen;
    if(i>N) return 0;
    return max(go(i+2, A_screen, N, A_screen), max(go(i+1, buffer, N, A_screen+1), go(i+1, buffer, N, A_screen+buffer)));

} */

bool func(const pair<int,int> &p1, const pair<int,int> &p2){
    return p1.first > p2.first;
}
int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll T;cin>>T;
	while(T--){
	    int N;cin>>N;
	    pair<int,int> dp[N][4];  //screen #As, no of As in buffer
        // 0 print A
        // 1 Ctrl+A
        // 2 Ctrl+C
        // 3 Ctrl+V
        for(int i=0;i<N;i++){
            if(i==0){
                dp[i][0] = make_pair(1,0);
                dp[i][1] = make_pair(0,1);
                dp[i][2] = make_pair(0,0);
                dp[i][3] = make_pair(0,0);
            } else {
                vector<pair<int,int>> s = {dp[i-1][0],dp[i-1][1],dp[i-1][2],dp[i-1][3]};
                sort(s.begin(), s.end(), func);
                dp[i][0] = make_pair(1+s[0].first,s[0].second);
                dp[i][1] = make_pair(s[0].first,s[0].first);
                dp[i][2] = make_pair(0,0);
                dp[i][3] = make_pair(0,0);
            }
        }
	}
	return 0;
}