#include <bits/stdc++.h>
using namespace std;

long long int bsearch(long long int A, long long int arr[], long long int start, long long int end){
    long long int mid = (start+end)/2;
    if(end-start == 0){
        if(arr[mid]==A) return mid;
        return -1;
    } else if(arr[mid])
}


int main() {
    long long int N;cin>>N;
    long long int Q;cin>>Q;
    long long int arr[N];
    for(long long int i=0;i<N;i++) cin>>arr[i];
    while(Q--){
        long long int A;cin>>A;
        long long int low = 0;
        long long int high = N-1;
        long long int ans = -1;
        while(low<=high){
            long long int mid = (low+high)/2;
            if(arr[mid]==A){
                ans = mid;
                break;
            } else if(arr[mid]<A){
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
