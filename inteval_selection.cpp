#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool cmp_func(const pair<ll,ll> &p1, const pair<ll,ll> &p2){
    return p1.second < p2.second;
}

int main(){
    ll s;cin>>s;
    while(s--){
        ll n;cin>>n;
        vector<pair<ll,ll>> intervals;
        for(ll i=0;i<n;i++){
            ll a;ll b;
            cin>>a;cin>>b;
            intervals.push_back(make_pair(a,b));
        }
        sort(intervals.begin(), intervals.end(), cmp_func);
        ll resource1_ending = -1;
        ll resource2_ending = -1;
        ll count = 0;
        for(ll i =0;i<n;i++){
            if(i==0){
                count++;
                resource1_ending = intervals[i].second;
            } else {                
                if(resource1_ending!=resource2_ending)   {
                    if(intervals[i].first >= max(resource1_ending, resource2_ending)){
                        count++;
                        if(resource1_ending < resource2_ending){
                            resource1_ending = intervals[i].second;
                        } else {
                            resource2_ending = intervals[i].second;
                        }
                    } else if(intervals[i].first < max(resource1_ending, resource2_ending) && intervals[i].first > min(resource1_ending, resource2_ending)){
                        count++;  
                        if(resource1_ending < resource2_ending){
                            resource1_ending = intervals[i].second;
                        } else {
                            resource2_ending = intervals[i].second;
                        }                      
                    }
                } else {
                    if(intervals[i].second > resource2_ending){
                        count++;                          
                        resource1_ending = intervals[i].second;
                        
                    }
                }
            }
        }
    }
    
    return 0;
}
