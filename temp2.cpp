#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T;cin>>T;
	while(T--){
	    int N;cin>>N;
	    ll factorial[2*N+1];
	    factorial[0] = 1;
	    for(ll i=1;i<=2*N;i++){
	        factorial[i] = i*factorial[i-1];
            cout << factorial[i] << " ";
	    }
	    ll ans = ((factorial[2*N]/(factorial[N+1]))/factorial[N]);
	    cout << ans << endl;
	}
	return 0;
}