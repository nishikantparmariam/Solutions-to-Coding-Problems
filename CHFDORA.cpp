#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        ll N;ll M;
        cin>>N;cin>>M;
        ll matrix[N][M];
        for(ll i = 0;i<N;i++){
            for(ll j=0;j<M;j++){
                cin>>matrix[i][j];
            }
        }

        ll manacher_row_wise[N][M];
        for(ll i=0;i<N;i++){
            ll r=0;
            ll c=0;
            for(ll j=0;j<M;j++){
                ll j_mirror_left = c-(j-c);
                if(j<r){
                    manacher_row_wise[i][j] = min(2*(r-j)-1, manacher_row_wise[i][j_mirror_left]);
                } else {
                    manacher_row_wise[i][j] = 1;
                }
                if(j-1-manacher_row_wise[i][j]/2 >= 0 && j+1+manacher_row_wise[i][j]/2<M){
                    while(matrix[i][j-1-manacher_row_wise[i][j]/2]==matrix[i][j+1+manacher_row_wise[i][j]/2]){
                        manacher_row_wise[i][j]+=2;
                        if(j-1-manacher_row_wise[i][j]/2 < 0 || j+1+manacher_row_wise[i][j]/2>=M){
                            break;
                        }
                    }
                }                

                if(j+manacher_row_wise[i][j]/2 > r){
                    r = j+manacher_row_wise[i][j]/2;
                    c = j;
                } 
               // cout << manacher_row_wise[i][j] << " ";
            }

           // cout << endl;
        }

       // cout << endl;

        ll manacher_column_wise[N][M];
        for(ll j=0;j<M;j++){
            ll r=0;
            ll c=0;
            for(ll i=0;i<N;i++){
                ll i_mirror_left = c-(i-c);
                if(i<r){
                    manacher_column_wise[i][j] = min(2*(r-i)-1, manacher_column_wise[i_mirror_left][j]);
                } else {
                    manacher_column_wise[i][j] = 1;
                }
                if(i-1-manacher_column_wise[i][j]/2 >= 0 && i+1+manacher_column_wise[i][j]/2<N){
                    while(matrix[i-1-manacher_column_wise[i][j]/2][j]==matrix[i+1+manacher_column_wise[i][j]/2][j]){
                        manacher_column_wise[i][j]+=2;
                        if(i-1-manacher_column_wise[i][j]/2 < 0 || i+1+manacher_column_wise[i][j]/2>=N){
                            break;
                        }
                    }
                }                

                if(i+manacher_column_wise[i][j]/2 > r){
                    r = i+manacher_column_wise[i][j]/2;
                    c = i;
                } 
                //cout << manacher_column_wise[i][j] << " ";
            }

            //cout << endl;
        }

        ll ans = 0;
        for(ll i =0;i<N;i++){
            for(ll j=0;j<M;j++){
                ans+=min(manacher_row_wise[i][j]/2+1, manacher_column_wise[i][j]/2+1);
            }
        }        
        cout << ans << endl;
    }    
    return 0;
}