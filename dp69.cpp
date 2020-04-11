#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {3, -4, 2, -3, -1, 7, -5};
    int N = 7;
    int ps[N];
    ps[0] = arr[0];
    int ans = ps[0];
    for(int i=1;i<N;i++) {
        ps[i] = ps[i-1]+arr[i];
        ans = min(ans, ps[i]);
    }

    int maxps = ps[0];

    for(int i=1;i<N;i++){
        ans = min(ans, ps[i]-maxps);
        maxps = max(maxps, ps[i]);
    }

    cout << ans << endl;

    return 0;
}