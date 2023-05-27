
def recurs_sub(strr, ind, newstring):
    
    #base condition
    if ind == len(strr):
        if len(newstring) > 0: 
            op.append(newstring)
        return 
    
    #letter to be included
    recurs_sub(strr, ind + 1, newstring + strr[ind])
    
    #letter not to be included
    recurs_sub(strr, ind+1, newstring)
    
ss = "abc"
op = []
recurs_sub(ss, 0, "")
print(op)
