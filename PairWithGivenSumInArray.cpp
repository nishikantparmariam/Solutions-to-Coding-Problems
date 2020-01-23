#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {10,15,3,7,-5};
    int k = 10;
    unordered_map<int, int> myMap;
    int n = sizeof(arr)/sizeof(arr[0]);
    int matches = 0;
    for(int i = 0; i<n; i++){
        auto it = myMap.find(k-arr[i]);
        if(it!=myMap.end()){
            cout << it->second << " " << i << endl;
            matches++;
        }
        myMap[arr[i]] = i;
    }
    cout << "Matches = " << matches << endl;
    return 0;
}