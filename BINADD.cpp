#include <cmath>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
#define INT_MAX 1000000

string sameLength(long long int finalLength, string A);
bool check_B_positive(string B_string);

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        string A, B;
        cin >> A >> B;        
        A = '0'+A;
        B = '0'+B;
        long long int finalLength = max(A.size(), B.size());
        A = sameLength(finalLength,A);
        B = sameLength(finalLength,B);        
        long long int ans = 0;
        vector<long long int> carries;
        if(!check_B_positive(B)){
            cout << ans << endl;                        
        } else {            
            bool wasPreviousCarry = false;            
            long long int carry_current = 0;
            for(long long int i = finalLength-1; i>=0; i--){
                if(A[i]=='1' && B[i]=='1'){
                    if(wasPreviousCarry){
                        carry_current++;
                        carries.push_back(carry_current);
                        carry_current = 0;
                    }
                    carry_current++;
                    wasPreviousCarry = true;
                }
                if(A[i]=='0' && B[i]=='0'){
                    if(wasPreviousCarry){
                        carry_current++;                        
                        carries.push_back(carry_current);
                        carry_current = 0;
                    }

                    wasPreviousCarry = false;
                }
                if((A[i]=='1' && B[i]=='0') || (A[i]=='0' && B[i]=='1')){
                    if(wasPreviousCarry){
                        carry_current++;
                        wasPreviousCarry = true;
                    } else {
                        wasPreviousCarry = false;
                    }
                }
            }

            if(carries.size()==0){
                ans++;
                cout << ans << endl;
            } else {
                long long int maxi_carry_prop = -INT_MAX;
                for(long long int carry:carries){                    
                    if(carry>maxi_carry_prop){
                        maxi_carry_prop = carry;
                    }
                }
                ans=maxi_carry_prop;
                cout << ans << endl;
            }
        }        
    }
    return 0;
}

string sameLength(long long int finalLength, string A){
    long long int toPad = finalLength-A.size();
    string A_modified = "";
    while(toPad--){
        A_modified+='0';
    }
    A_modified+=A;
    return A_modified;
}


bool check_B_positive(string B_string){
    for(long long int i = 0; i<B_string.size(); ++i){
        if(B_string[i]=='1'){
            return true;
        }
    }
    return false;
}