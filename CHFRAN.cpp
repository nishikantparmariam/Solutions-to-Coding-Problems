#include <iostream>
#include <map>
#define mod 998244353
using namespace std;


long long int modPower(long long int x, long long int y, long long int p) 
{ 
    long long int ans = 1;  
    x = x % p;  
    while (y > 0) 
    {         
        if (y & 1) 
           ans = (ans*x) % p;         
        y = y>>1;
        x = (x*x) % p; 
    } 
    return ans; 
} 


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        long long int l,r;
        map<long long int, tuple<long long int,long long int,long long int>>  ranges;
        for(int i = 0; i<N; i++){
            cin >> l >> r;                        
            tuple<long long int,long long int,long long int> prev_tuple_l = ranges[l];
            tuple<long long int,long long int,long long int> prev_tuple_r = ranges[r];
            if(l==r){
                ranges[l] = make_tuple(get<0>(prev_tuple_l),get<1>(prev_tuple_l),get<2>(prev_tuple_l)+1);    
            } else {
                ranges[l] = make_tuple(get<0>(prev_tuple_l)+1,get<1>(prev_tuple_l),get<2>(prev_tuple_l));    
                ranges[r] = make_tuple(get<0>(prev_tuple_r),get<1>(prev_tuple_r)+1,get<2>(prev_tuple_r));    
            }
            
        }        

        long long int minState = INT_MAX;        
        long long int currState = 0;                       
        int i = 0;
        for(auto it = ranges.begin(); it!=ranges.end(); it++){
            
            tuple<long long int,long long int,long long int> myTuple = it->second;            

            long long int prevColong long intsions = currState+get<0>(myTuple)+get<2>(myTuple);

            currState = currState+get<0>(myTuple)-get<1>(myTuple);

            if(i<ranges.size()-1){
                tuple<long long int,long long int,long long int> myTuple2 = next(it,1)->second;    
                 long long int nextColong long intsions = currState+get<0>(myTuple2)+get<2>(myTuple2);
                 //cout << "pc = " << prevColong long intsions << "\t cs = " << currState << "\t nc = " << nextColong long intsions <<  endl;
                 if(currState<prevColong long intsions && currState<nextColong long intsions && currState<minState){

                     minState = currState;
                 }   
            }

            i++;

        }



        if(minState!=INT_MAX && minState!=N-1 && N!=1){
            cout << minState << endl;
        } else {
            cout << "-1" << endl;
        }
        
        


    }
    return 0;
}