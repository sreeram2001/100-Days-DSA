def reverse(strr):
    
    if len(strr) == 1:
        return strr
        
    curr = strr[0]
    nextt = reverse(strr[1:])
    return nextt+curr
    
ss = 'abc'
print(reverse(ss))
