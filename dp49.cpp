#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int profit_dp2[107][107];

int profit2(int i, int X, int Y, int x, int N, int A[], int B[]){    
    if(i==N) return 0;    
    if(profit_dp2[i][x]!=-1) return profit_dp2[i][x];

    int toOne = x;
    int toTwo = (i+1)-x;

    if(toOne<X && toTwo<Y){
        //can go to anyone
        profit_dp2[i][x] =  max(A[i]+profit2(i+1,X,Y,x+1,N,A,B), B[i]+profit2(i+1,X,Y,x,N,A,B));
    } else if(toOne<X) {
        //can go to only X
        profit_dp2[i][x] =  max(A[i]+profit2(i+1,X,Y,x+1,N,A,B), 0);
    } else {
        //can go to only Y
        profit_dp2[i][x] =  max(0, B[i]+profit2(i+1,X,Y,x,N,A,B));
    }

    return profit_dp2[i][x];
}

int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll T;cin>>T;
	while(T--){
	    int N;int X; int Y;
        cin>>N;cin>>X;cin>>Y;
        int A[N];
        int B[N];
        for(int i=0;i<N;i++) cin>>A[i];
        for(int i=0;i<N;i++) cin>>B[i];
        

        for(int i=0;i<107;i++){
            for(int j=0;j<107;j++){                
                    profit_dp2[i][j] = -1;
                  
            }   
        } 

        cout << profit2(0,X,Y,0,N,A,B) << endl;
	}
	return 0;
}