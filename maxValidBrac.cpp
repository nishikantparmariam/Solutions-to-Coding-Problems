#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    int a = 1;
    string S;cin>>S;
    stack<ll> STACK;
    ll N = S.size();
    ll dp[N];
    ll longest = 0;
    ll numSubstrings = 0;
    for(ll i=0;i<N;i++){
        if(S[i]=='('){
            dp[i] = 0;
            STACK.push(i);
        } else {
            if(STACK.empty()){
                dp[i] = 0;
            } else {
                ll index = STACK.top();
                STACK.pop();
                dp[i] = i-index+1;
                if(index-1>=0){
                    dp[i]+=dp[index-1];
                }
            }
        }
        longest = max(longest, dp[i]);
    }    
    ll i = N-1;
    while(i>=0){
        if(dp[i]==0) i--;
        else {
            numSubstrings++;
            i-=dp[i];
        }
    }    
    if(numSubstrings==0){
        cout << 0 << " " << 1 << endl;
    } else {
        cout << longest << " " << numSubstrings << endl;
    }
    return 0;
}