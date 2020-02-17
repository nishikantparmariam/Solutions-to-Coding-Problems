#include <bits/stdc++.h>
using namespace std;

int matchRecurse(int i, int j, string &pattern, string &str, vector<vector<int>> &dp){
   // cout << i << " " << j << endl;
    if(dp[i][j]!=-1) return dp[i][j];
    int N = pattern.size();
    int M = str.size();
    if(j==M && i==N){
        dp[i][j] =  1;
    } else if(j<M && i==N){
        dp[i][j] = 0;
    } else if(j==M && i<N){
        if(i==N-1){
            if(pattern[i]=='*') dp[i][j] = 1;
            else dp[i][j] = 0;
        } else {
            dp[i][j] = 0;
        }
    }else {
        if(pattern[i]=='?'){
            dp[i][j] = matchRecurse(i+1,j+1,pattern,str,dp);
        } else if(pattern[i]!='*'){
            if(pattern[i]==str[j]){
                dp[i][j] =  matchRecurse(i+1,j+1,pattern,str,dp);
            } else {
                dp[i][j] = 0;
            }
        } else {
            int a = matchRecurse(i,j+1,pattern,str,dp);
            int b = matchRecurse(i+1,j,pattern,str,dp);
            dp[i][j] =  a | b;
        }
    }
    
    return dp[i][j];
}

string preProcess(string &pattern){
    string toReturn = "";
    for(int i=0;i<pattern.size();i++){
        if(pattern[i]=='*'){
            if(toReturn.size()==0){
                toReturn+=pattern[i];
            } else {
                if(toReturn[toReturn.size()-1]=='*'){
                    continue;
                } else {
                    toReturn+=pattern[i];
                }
            }
        } else {
            toReturn+=pattern[i];
        }
    }
    return toReturn;
}
int wildCard(string pattern,string str)
{
    pattern = preProcess(pattern);
    int N = pattern.size();
   // cout << pattern << endl;
    int M = str.size();
    vector<vector<int>> dp;
    for(int i=0;i<N+3;i++){
        vector<int> a;
        for(int j=0;j<M+3;j++){
            a.push_back(-1);
        }
        dp.push_back(a);
    }
    return matchRecurse(0,0,pattern,str,dp);
}

int main(){
    cout << wildCard("******************************","abcdef") << endl;
    return 0;
}
