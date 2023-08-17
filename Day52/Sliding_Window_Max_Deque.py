class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        dq = deque()
        op = []         #to store maximum val of every window

        #adding first k elements
        for i in range(k):
            #remove all elements lesser than current
            while dq and dq[len(dq)-1] <= nums[i]:
                dq.pop()

            #we append indices into deque
            dq.append(i)

        #the index of element with maxim value is in the front of the queue
        #the lower values are to the right/rear end of the deque
        for i in range(k,len(nums)):
            
            op.append(nums[dq[0]])
            #first we remove the max elements which are not in current window from deque
            while dq and i-k >= dq[0]:
                #remove elements from front
                dq.popleft()

            #now before we insert we remove elements lesser than current element
            while dq and dq[len(dq)-1] <= nums[i]:
                dq.pop()

            dq.append(i)
        
        #element from last window
        op.append(nums[dq[0]])
        return op

        
