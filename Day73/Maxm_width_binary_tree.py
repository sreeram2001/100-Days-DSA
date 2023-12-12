# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:

        if root == None:
            return 0

        res = 1
        queue = [[root, 0]]

        while(queue):
            size = len(queue)
            start = queue[0][1]
            end = queue[len(queue)-1][1]

            res = max(res, end-start+1)

            for i in range(size):

                top = queue.pop(0)
                ind = top[1] - start

                if top[0].left:
                    queue.append( [top[0].left, 2*ind + 1] )

                if top[0].right:
                    queue.append( [top[0].right, 2*ind + 2] )

        return res



        
