def productSum(arr, level):
    if hasattr(arr,"__len__"):
        ans = 0
        for x in arr:
            if hasattr(x,"__len__"):
                ans+=(level+1)*productSum(x, level+1)
            else:
                ans+=x
        return ans
    else:
        return arr

arr = [[1,2,[1,2]]]

print(productSum(arr,1))