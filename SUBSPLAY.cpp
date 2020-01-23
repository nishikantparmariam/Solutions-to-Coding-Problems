#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#define INT_MAX 100005
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        string S;
        cin >> S;
        unordered_map<char,vector<int>> freq_map;
        int minDifferece = INT_MAX;        
        int i = 0;
        for(char x:S){
            auto it = freq_map.find(x);
            if(it!=freq_map.end()){
                int le = (it->second).back();
                if(i-le < minDifferece){
                    minDifferece = i-le;                    
                }
            } else {                
            }
            //
            freq_map[x].push_back(i);
            i++;
        }
        if(minDifferece==INT_MAX){
            cout << "0" << endl;
        } else {
            cout << N-minDifferece << endl;
        }        
    }
    return 0;
}