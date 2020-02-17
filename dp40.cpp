#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll T;cin>>T;
	while(T--){
	    int N;cin>>N;
	    int arr[N];
	    int max_ending_here[N];
	    int min_ending_here[N];
	    int max_starting_here[N];
	    int min_starting_here[N];
	    for(int i=0;i<N;i++){
	        cin>>arr[i];
	        max_ending_here[i] = arr[i];
	        min_ending_here[i] = arr[i];
	        max_starting_here[i] = arr[i];
	        min_starting_here[i] = arr[i];
	    } 

        if(N==1){
            cout << arr[0] << endl;
        } else if(N==2) {
            cout << abs(arr[0]-arr[1]) << endl;
        } else {
            for(int i=1;i<N;i++){
                if(max_ending_here[i-1] + arr[i] > arr[i]){
                    max_ending_here[i] = max_ending_here[i-1] + arr[i];
                }

                if(min_ending_here[i-1]+arr[i] < arr[i]){
                    min_ending_here[i] = min_ending_here[i-1]+arr[i];
                }
            }

            for(int i=N-2;i>=0;i--){
                if(max_starting_here[i+1]+arr[i] > arr[i]){
                    max_starting_here[i] = max_starting_here[i+1]+arr[i];
                }

                if(min_starting_here[i+1]+arr[i] < arr[i]){
                    min_starting_here[i] = min_starting_here[i+1]+arr[i];
                }
            }

            int ans = -INT_MAX;

            for(int i=0;i<N-1;i++){
                int l1 = max_ending_here[i];
                int l2 = min_ending_here[i];
                int r1 = max_starting_here[i+1];
                int r2 = min_starting_here[i+1];
                ans = max(ans, max(max(abs(l1-r1), abs(l1-r2)), max(abs(l2-r1), abs(l2-r2))));
            }

            cout << ans << endl;
        }	                           

	}
	return 0;
}