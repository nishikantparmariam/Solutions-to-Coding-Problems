#include <bits/stdc++.h>
using namespace std;
    string minWindow(string s, string t) {        
        unordered_map<char, int> sign_map;        
        for(int i =0;i<t.size();i++){
            sign_map[t[i]]++;
        }
        unordered_map<char, int> curr_window_map;                
        int left = 0;
        int curr_length = 0;
        int final_start = 0;
        int min_length = INT_MAX;
        int matched = 0;
        for(int i = 0; i<s.size(); i++){
            if(sign_map[s[i]]==0){
                curr_length++;
            } else {
                if(curr_window_map[s[i]] < sign_map[s[i]]){
                    curr_window_map[s[i]]++;
                    matched++;
                    curr_length++;
                } else {
                    curr_window_map[s[i]]++;
                    curr_length++;
                }
            }
            
            
            if(matched == t.size()){
                while(sign_map[s[left]]==0 || curr_window_map[s[left]] > sign_map[s[left]]){
                    if(curr_window_map[s[left]] > sign_map[s[left]]){
                        curr_window_map[s[left]]--;
                    }
                    left++;
                    curr_length--;
                }
            }
                    
            
            if(matched == t.size()){
               // cout << s.substr(left, curr_length) << " - \n";
                if(min_length > curr_length){
                    final_start = left;
                    min_length = curr_length;
                }
            }
        }

        if(min_length==INT_MAX) return "";
        return s.substr(final_start, min_length);
    }

int main(){
    cout << minWindow("%^&*())FjfJDFDSJFJDFF%JKF94329if32^34fs6d544*&*5D4F6354454f", "&*D3()") << endl;
    cout << minWindow("ZOOMLAZAPZO", "OZA") << endl;
    return 0;
}