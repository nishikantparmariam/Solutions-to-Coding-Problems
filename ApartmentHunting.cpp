#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> apartments = {
                    { 0,1,0 }, 
                    { 1,1,0 }, 
                    { 1,1,0 }, 
                    { 0,1,0 }, 
                    { 0,1,1 }};

    int ans[apartments.size()][6];

    int l_one_0 = -1;
    int l_one_1 = -1;
    int l_one_2 = -1;
    for(int i = 0;i < apartments.size(); i++){
        if(apartments[i][0]){
            l_one_0 = i;            
        }
        ans[i][0] = l_one_0;


        if(apartments[i][1]){
            l_one_1 = i;            
        }
        ans[i][2] = l_one_1;


        if(apartments[i][2]){
            l_one_2 = i;            
        }
        ans[i][4] = l_one_2;
    }

    l_one_0 = -1;
    l_one_1 = -1;
    l_one_2 = -1;

    for(int i = apartments.size()-1;i >=0; i--){
        if(apartments[i][0]){
            l_one_0 = i;            
        }
        ans[i][1] = l_one_0;


        if(apartments[i][1]){
            l_one_1 = i;            
        }
        ans[i][3] = l_one_1;


        if(apartments[i][2]){
            l_one_2 = i;            
        }
        ans[i][5] = l_one_2;
    }

    for(int i=0;i<apartments.size();i++){
        cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << " " << ans[i][3] << " " << ans[i][4] << " " << ans[i][5] << "\n";
    }

    int index = 0;
    int final_ans = INT_MAX;

    for(int i = 0;i<apartments.size();i++){
        if(ans[i][0]!=-1 && ans[i][1]!=-1){
            ans[i][0] = min(i-ans[i][0], ans[i][1]-i);
        } else if(ans[i][0]!=-1){
            ans[i][0] = i-ans[i][0];
        } else {
            ans[i][0] = ans[i][1]-i;
        }

        if(ans[i][2]!=-1 && ans[i][3]!=-1){
            ans[i][2] = min(i-ans[i][2], ans[i][3]-i);
        } else if(ans[i][2]!=-1){
            ans[i][2] = i-ans[i][2];
        } else {
            ans[i][2] = ans[i][3]-i;
        }


        if(ans[i][4]!=-1 && ans[i][5]!=-1){
            ans[i][4] = min(i-ans[i][4], ans[i][5]-i);
        } else if(ans[i][4]!=-1){
            ans[i][4] = i-ans[i][4];
        } else {
            ans[i][4] = ans[i][5]-i;
        }

        int l = max(ans[i][0], max(ans[i][2], ans[i][4]));
        if(l < final_ans){
            final_ans = l;
            index = i;
        }
    }

    cout << index << endl;

    return 0;
}