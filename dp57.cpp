/*
Describe and analyze an algorithm to find the 
length of the shortest supersequence of a given string
that is also a palindrome. For example, the shortest palindrome 
supersequence of TWENTYONE is TWENTOYOTNEWT, so given the string 
TWENTYONE as input, your algorithm should return 13.
 */

#include <bits/stdc++.h>
using namespace std;

int main(){
    string A;
    cin>>A;
    int N = A.size();
    int dp[N][N];
    for(int len=1;len<=N;len++){
        int i = 0;
        int j = i+len-1;
        while (j<N)
        {
            if(len==1) dp[i][j] = 1;
            else if(len==2){
                if(A[i]==A[j]) dp[i][j] = 2;
                else dp[i][j] = 3;
            } else {
                if(A[i]==A[j]) dp[i][j] = 2+dp[i+1][j-1];
                else dp[i][j] = 2+min(dp[i+1][j], dp[i][j-1]);
            }
            i++;
            j++;
        }
        
    }

    cout << dp[0][N-1] << endl;
    return 0;
}