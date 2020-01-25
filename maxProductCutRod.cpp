    #include<bits/stdc++.h>
    using namespace std;

    long long int binaryToDecimal(string n) 
    { 
        string num = n; 
        long long int dec_value = 0; 
    
        // Initializing base value to 1, i.e 2^0 
        long long int base = 1; 
    
        long long int len = num.length(); 
        for (long long int i = len - 1; i >= 0; i--) { 
            if (num[i] == '1') 
                dec_value += base; 
            base = base * 2; 
        } 
    
        return dec_value; 
    } 

    bool isPowerOf(long long int val, long long int base) 
    { 
    
        // Divide given number repeatedly 
        // by base value.  
        while (val > 1) { 
            if (val % base != 0) 
                return false; // not a power  
            val /= base; 
        } 
    
        return true; 
    } 

    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int T;cin>>T;
        while(T--){
            string S;cin>>S;
            int N = S.size();
            int dp[N][N];
            for(int len=1;len<=N;len++){
                int i = 0;
                int j = i+len-1;
                while(j<N){
                    if(len<=2){
                        dp[i][j] = -1;
                    } else {
                        dp[i][j]=-1;
                        bool _is = isPowerOf(binaryToDecimal(S.substr(i,len)),5);   
                        if(_is){
                            dp[i][j]=1;
                        } else if(len>3) {
                            int minAns = INT_MAX;
                            for(int k=i+1;k<j;k++){
                                if(dp[i][k]!=-1 && dp[k+1][j]!=-1){
                                    minAns = min(minAns, dp[i][k]+dp[k+1][j]);
                                } 
                            }
                            if(minAns!=INT_MAX){
                                dp[i][j] = minAns;
                            } else {
                                dp[i][j] = -1;
                            }
                        }
                    }
                    i++;
                    j++;
                }
            }
            cout << dp[0][N-1] << endl;
        }
        return 0;
    }