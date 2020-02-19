#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll go(ll A, ll B){
    if(A==B) return 1;
    else if(A==0 || B==0) return 0;
    else if(A>B){
        int p = floor(A/B);
        return p+go(A-B*p, B);
    } else {
        int p = floor(B/A);
        return p+go(A, B-A*p);
    }
}

int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll T;cin>>T;
	while(T--){
    
	   ll A;ll B;
	   cin>>A;cin>>B;
	   cout << go(A, B) << endl;
	}
	return 0;
}