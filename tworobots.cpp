#include <bits/stdc++.h>

using namespace std;

// Complete the redJohn function below.
int redJohn(int n) {
    int dp[n+1];


    cout << "w = ";
    for(int i=0;i<n;i++){
        if(i<=2) dp[i] = 1;
        else if(i==3) dp[i] = 2;
        else dp[i] = dp[i-1]+dp[i-4];
        /*if(i>=4) dp[i] = dp[i-1]+dp[i-4];
        else if(i==0) dp[i] = 1;
        else dp[i] = dp[i-1]; */

        cout << dp[i] << " ";
    }

    cout << endl;

    int ways = dp[n];    
    
    bool sieve[ways+1];
    memset(sieve, true, sizeof(sieve));
    for(int i=2;i*i<=ways;i++){
        if(sieve[i]){
            for(int j=i*i;j<=n;j+=i){
                sieve[j] = false;
            }
        }
    }

    int ans = 0;
    for(int i=2;i<=ways;i++){
        if(sieve[i]) ans++;
    }

    return ans;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = redJohn(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
