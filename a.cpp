#include <bits/stdc++.h>

using namespace std;
int substringDiff(int k, string s1, string s2) {
    int n1 = s1.size();
    int n2 = s2.size();
    pair<int,int> dp[n1+1][n2+1];
    for(int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++){
            dp[i][j] = make_pair(0,0);
        }
    }

    //len, mismatches of far
    int ans = 0;
    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){            
            if(s1[i-1]==s2[j-1]){                
                pair<int,int> p = dp[i-1][j-1];                
                dp[i][j] = make_pair(p.first+1, p.second);                
                          
            }            
            else {
                pair<int,int> p = dp[i-1][j-1];
                if(p.second <= k-1){
                   // if(i==10 && j==10) cout << p.second << " " << p.first << "\n";
                    dp[i][j] = make_pair(p.first+1, p.second+1);                    
                } else {                    
                    int len_now = p.first;
                    if(len_now==0){
                        //if k == 0
                        if(k==0){
                            dp[i][j] = make_pair(0, 0);
                        } else {
                            dp[i][j] = make_pair(1, 1);
                        }
                    } else {
                        int back_i = i-p.first;
                        int back_j = j-p.first;
                        while(s1[back_i-1]==s2[back_j-1] && len_now>0){
                            back_j++;
                            back_i++;
                            len_now--;                            
                        }
                        if(len_now==0){
                            if(k==0){
                                dp[i][j] = make_pair(0, 0);
                            } else {
                                dp[i][j] = make_pair(1, 1);
                            }
                        } else {
                            if(k==0) dp[i][j] = make_pair(0, 0);                            
                            else dp[i][j] = make_pair(len_now, p.second);                            
                        }
                    }                   
                }
            }
           

           
            if(ans <= dp[i][j].first){
                ans = dp[i][j].first;               
            }
        }            
    }

    return ans;
    
}

int main()
{
    int t;cin>>t;
    while(t--){
        int k;cin>>k;
        string s1;string s2;
        cin>>s1;cin>>s2;
        cout << substringDiff(k,s1,s2) << endl;        
    }

    return 0;
}
