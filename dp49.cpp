#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


bool func(const pair<int,pair<int,int>> &p1, const pair<int,pair<int,int>> &p2){
    return p1.first > p2.first;
}

int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll T;cin>>T;
	while(T--){
	    int N;int X; int Y;
        cin>>N;cin>>X;cin>>Y;
        int A[N];
        int B[N];
        for(int i=0;i<N;i++) cin>>A[i];
        for(int i=0;i<N;i++) cin>>B[i];

        vector<pair<int,pair<int,int>>> S(N);
        for(int i=0;i<N;i++){
            S[i] = make_pair(abs(A[i]-B[i]), make_pair(A[i], B[i]));
        }

        sort(S.begin(), S.end(), func);

        int x = 0;
        int y = 0;
        int total_profit = 0;
        for(int i=0;i<N;i++){
            pair<int,pair<int,int>> p = S[i];
            int Xi = p.second.first;
            int Yi = p.second.second;
            if(Xi > Yi){
                if(x < X){
                    x++;
                    total_profit+=Xi;
                } else {
                    y++;
                    total_profit+=Yi;
                }
            } else {
                if(y < Y){
                    y++;
                    total_profit+=Yi;
                } else {
                    x++;
                    total_profit+=Xi;
                }
            }
        }

        cout << total_profit << endl;

	}
	return 0;
}