#include <iostream>
#include <unordered_map>
using namespace std;
#include <set>

int main(){
    long long int n;
    long long int r;
    cin >> n;
    cin >> r;
    long long int arr[n];
    unordered_map<long long int, set<long long int>> myMap;
    for(long long int i = 0; i<n; i++) {
        cin >> arr[i];
        myMap[arr[i]].insert(i);
    }
    if(n<=2) {
        cout << "0" << endl;
        return 0;
    }

    cout << "Fin" << endl;
    long long int ans = 0;
    for(long long int j = 1; j<n-1; j++){        
        long long int f = arr[j]/r;
        auto itr1 = myMap.find(f);
        auto itr2 = myMap.find(arr[j]*r);
        myMap[arr[j]].erase(j);
        if(itr1!=myMap.end() && itr2!=myMap.end()){
            /*set<long long int> set_ai = itr1->second;
            set<long long int> set_ak = itr2->second; 
            long long int l1, l2;     
            auto itr3 = set_ai.lower_bound(j);
            auto itr4 = set_ak.upper_bound(j);
            l1 = distance(set_ai.begin(), itr3);
            l2 = distance(set_ak.end(), itr4);            
            ans+=l1*l2; */
            cout << ans << endl;
        }

        myMap[arr[j]].insert(j);   
    }
    cout << ans << endl;
    return 0;
}
