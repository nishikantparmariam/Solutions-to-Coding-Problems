def permutations(arr, i, ans):       
    if(i==len(arr)):        
        ans.append(arr.copy())
    else:  
        permutations(arr, i+1, ans)
        for j in range(i+1, len(arr)):            
            temp = arr[j]
            arr[j] = arr[i]
            arr[i] = temp            
            permutations(arr, i+1, ans)
            temp = arr[j]
            arr[j] = arr[i]
            arr[i] = temp

ans = []
arr = [i for i in range(0, 8)]
permutations(arr, 0, ans)
print(ans)
