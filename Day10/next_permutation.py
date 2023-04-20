class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)-1

        #in case of descending order array
        flag = 0
        for i in range(n,0,-1):
            if nums[i] <= nums[i-1]:
                flag = 1
            else:
                flag = 0
                break
        if flag == 1:
            nums.reverse()
            return

        ind = 0
        #find the element wrong order
        for i in range(n,0,-1):
            if nums[i] > nums[i-1]:
                ind = i-1
                break

        #find element closely greater than this element
        ele = nums[ind]
        swap_index = ind
        item = 10**5
        for i in range(ind,n+1):
            if nums[i] > ele and nums[i] <= item:
                item = nums[i]
                swap_index = i
        
        #now swap both these element
        nums[ind], nums[swap_index] = nums[swap_index], nums[ind]

        #reverse elements after the swapped index
        if ind+1 == n:
            return
        else:
            print(nums[:ind+1],nums[ind+1:])
            start = ind+1
            end = n
            while start < end:
                nums[start], nums[end] = nums[end], nums[start]
                start += 1
                end -= 1
