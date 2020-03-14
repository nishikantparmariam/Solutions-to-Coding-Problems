#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {10, 3, 5, 6, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int ans[n];

    //Without Divison - Extra Space O(n)
    int pref[n];
    int suff[n];
    suff[n-1] = arr[n-1];
    pref[0] = arr[0];
    
    for(int i = n-2;i>=0;i--){
        suff[i] = arr[i]*suff[i+1];
    }
    for(int i = 1;i<n;i++){
        pref[i] = arr[i]*pref[i-1];
    }


    for(int i=0;i<n;i++){
        if(i==0){
            ans[i] = suff[i+1];
        } else if(i==n-1){
            ans[i] = pref[i-1];
        } else {
            ans[i] = pref[i-1]*suff[i+1];
        }
        cout << ans[i] << " ";
    }

    cout << endl;

    
    //Without Divison - Extra Space O(1)
    

    int leftans = 1;
    for(int i = 0; i<n;i++){
        ans[i] = leftans;
        leftans=leftans*arr[i];
    }
    int rightans = 1;
    for(int i = n-1;i>=0;i--){
        ans[i]=ans[i]*rightans;
        rightans=rightans*arr[i];
    }

    for(int i = 0; i<n; i++){
        cout << ans[i] << " ";
    }


    return 0;
}