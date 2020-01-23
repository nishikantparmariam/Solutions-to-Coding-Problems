#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll T;cin>>T;
	while(T--){
	    ll N;cin>>N;
	    string S;cin>>S;
	    stack<ll> STACK;
	    ll count_swaps = 0;
	    for(ll i=0;i<S.size();i++){
	        if(S[i]=='['){
                STACK.push(i);
            } else {
                if(STACK.empty()){
                    count_swaps++;
                } else {
                    STACK.pop();
                }
            }
	    }
        if(count_swaps==STACK.size()){
            cout << "YES ";
        }
        cout << count_swaps << endl;        
	    
	}
	return 0;
}