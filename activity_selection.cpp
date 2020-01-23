#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool cmp_func(const pair<ll,pair<ll,ll>> &p1, const pair<ll,pair<ll,ll>> &p2){
    return p1.second.second < p2.second.second;
}
int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll T;cin>>T;
	while(T--){
	    long long int N;cin>>N;
	    vector<pair<ll,pair<ll,ll>>> meetings;
	    for(long long int i=0;i<N;i++){
	        long long int s_time;
	        cin>>s_time;
	        meetings.push_back(make_pair(i,make_pair(s_time, -1)));
	    }
	    
	    for(long long int i=0;i<N;i++){
	        long long int e_time;
	        cin>>e_time;
	        meetings[i].second.second = e_time;
	    }
	    
	    sort(meetings.begin(), meetings.end(), cmp_func);
        ll last_end_time = -1;
        vector<ll> meetings_ans;
        for(pair<ll,pair<ll,ll>> meeting:meetings){
            ll index  = meeting.first+1;
            ll s_time  = meeting.second.first;
            ll e_time  = meeting.second.second;
            if(s_time >= last_end_time){
                meetings_ans.push_back(index);
                last_end_time = e_time;
            } 
        }

        for(ll ans:meetings_ans){
            cout << ans << " ";
        }
        cout << endl;

	}
	
	return 0;
}