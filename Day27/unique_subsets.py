class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        op = []

        def recursi(nums, ind, arr):
            if ind == len(nums):
                if arr not in op:
                    op.append(arr)
                return
            
            #to be part
            recursi(nums, ind+1, arr + [nums[ind]])

            #not to be part
            recursi(nums, ind+1, arr)

        
        recursi(nums,0,[])
        return op
