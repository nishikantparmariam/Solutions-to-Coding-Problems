#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int convertobasex(int N, int x){
    string ans = "";
    if(N==0) return 0;
    else {
        while(N>0){
            int rem = N%x;
            ans = to_string(rem)+ans;
            N = N/x;
        }
    }

    return stoi(ans);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll T;cin>>T;	
	while(T--){                              
	    int N;cin>>N;
        cout << convertobasex(N-1, 6) << endl;
	}
    return 0;
}	


