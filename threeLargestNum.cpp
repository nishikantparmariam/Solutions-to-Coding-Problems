#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
    int partition(vector<int>& num, int s, int e){ 
                   
        int pivot = num[e];
        int i=s-1;
        int j=e+1;
        while(i<j){
            do{
                i++;
            } while(num[i]<=pivot);
            do{
                j--;
            }while(num[i]>pivot);

            if(i<j){
                int temp = num[i];
                num[i] = num[j];
                num[j] = temp;
                i++;
                j--;
            } else {
                return i-1;
            }
        }                     
    }
    int kthLargest(vector<int>& nums, int k, int s, int e){ 
        cout << "kl " << s << " " << k << " " << e << endl;
        if(s==e) return s;
        int p = partition(nums,s,e);
        int length = e-p+1;
        if(length==k){
            return p;
        } else if(length<k) {
            return kthLargest(nums,k-length,s, p-1);
        } else {
            return kthLargest(nums,k,p+1,e);
        }
        
    }

int main()
 {
     vector<int> nums = {3,2,3,1,2,4,5,5,6};
     int k = 4;
    kthLargest(nums, k, 0, nums.size()-1);
    
	return 0;
}