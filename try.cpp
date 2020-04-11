#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> dp(5, vector<int> (5, -1));
    for(auto it=dp.begin();it!=dp.end();it++){
        for(auto it2 = (*it).begin();it2!=(*it).end();it2++){
            cout << (*it2) << " ";
        }
        cout << endl;
    }
    return 0;
}