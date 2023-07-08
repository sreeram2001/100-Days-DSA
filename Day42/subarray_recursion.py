class Solution:
  
    def SubArray(self, target: int, nums: List[int]) -> int:
        #to print all subarray using RECURSION
        op = []

        def recurs(nums, start, end):
            if end == len(nums):
                return

            elif start > end:
                recurs(nums, 0, end+1)

            else:
                curr = []
                for i in range(start, end+1):
                    curr.append(nums[i])
                op.append(curr)

                recurs(nums, start+1, end)

        recurs(nums, 0, 0)
        print(op)
        return 0
