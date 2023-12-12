# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> Optional[TreeNode]:

        def construct(start, end, nums):
            if start > end:
                return None
            
            maxNum = 0
            ind = 0

            for i in range(start,end+1):
                if(nums[i] >= maxNum):
                    maxNum = nums[i]
                    ind = i
                
            root = TreeNode(maxNum)
            root.left = construct(start, ind-1, nums)
            root.right = construct(ind+1, end, nums)
            return root
        
        return construct(0, len(nums)-1, nums)


        



        
