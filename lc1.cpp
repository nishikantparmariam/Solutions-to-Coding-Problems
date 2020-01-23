#include <bits/stdc++.h> 
#include <iostream>
#include <string>
#include <tuple>
#include <unordered_map>
using namespace std;
#define mod 1000000007



#include <tuple>

long long int fact(long long int n) 
{ 
    if (n==0 || n==1) return 1;
    long long int res = 1; 
    for (int i = 2; i <= n; i++) 
        res = res * i; 
    return res; 
} 

long long int nCr(int n, int r) 
{ 
    if(n==r) return 1;
    return fact(n) / (fact(r) * fact(n - r)); 
} 
namespace std{
    namespace
    {
        template <class T>
        inline void hash_combine(std::size_t& seed, T const& v)
        {
            seed ^= hash<T>()(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }        
        template <class Tuple, size_t Index = std::tuple_size<Tuple>::value - 1>
        struct HashValueImpl
        {
          static void apply(size_t& seed, Tuple const& tuple)
          {
            HashValueImpl<Tuple, Index-1>::apply(seed, tuple);
            hash_combine(seed, get<Index>(tuple));
          }
        };

        template <class Tuple>
        struct HashValueImpl<Tuple,0>
        {
          static void apply(size_t& seed, Tuple const& tuple)
          {
            hash_combine(seed, get<0>(tuple));
          }
        };
    }
    template <typename ... TT>
    struct hash<std::tuple<TT...>> 
    {
        size_t
        operator()(std::tuple<TT...> const& tt) const
        {                                              
            size_t seed = 0;                             
            HashValueImpl<std::tuple<TT...> >::apply(seed, tt);    
            return seed;                                 
        }                                              

    };
}

long long int _max(long long int x, long long int y){
    return x>y ? x:y;
}

long long int compute(int i, int zero_A, int one_A, int zero_B, int one_B, int N, unordered_map<tuple<int,int,int,int>,long long int> &dp_map){
    if(i==N) return 1;
    if((zero_A==0 && one_A==0) || (zero_B==0 && one_B==0) ) return 0;

    auto it = dp_map.find(make_tuple(zero_A,one_A,zero_B,one_B));
    if(it!=dp_map.end()){        
        return it->second;
    }


    tuple<int,int,int,int> for_a1 = make_tuple(zero_A-1,one_A,zero_B,one_B-1);
    tuple<int,int,int,int> for_a2 = make_tuple(zero_A,one_A-1,zero_B-1,one_B);
    tuple<int,int,int,int> for_a3 = make_tuple(zero_A-1,one_A,zero_B-1,one_B);
    tuple<int,int,int,int> for_a4 = make_tuple(zero_A,one_A-1,zero_B,one_B-1);

    //for one in XOR
    long long int ans1 = 0;
    long long int a1 = 0;
    long long int a2 = 0;
    if(zero_A>0 && one_B>0){
        auto it2 = dp_map.find(for_a1);
        if(it2!=dp_map.end()){        
            a1 =  it2->second;
        } else {
            a1=compute(i+1,zero_A-1,one_A,zero_B,one_B-1,N, dp_map)%mod;                     
        }        
    }
    if(one_A>0 && zero_B>0){            

        auto it3 = dp_map.find(for_a2);
        if(it3!=dp_map.end()){        
            a2 =  it3->second;
        } else {
            a2=compute(i+1,zero_A,one_A-1,zero_B-1,one_B,N, dp_map)%mod; 
        }     
    }    
    ans1=_max(a1,a2)%mod;

    //for zero in XOR
    long long int ans2 = 0;
    long long int a3 = 0;
    long long int a4 = 0;
    if(zero_A>0 && zero_B>0){

        auto it4 = dp_map.find(for_a3);
        if(it4!=dp_map.end()){        
            a3 =  it4->second;
        } else {
            a3=compute(i+1,zero_A-1,one_A,zero_B-1,one_B,N, dp_map)%mod;                     
        }             
    }
    if(one_A>0 && one_B>0){

        auto it5 = dp_map.find(for_a4);
        if(it5!=dp_map.end()){        
            a4 =  it5->second;
        } else {
            a4=compute(i+1,zero_A,one_A-1,zero_B,one_B-1,N, dp_map)%mod;                     
        }   

        
    }
    ans2=_max(a3,a4)%mod;
    
    long long int ans = (ans1+ans2)%mod;

    dp_map.insert(make_pair(make_tuple(zero_A,one_A,zero_B,one_B), ans));        
    return ans;

}

unordered_map<tuple<int,int,int,int>,long long int> dp_map;

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        string A,B;
        cin >> A;
        cin >> B;
        int zero_A = count(A.begin(), A.end(), '0');
        int zero_B = count(B.begin(), B.end(), '0');
        int one_A = N-zero_A;
        int one_B = N-zero_B;        
        long long int ans = compute(0, zero_A, one_A, zero_B, one_B, N, dp_map);
        cout << "Prev - "  <<ans%mod << endl;


        int x = count(A.begin(), A.end(), '0');
        int a = count(B.begin(), B.end(), '0');
        int y = N-x;
        int b = N-a;
        int l1 = min(y,b)+min(x,a);
        int l2 = N-min(y,a)-min(x,b);
        int start = min(l1,l2);
        int end = max(l1,l2);
        ans = 0;
        cout << start << " " << end << endl;
        for(int r = start; r<=end; r = r+2){
            ans+=nCr(N,r)%mod;
        }

        cout << "Now - "  <<ans%mod << endl;


    }
    return 0;
}