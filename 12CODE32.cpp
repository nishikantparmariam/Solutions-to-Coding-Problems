#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll T;cin>>T;
    while(T--){
        ll N;cin>>N;
        ll M;cin>>M;
        ll arr[N];        
        ll sorted_arr[N];
        unordered_map<ll,ll> MAP;
        for(ll i=0;i<N;i++){
            cin>>arr[i]; 
            sorted_arr[i] = arr[i];           
            MAP[arr[i]] = i;
        }        

        sort(sorted_arr, sorted_arr+N);
        unordered_map<ll,ll> SORTED_MAP;
        for(ll i=0;i<N;i++){
            SORTED_MAP[sorted_arr[i]] = i;
        }

        while(M--){
            ll X;cin>>X;            
            ll low = 0;
            ll high = N-1;
            ll indexInSorted = SORTED_MAP[X];
            ll less = indexInSorted;
            ll lessNeeded = 0;
            ll more = N-indexInSorted-1;
            ll moreNeeded = 0;
            ll swapWithLow = 0;
            ll swapWithHigh = 0;            
            ll correctIndex = MAP[X];            
            while(low<=high){
                ll mid = low+(high-low)/2;
                if(arr[mid]==X) {
                    break;
                }
                else if(arr[mid] > X){
                    //go to left                     
                    if(correctIndex < mid){
                        high = mid-1;       
                        moreNeeded++;           
                    } 
                    else {
                        low = mid+1;
                        swapWithLow++;
                    }
                } else {
                    //go to right                    
                    if(correctIndex > mid){
                        low = mid+1;  
                        lessNeeded++;               
                    } 
                    else {
                        high = mid-1;
                        swapWithHigh++;
                    }
                }
            }        

            ll lessLeft = less - lessNeeded;    
            ll moreLeft = more - moreNeeded;

            if(swapWithLow > lessLeft || swapWithHigh > moreLeft){
                cout << -1 << endl;
            } else {
                cout << max(swapWithLow, swapWithHigh) << endl;
            }         
                     
        }                   
    }
    
    return 0;
}