# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        
        if(root == None):
            return 0
        
        count = 0
        q = []
        q.append(root)

        while(len(q) > 0):
            size = len(q)
            lvl = []
            
            for i in range(size):
                temp = q.pop(0)

                if temp.left:
                    q.append(temp.left)

                if temp.right:
                    q.append(temp.right)

            count += 1
        
        return count
