#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ways = 100;
    bool sieve[ways+1];
    memset(sieve, true, sizeof(sieve));
    for(int i=2;i*i<=ways;i++){
        if(sieve[i]){
            for(int j=i*i;j<=ways;j+=i){
                sieve[j] = false;
            }
        }
    }

    int ans = 0;
    for(int i=2;i<=ways;i++){
        if(sieve[i]) cout << i << " ";
    }
    return 0;
}