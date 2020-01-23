def modPower(x,y,p): 
    if x==1:
        return 1
    ans = 1  
    x = x % p;  
    while (y > 0):     
        if (y & 1): 
           ans = (ans*x) % p      
        y = y>>1
        x = (x*x) % p    
    return ans
mod = 998244353
for _ in range(int(input())):
    N,p,r = map(int,input().split())
    factorial = dict()
    factorial[0] = 1
    for i in range(1, max(p**N, r)+3):
        factorial[i]=i*factorial[i-1]
    
    ans = 0

    for i in range(0,N+1):
        p_i = pow(p,i,mod)
        if p_i>=r:
            ans+=(factorial[p_i]*modPower(factorial[r],mod-2,mod) % mod *modPower(factorial[p_i-r],mod-2,mod) % mod)%mod 
            ans%=mod
    
    print(ans%mod)

