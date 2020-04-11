
import sys
import numpy as np 
input = sys.stdin.readline

def main():
    for _ in range(int(input())):
        n = int(input())
    arr = list(map(int, input().split()))
    Q = int(input())
    M_temp = np.arange(n*n).reshape(n,n)    
    for i in range(0,n):
        M_temp[0][i] = 1
    for i in range(1,n):
        for j in range(0,n):
            M_temp[i][j] = 0
    for j in range(1,n):
        M_temp[j][j-1] = 1
    #print(M) 
    while Q:
        x = int(input())        
        if x<=n:
            print(arr[x-1])
        else:
            res = np.arange(n).reshape(n,1)    
            for i in range(n):
                res[i][0] = arr[n-i-1]   
            M = M_temp.copy()         
            N = x-n            
            while N:
                if N%2: res = np.matmul(M,res)
                M = np.matmul(M,M)     
                N = N//2            
            print(res[0][0]//n)            
        Q-=1

if __name__ == '__main__':
    main()