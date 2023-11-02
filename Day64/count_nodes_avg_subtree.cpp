# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfSubtree(self, root: Optional[TreeNode]) -> int:

        def calculate(root, arr):
            if root == None:
                return arr
            
            if root.left:
                calculate(root.left, arr)
            
            arr[0] = arr[0] + root.val
            arr[1] = arr[1] + 1

            if root.right:
                calculate(root.right, arr)
            
            return arr

        calc = []
        op = [0]
        def inorder(root):
            if root == None:
                return
            
            if root.left:
                inorder(root.left)

            calc = calculate(root, [0,0])

            if calc[0]//calc[1] == root.val:
                op[0] += 1

            if root.right:
                inorder(root.right)
        
        inorder(root)
        return op[0]


            
            


        
