# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        

        if inorder:
            root = TreeNode(preorder.pop(0))
            ind = inorder.index(root.val)

            #everything to the left of root is left child
            root.left = self.buildTree(preorder, inorder[:ind])

            #everything to the right of root is right child
            root.right = self.buildTree(preorder, inorder[ind+1:])

            return root


                
