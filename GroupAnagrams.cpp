#include<bits/stdc++.h>
using namespace std;
int myComp(const void *a, const void *b){
    return *(char*)a- *(char*)b;
}
int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T;cin>>T;
	while(T--){
	    int N;cin>>N;
	    unordered_map<string, int> MAP;
	    for(int i = 0;i<N;i++){
	        string word;cin>>word;
            int word_len = word.size();
            char *char_word = new char[word_len];
            for(int i=0;i<word_len;i++){
                char_word[i] = (char)word[i];
            }
	        qsort(char_word, word_len, sizeof(char), myComp);
            word = "";
            for(int i=0;i<word_len;i++){
                word += char_word[i];// = (char)word[i];
            }
	        MAP[word]++;
	    }
	    vector<int> ans;
	    for(auto it=MAP.begin(); it!=MAP.end(); it++){
	        ans.push_back(it->second);
	    }
	    sort(ans.begin(), ans.end());
	    for(int i =0;i<ans.size();i++){
	        cout << ans[i] << " ";
	    }
	    cout << endl;
	}
	return 0;
}