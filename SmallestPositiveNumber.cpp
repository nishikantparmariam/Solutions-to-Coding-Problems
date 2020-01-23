#include<bits/stdc++.h>
using namespace std;
int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T;cin>>T;
	while(T--){
	    int N;cin>>N;
	    int arr[N];
	    for(int i=0;i<N;i++) cin>>arr[i];
	    int i = 0;
	    while(i<N){
	        if(arr[i]<=0 || arr[i]>N){
	            arr[i] = 0;
	            i++;
	        } else {
				if(arr[i] != i+1){
					int index = arr[i]-1;
					int ele = arr[i];
					if(index+1!=arr[index]){
						int temp = arr[index];
						arr[index] = arr[i];
						if(temp<=0){
							arr[i] = 0;
							i++;
						} else {
							arr[i] = temp;
						}
					} else {
						arr[i] = 0;
						i++;
					}
				} else {
					i++;
				}	            
	        }
	    }
	    
	    int ans = -1;
	    for(int i=0;i<N;i++){
	        if(i==0 && arr[i]==0){
	            ans = 1;
	            break;
	        } else {
	            if(arr[i]==0){
	                ans = i+1;
	                break;
	            }
	        }
	    }
	    if(ans!=-1) cout << ans << endl;
	    else cout << N+1 << endl;
	}
	return 0;
}