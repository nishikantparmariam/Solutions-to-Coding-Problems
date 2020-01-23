_xormap = {('0', '1'): '1', ('1', '0'): '1', ('1', '1'): '0', ('0', '0'): '0'}
_andmap = {('0', '1'): '0', ('1', '0'): '0', ('1', '1'): '1', ('0', '0'): '0'}
def xor_op(x, y):
    return ''.join([_xormap[a, b] for a, b in zip(x, y)])
def and_op(x, y):
    A = ''.join([_andmap[a, b] for a, b in zip(x, y)])    
    return A+"0"    
def isB_pos(B):
    if B.count("0") == len(B):
        return False
    else:
        return True
def makeSameLength(U,V):
    if len(U)!=len(V):
        toPad = abs(len(U)-len(V))
        if len(U)>len(V):
            temp_V = ""
            while toPad>0:
                temp_V+="0"
                toPad-=1
            temp_V+=V
            V = temp_V
        else:
            temp_U = ""
            while toPad>0:
                temp_U+="0"
                toPad-=1
            temp_U+=U
            U = temp_U
    return U,V
for _ in range(int(input())):
    A = input()
    B = input()
    A,B = makeSameLength(A,B)    
    ans = 0
    while isB_pos(B):
        U = xor_op(A,B)
        V = and_op(A,B)
        U,V = makeSameLength(U,V)
        A = U
        B = V        
        ans = ans+1
    print(ans)