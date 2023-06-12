
subset = [1,2,3]
n = len(subset)
op = []

for i in range(2**n):
    b = bin(i)[:1:-1]
    subs = []
    
    for i in range(len(b)):
        if b[i] == "1":
            subs.append(subset[i])
            
    op.append(subs)
    
print(op)
    
    
