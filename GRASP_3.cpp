#include <bits/stdc++.h>
using namespace std;

bool canSolve(long long int K, long long arr[], long long int H, long long int N){
    long long int numHours = 0;
    for(long long int i=0;i<N;i++){
        numHours+=ceil(arr[i]/K);
    }
    if(numHours<=H){
        return true;
    } 
    return false;
}

int main(){
    int T;cin>>T;
    while(T--){
        long long int N;
        long long int H;
        cin>>N;cin>>H;
        long long int arr[N];
        long long int maxArr = -1;
        for(long long int i=0;i<N;i++){
            cin>>arr[i];
            maxArr = max(maxArr, arr[i]);
        }
        long long int low = 1;
        long long int high = maxArr-1;    
        long long int K=-1;  
        long long int mid;  
        while(low<=high){
            mid = (low+high)/2;
            if(!canSolve(mid+1,arr,H,N)){                                
                low = mid+1;
                K = mid+1;         
            } else {                        
                high = mid-1;
            }
        }

        cout << K+1 << endl;
    }
    return 0;
}