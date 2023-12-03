# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:

        self.count = 0
        #using a stack to insert each and every root node
        stack = []
        stack.append(root)

        def getPath(root, currSum):
            if root == None:
                return

            currSum += root.val

            if currSum == targetSum:
                self.count += 1

            getPath(root.left, currSum)
            getPath(root.right, currSum)

        while stack:
            root = stack.pop()
            if root:
                #insert the child nodes of root into stack
                stack.append(root.left)
                stack.append(root.right)

            getPath(root, 0)

        return self.count





        
