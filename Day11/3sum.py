class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:

        op = []
        nums.sort()

        for i in range(0,len(nums)-2):
            l = i+1
            r = len(nums)-1

            while l < r:

                if nums[i]+nums[l]+nums[r] == 0:
                    arr = [nums[i], nums[l], nums[r]]
                    if arr not in op:
                        op.append(arr)
                    l += 1
                    r -= 1

                elif nums[i]+nums[l]+nums[r] < 0:
                    l += 1

                elif nums[i] + nums[l] + nums[r] > 0:
                    r -=1

        return op





        
        
