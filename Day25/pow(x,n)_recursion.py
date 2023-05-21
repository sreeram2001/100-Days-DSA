class Solution:
    def myPow(self, x: float, n: int) -> float:

        def recursive(n,x):
            
            #base conditions
            if x == 0:
                return 0

            if n==0 or x==1:
                return 1
            
            if n==1:
                return x
            
            if n == -1:
                return 1/x

            if n%2 == 0:
                return recursive(n//2,x)**2

            else:
                return recursive(n//2,x)*recursive(1+n//2,x)

        op = recursive(n,x)
        return op

            
        

        
        
