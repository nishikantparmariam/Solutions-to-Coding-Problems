mod = 1000000007
def compute(i,zero_A,one_A, zero_B,one_B,N,dp_map):
    if i==N: 
        return 1
    if((zero_A==0 and one_A==0) or (zero_B==0 and one_B==0)):
        return 0

    if (zero_A, one_A, zero_B, one_B) in dp_map:        
        return dp_map[(zero_A, one_A, zero_B, one_B)]

    ans1 = 0
    a1 = 0
    a2 = 0
    if zero_A>0 and one_B>0:
        a1=compute(i+1,zero_A-1,one_A,zero_B,one_B-1,N, dp_map)%mod;                         
    if one_A>0 and zero_B>0:
        a2=compute(i+1,zero_A,one_A-1,zero_B-1,one_B,N, dp_map)%mod;            
    ans1=max(a1,a2)%mod


    ans2 = 0
    a3 = 0
    a4 = 0
    if zero_A>0 and zero_B>0:
        a3=compute(i+1,zero_A-1,one_A,zero_B-1,one_B,N, dp_map)%mod;                         
    if one_A>0 and one_B>0:
        a4=compute(i+1,zero_A,one_A-1,zero_B,one_B-1,N, dp_map)%mod;            
    ans2=max(a3,a4)%mod    


    ans = (ans1+ans2)%mod
    dp_map[(zero_A, one_A, zero_B, one_B)] = ans
    return ans
    
for _ in range(int(input())):
    N = int(input())
    A = input()
    B = input()
    zero_A = A.count("0")
    zero_B = B.count("0")
    one_A = N-zero_A
    one_B = N-zero_B
    dp_map = dict()
    ans = compute(0,zero_A,one_A, zero_B,one_B, N,dp_map)
    print(ans)