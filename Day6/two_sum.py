class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:

        arr = []

        for i in range(len(nums)):
            diff = target - nums[i]

            if diff in arr:
                return [nums.index(diff), i]

            arr.append(nums[i])
            
        return []
