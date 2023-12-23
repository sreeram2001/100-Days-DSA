# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
        
        nodes = []
        dict = {}

        def inorder(root):
            if root == None:
                return

            if root.left:
                inorder(root.left)
            
            nodes.append(root.val)

            if root.right:
                inorder(root.right)
        
        inorder(root)

        for i in range(len(nodes)):
            if k-nodes[i] in dict:
                return True
            dict[nodes[i]] = 1
        
        return False

