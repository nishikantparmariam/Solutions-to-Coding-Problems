import sys 
input = sys.stdin.readline

def findNext(toassign, assigned):
    if toassign>10**10:
        return -1
    while toassign in assigned:
        toassign+=1
        if toassign>10**10:
            return -1
    return toassign

def main():
    for _ in range(int(input())):
        N,C = map(int,input().split())
        arr = list(map(int,input().split()))
        freq = dict()
        assigned = dict()
        for x in arr:
            if x in freq:
                freq[x]+=1
            else:
                freq[x]=1
            assigned[x] = True        
        numops = 0
        toassign = findNext(1, assigned)      
        temp = [x for x in freq]
        for x in temp:
            if freq[x]>1:                
                while toassign!=-1 and toassign<=10**10 and numops<C and freq[x]>1:
                    freq[x]-=1
                    freq[toassign] = 1
                    assigned[toassign] = True
                    numops+=1
                    toassign = findNext(toassign, assigned)                
        totalFreq = 0
        for x in freq:
            totalFreq+=freq[x]

        ans = totalFreq*(totalFreq-1)//2
        for x in freq:
            ans-=(freq[x]*(freq[x]-1))//2

        print(ans)                
        print(freq  )

if __name__ == '__main__':
    main()





