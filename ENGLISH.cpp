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
	        cout << i << "-";			
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
	    
	    cout << "\n\n\n";
	    
	    
	    for(int i = 0;i < N; i++) {
	        cout << arr[i] << " ";
	    }
	}
	return 0;
}