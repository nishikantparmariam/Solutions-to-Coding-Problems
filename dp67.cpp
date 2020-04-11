#include <bits/stdc++.h>
using namespace std;

bool go(int n, int x, int y, unordered_map<int,bool> &dp){

    if(dp.find(n)!=dp.end()) {
        return dp[n];
    }

    if(n==x || n==y || n==1) {
        dp[n] = true;
    } else {
        bool win = false;
        if(n-x>0){
            win = win | !go(n-x,x,y,dp);
        }
        if(n-y>0){
            win = win | !go(n-y,x,y,dp);
        }

        if(n-1>0){
            win = win | !go(n-1,x,y,dp);
        }
        dp[n] = win;
    }    
    return dp[n];
}


int main(){
    unordered_map<int,bool> dp;
    if(go(2,3,4,dp)){
        cout << "A won";
    } else cout << "B won";
    return 0;    
}