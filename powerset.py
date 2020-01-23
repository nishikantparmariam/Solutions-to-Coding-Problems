def powerset(arr):
    n = len(arr)
    powerset = []
    for i in range(0, 2**n):
        set = []
        for j in range(len(arr)):
            if(i>>j & 1):
                set.append(arr[j])
        powerset.append(set)
    return powerset


print(powerset([1,2,3,4,5,6,7]))

