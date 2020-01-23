for _ in range(int(input())):
    N=int(input())
    A=int(input())
    print(2*(10**N-1)+A+2,flush=True)
    B=int(input())    
    print(10**N-B,flush=True)
    D=int(input())
    print(10**N-D,flush=True)
    one=int(input())
    if one==-1:
        break