#include <bits/stdc++.h>
using namespace std;

/*
....ij......


aabacbebebe 




....*/

int find_len(vector<int> arr, int k){
    int len = 0;
    int number_dis = 0;
    for(int i=0;i<26;i++){
        len+=arr[i];
        if(arr[i]!=0){
            number_dis++;
        }
    }    
    if(number_dis == k){
        return len;
    }
    return -1;
}

int main(){
    int T;cin>>T;
    while(T--){
        string S;cin>>S;
        int k;cin>>k;
        int N = S.size();
        /*pair<vector<int>,int> dp[N][N];
        int ans = -1;
        for(int len = 1; len<=N;len++){
            int i = 0;            
            int j = i+len-1;
            while(j<N){
                if(i==j){
                    vector<int> v;
                    for(int i=0;i<26;i++){
                        v.push_back(0);
                    }
                    v[S[i]-'a'] = 1;
                    dp[i][j] = make_pair(v, find_len(v,k));
                } else if(len==2){
                    vector<int> v0 = dp[i+1][j].first;                                        
                    vector<int> v1;
                    for(int i=0;i<26;i++){
                        v1.push_back(v0[i]);
                    }
                    v1[S[i]-'a']++;
                    dp[i][j] = make_pair(v1, find_len(v1,k));
                } else {
                    vector<int> v0 = dp[i+1][j-1].first;                                        
                    vector<int> v1;
                    for(int i=0;i<26;i++){
                        v1.push_back(v0[i]);
                    }
                    v1[S[i]-'a']++;
                    v1[S[j]-'a']++;
                    dp[i][j] = make_pair(v1, find_len(v1,k));
                }       
                ans = max(ans, dp[i][j].second);                         
                i++;
                j++;
            }
        }*/
        /*for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){

                if(j>=i){
                  cout << dp[i][j].second << " ";  
                } else {
                    cout << "0 ";
                }
            }
            cout << endl;
        } */
/*
        cout << ans << endl;*/
        int left = 0;
        int right = 0;
        int k_now = 0;  
        int curr_len = 0;   
        int max_len = -1;   
        vector<int> validLengths;
        unordered_map<char,int> look_up;    
        while(right<N){ 
            bool perform = false;
            
            auto it = look_up.find(S[right]);
            if(it==look_up.end()){
                perform = true;                
            } else {                
                if((*it).second==0){
                    perform = true;
                } else {                  
                    look_up[S[right]]++;
                    curr_len++;
                }                
            }
            if(perform){
                if(k_now < k){                    
                    look_up[S[right]] = 1;
                    curr_len++;
                    k_now++;                 
                } else {                    
                    while(look_up[S[left]]>1){                                              
                        look_up[S[left]]--;
                        left++;
                        curr_len--;
                    }                                       
                    curr_len--;
                    
                    look_up[S[left]]--; 
                    left++;                   
                    look_up[S[right]] = 1;
                    curr_len++;
                }
            }           
            right++;          
           if(k_now==k){
               max_len = max(max_len, curr_len);
           }                        
        }

        cout  <<  max_len << endl;
    }
}

