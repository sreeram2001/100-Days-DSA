''' SORT A STACK '''
stack = [5,1,3,2,6]
tempstack = []
print("Unsorted Stack : ", stack)
while stack:
    popp = stack.pop()   #popped element
    
    #if temporary stack is empty
    if len(tempstack) < 1:
        tempstack.append(popp)
        
    #if temporary stack has elements
    elif tempstack:
        
        if popp >= tempstack[-1]:
            tempstack.append(popp)
        else:
            while(tempstack and popp < tempstack[-1]):
                popt = tempstack.pop()
                stack.append(popt)
            tempstack.append(popp)
            
print("Sorted Stack : ",tempstack)
            
        
        
