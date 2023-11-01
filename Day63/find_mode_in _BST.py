# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def findMode(self, root: Optional[TreeNode]) -> List[int]:

        dict = {}
        op = []

        def inorder(root):
            if root.left:
                inorder(root.left)

            if(root.val in dict):
                dict[root.val] += 1
            elif root.val not in dict:
                dict[root.val] = 1

            if root.right:
                inorder(root.right)

        inorder(root)
        maxi_count = max(dict.values())

        for i in dict:
            if dict[i] == maxi_count:
                op.append(i)
        
        return op


        
